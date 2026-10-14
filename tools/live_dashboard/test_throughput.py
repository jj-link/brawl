"""Numeric/semantic regressions; run with unittest discovery from this directory."""

import json
import unittest
from dataclasses import replace
from unittest.mock import patch

import throughput as t


class ThroughputMathTests(unittest.TestCase):
    def setUp(self):
        self.tracker = t.ThroughputTracker({"providers": {"qwen": {"url": "http://localhost/metrics"}}})

    def publish(self, tokens, active, at, counters=None, source="test counter", markers=None):
        sample = t._Observation(counters or {(): tokens}, active, source, "Backend-wide generated tokens.",
                                at, "2026-10-13T00:00:00.000Z", markers or {})
        self.tracker._publish("qwen", sample)
        with patch.object(t.time, "monotonic", return_value=at):
            return self.tracker.snapshot()["providers"]["qwen"]

    def test_warming_then_output_rate_and_same_window_mean_concurrency(self):
        first = self.publish(1000, 2, 10)
        self.assertEqual(first["status"], "warming")
        self.assertIsNone(first["totalTokensPerSecond"])
        self.assertEqual(first["activeStreams"], 2)
        second = self.publish(1120, 4, 12)
        self.assertEqual(second["totalTokensPerSecond"], 60)
        self.assertEqual(second["averageTokensPerSecond"], 20)
        self.assertEqual(second["activeStreams"], 3)
        self.assertEqual(second["status"], "ok")

    def test_first_sample_deadline_does_not_warm_forever(self):
        with patch.object(t.time, "monotonic", return_value=10):
            tracker = t.ThroughputTracker({"providers": {"qwen": {"url": "http://localhost/metrics"}}})
        with patch.object(t.time, "monotonic", return_value=21):
            result = tracker.snapshot()["providers"]["qwen"]
        self.assertEqual(result["status"], "unavailable")
        self.assertIsNone(result["totalTokensPerSecond"])

    def test_idle_zero_is_measured_not_assumed_on_first_sample(self):
        self.assertIsNone(self.publish(100, 0, 10)["totalTokensPerSecond"])
        idle = self.publish(100, 0, 12)
        self.assertEqual(idle["totalTokensPerSecond"], 0)
        self.assertEqual(idle["averageTokensPerSecond"], 0)
        self.assertEqual(idle["activeStreams"], 0)

    def test_output_between_zero_gauges_has_no_average(self):
        self.publish(100, 0, 10)
        result = self.publish(140, 0, 12)
        self.assertEqual(result["totalTokensPerSecond"], 20)
        self.assertIsNone(result["averageTokensPerSecond"])

    def test_missing_denominator_does_not_hide_valid_total(self):
        self.publish(100, None, 10)
        result = self.publish(160, None, 12)
        self.assertEqual(result["totalTokensPerSecond"], 30)
        self.assertIsNone(result["averageTokensPerSecond"])
        self.assertIsNone(result["activeStreams"])

    def test_counter_reset_rebaselines(self):
        self.publish(500, 2, 10)
        reset = self.publish(20, 2, 12)
        self.assertEqual(reset["status"], "warming")
        self.assertIsNone(reset["totalTokensPerSecond"])
        self.assertEqual(self.publish(60, 2, 14)["totalTokensPerSecond"], 20)

    def test_per_series_reset_cannot_be_hidden_by_another_engine(self):
        self.publish(0, 2, 10, {("engine0",): 500, ("engine1",): 100})
        result = self.publish(0, 2, 12, {("engine0",): 20, ("engine1",): 1000})
        self.assertEqual(result["status"], "warming")
        self.assertIsNone(result["totalTokensPerSecond"])

    def test_series_replacement_and_backend_swap_rebaseline(self):
        self.publish(0, 1, 10, {("old",): 100})
        self.assertEqual(self.publish(0, 1, 12, {("new",): 200})["status"], "warming")
        self.assertEqual(self.publish(300, 1, 14, source="another backend")["status"], "warming")

    def test_process_reset_detected_even_when_counter_has_recovered(self):
        self.publish(100, 1, 10, markers={"finished": 80, "process": "1"})
        result = self.publish(200, 1, 12, markers={"finished": 180, "process": "2"})
        self.assertEqual(result["status"], "warming")

    def test_failure_discards_rates_and_next_success_is_a_baseline(self):
        self.publish(100, 1, 10)
        self.publish(200, 1, 12)
        self.tracker._failure("qwen", "Telemetry timed out.")
        with patch.object(t.time, "monotonic", return_value=13):
            failed = self.tracker.snapshot()["providers"]["qwen"]
        self.assertEqual(failed["status"], "stale")
        self.assertIsNone(failed["totalTokensPerSecond"])
        self.assertIsNone(failed["activeStreams"])
        self.assertEqual(self.publish(300, 1, 14)["status"], "warming")

    def test_expired_snapshot_is_null_and_detached(self):
        self.publish(100, 1, 10)
        self.publish(200, 1, 12)
        with patch.object(t.time, "monotonic", return_value=23):
            result = self.tracker.snapshot()
        self.assertEqual(result["providers"]["qwen"]["status"], "stale")
        self.assertIsNone(result["providers"]["qwen"]["totalTokensPerSecond"])
        result["providers"]["qwen"]["source"] = "modified by caller"
        self.assertNotEqual(self.tracker._metrics["qwen"]["source"], "modified by caller")

    def test_expired_sampling_window_rebaselines(self):
        self.publish(100, 1, 10)
        self.assertEqual(self.publish(200, 1, 21)["status"], "warming")


class BackendMetricTests(unittest.TestCase):
    def test_prometheus_label_escaping_exponents_and_timestamp(self):
        metrics = t._parse_metrics(r'vllm:generation_tokens_total{model_name="a\"b\\c\nd",engine="0"} 1.2e3 1234')
        labels, value = metrics["vllm:generation_tokens_total"][0]
        self.assertEqual(labels["model_name"], 'a"b\\c\nd')
        self.assertEqual(value, 1200)

    def test_vllm_sums_disjoint_engines_and_filters_exact_model(self):
        metrics = t._parse_metrics('''
            vllm:generation_tokens_total{model_name="m",engine="0"} 100
            vllm:generation_tokens_total{model_name="m",engine="1"} 200
            vllm:generation_tokens_total{model_name="other",engine="0"} 999
            vllm:num_requests_running{model_name="m",engine="0"} 2
            vllm:num_requests_running{model_name="m",engine="1"} 3
        ''')
        result = t._prometheus_observation(metrics, "vllm", "m")
        self.assertEqual(sum(result.counters.values()), 300)
        self.assertEqual(result.active, 5)
        self.assertIn("prefill", result.reason)

    def test_duplicate_and_aggregate_engine_mixtures_are_rejected(self):
        for text in (
            'vllm:generation_tokens_total 1\nvllm:generation_tokens_total 1',
            'vllm:generation_tokens_total{model_name="m"} 10\n'
            'vllm:generation_tokens_total{model_name="m",engine="0"} 10',
        ):
            with self.subTest(text=text), self.assertRaises(t._TelemetryError):
                t._series(t._parse_metrics(text), "vllm:generation_tokens_total", "vllm")

    def test_sglang_selects_one_tp_pp_mirror_per_dp_replica(self):
        lines = []
        for dp, tokens, active in ((0, 100, 2), (1, 200, 3)):
            for pp in range(2):
                for tp in range(2):
                    labels = f'model_name="m",engine_type="unified",dp_rank="{dp}",pp_rank="{pp}",tp_rank="{tp}",priority=""'
                    lines.append(f'sglang:realtime_tokens_total{{{labels},mode="decode"}} {tokens}')
                    lines.append(f'sglang:num_running_reqs{{{labels}}} {active}')
                    lines.append(f'sglang:realtime_tokens_total{{{labels},mode="prefill_compute"}} 99999')
        lines.append('sglang:num_running_reqs{model_name="m",engine_type="unified",dp_rank="0",pp_rank="0",tp_rank="0",priority="1"} 2')
        result = t._prometheus_observation(t._parse_metrics("\n".join(lines)), "sglang", "m")
        self.assertEqual(sum(result.counters.values()), 300)
        self.assertEqual(result.active, 5)
        self.assertEqual(len(result.counters), 2)

    def test_sglang_finished_counter_is_not_a_live_counter(self):
        metrics = t._parse_metrics("sglang:generation_tokens_total 999\nsglang:num_running_reqs 3")
        with self.assertRaises(t._TelemetryError):
            t._prometheus_observation(metrics, "sglang", None)

    def test_tensorfold_health_uses_only_output_and_decoding(self):
        sample = t._tensorfold_health({"ok": True, "backend": "tensorfold",
                                      "completion_tokens_total": 120, "prompt_tokens_total": 99999,
                                      "requests_running": 5, "streams": {"decoding": 3, "prefilling": 2}}, None)
        self.assertEqual(sum(sample.counters.values()), 120)
        self.assertEqual(sample.active, 3)
        missing = t._tensorfold_health({"ok": True, "backend": "tensorfold",
                                       "completion_tokens_total": 120, "requests_running": 5}, None)
        self.assertIsNone(missing.active)

    def test_tensorfold_metrics_fall_back_to_live_health_not_finished_counter(self):
        health = {"ok": True, "backend": "tensorfold", "completion_tokens_total": 123,
                  "streams": {"decoding": 2}}
        with patch.object(t, "_fetch", side_effect=[("tensorfold:generation_tokens_total 999", None),
                                                   (json.dumps(health), None)]) as fetch:
            result = t._sample_provider({"url": "http://host/prefix/metrics", "backend": "auto"}, 2)
        self.assertEqual(sum(result.counters.values()), 123)
        self.assertEqual(result.active, 2)
        self.assertEqual(fetch.call_args_list[1].args[0], "http://host/prefix/health")

    def test_tensorfold_without_metrics_can_auto_detect_health(self):
        health = {"ok": True, "backend": "tensorfold", "completion_tokens_total": 123}
        with patch.object(t, "_fetch", side_effect=[t._TelemetryError("Not found.", http_status=404),
                                                   (json.dumps(health), None)]):
            result = t._sample_provider({"url": "http://host/metrics", "backend": "auto"}, 2)
        self.assertEqual(sum(result.counters.values()), 123)
        self.assertIsNone(result.active)

    def test_tensorfold_live_metrics_exclude_other_stream_states(self):
        metrics = t._parse_metrics('''
            tensorfold_health:completion_tokens_total 123
            tensorfold_health:streams{state="decoding"} 3
            tensorfold_health:streams{state="filling"} 2
            tensorfold_health:streams{state="paused"} 1
        ''')
        result = t._prometheus_observation(metrics, "tensorfold", None)
        self.assertEqual(sum(result.counters.values()), 123)
        self.assertEqual(result.active, 3)

    def test_tensorfold_rank_mirrors_cannot_double_count_global_output(self):
        metrics = t._parse_metrics(
            'tensorfold_health:completion_tokens_total{rank="0"} 100\n'
            'tensorfold_health:completion_tokens_total{rank="1"} 100'
        )
        with self.assertRaises(t._TelemetryError):
            t._prometheus_observation(metrics, "tensorfold", None)

    def test_invalid_selected_counter_values_never_become_rates(self):
        for value in ("NaN", "+Inf", "-1", "0.5"):
            with self.subTest(value=value), self.assertRaises(t._TelemetryError):
                t._series(t._parse_metrics(f"vllm:generation_tokens_total {value}"),
                          "vllm:generation_tokens_total", "vllm")


class LlamaLiveMetricTests(unittest.TestCase):
    def sample(self, finished, slots, after=None):
        text = f"llamacpp:tokens_predicted_total {finished}"
        following = f"llamacpp:tokens_predicted_total {finished if after is None else after}"
        with patch.object(t, "_fetch", side_effect=[(json.dumps(slots), None), (following, "1")]):
            return t._llama_observation("http://host/metrics", t._parse_metrics(text), "1", None, 2)

    @staticmethod
    def slot(slot_id, decoded, processing=True):
        return {"id": slot_id, "is_processing": processing, "n_prompt_tokens_processed": 50,
                "next_token": [{"n_decoded": decoded}]}

    def test_coherent_finished_plus_live_counter_and_decode_denominator(self):
        result = self.sample(100, [self.slot(0, 20), self.slot(1, 10), self.slot(2, 0),
                                   self.slot(3, 80, False)])
        self.assertEqual(sum(result.counters.values()), 130)
        self.assertEqual(result.active, 2)

    def test_request_completion_is_neither_lost_nor_double_counted(self):
        first = replace(self.sample(100, [self.slot(0, 20), self.slot(1, 10)]), at=10)
        # Request 0 finishes with 50 output tokens. Its former 20 live tokens
        # now reside in the finished counter; request 1 has advanced by 10.
        second = replace(self.sample(150, [self.slot(0, 0, False), self.slot(1, 20)]), at=12)
        tracker = t.ThroughputTracker({})
        tracker._publish("other", first)
        tracker._publish("other", second)
        with patch.object(t.time, "monotonic", return_value=12):
            result = tracker.snapshot()["providers"]["other"]
        self.assertEqual(result["totalTokensPerSecond"], 20)
        self.assertAlmostEqual(result["averageTokensPerSecond"], 20 / 1.5)

    def test_completion_during_bracket_is_not_a_plausible_fake_sample(self):
        with self.assertRaises(t._TelemetryError) as raised:
            self.sample(100, [self.slot(0, 20)], after=150)
        self.assertEqual(raised.exception.status, "warming")

    def test_legacy_slots_are_not_combined_with_stale_previous_request_tokens(self):
        slots = [{"id": 0, "is_processing": True, "next_token": {"n_decoded": 100}}]
        with self.assertRaises(t._TelemetryError):
            self.sample(100, slots)


class ThroughputConfigTests(unittest.TestCase):
    def test_missing_file_disables_all_providers(self):
        with patch.object(t.Path, "open", side_effect=FileNotFoundError):
            config = t.load_config("missing.json")
        tracker = t.ThroughputTracker(config)
        self.assertTrue(all(metric["status"] == "unavailable" for metric in tracker.snapshot()["providers"].values()))

    def test_urls_and_auth_are_not_echoed_in_validation_or_snapshot(self):
        secret_url = "http://user:secret@host/metrics"
        with self.assertRaises(ValueError) as raised:
            t.ThroughputTracker({"providers": {"qwen": {"url": secret_url}}})
        self.assertNotIn("secret", str(raised.exception))
        tracker = t.ThroughputTracker({"providers": {"qwen": {"url": "http://host/metrics?key=secret"}}})
        self.assertNotIn("secret", json.dumps(tracker.snapshot()))

    def test_configuration_is_detached_and_unknown_fields_fail(self):
        config = {"providers": {"qwen": {"url": "http://host/metrics"}}}
        tracker = t.ThroughputTracker(config)
        config["providers"]["qwen"]["url"] = "http://changed/metrics"
        self.assertEqual(tracker.config["providers"]["qwen"]["url"], "http://host/metrics")
        with self.assertRaises(ValueError):
            t.ThroughputTracker({"providers": {"qwen": {"url": "http://host/metrics", "backned": "vllm"}}})


if __name__ == "__main__":
    unittest.main()
