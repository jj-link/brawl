/* Native Agent callbacks, not an extension notification or a provider implementation. */
export function installAdmissionGuard(agent, { authorize, wait, onFailure }) {
  const reject = error => {
    // Diagnostics cannot turn a denied request into permission.
    try { onFailure(error); } finally { agent.abort(); }
  };
  const dispose = agent.addBeforeModelCall(async (_context, signal) => {
    try {
      if (signal?.aborted) throw new Error('Native model call was aborted');
      authorize(agent.state.model, false);
      if (wait) await wait(signal);
      if (signal?.aborted) throw new Error('Native model call was aborted while held');
      authorize(agent.state.model, true);
    } catch (error) {
      reject(error);
      return { stop: true, reason: String(error) };
    }
  });
  const original = agent.getApiKey?.bind(agent);
  // AgentBeforeModelCall receives provider Context, not the model. This actual
  // model argument is authoritative even if the run captured a different model
  // before another callback changed agent.state.model during an awaited gate.
  agent.getApiKey = async model => {
    try {
      authorize(model, true);
      const key = await original?.(model);
      authorize(model, true);
      return key;
    } catch (error) {
      reject(error);
      throw error;
    }
  };
  return dispose;
}
