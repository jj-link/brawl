#include <ip/ip_network_producer.h>
#include <nt/network.h>
#include <sr/sr_common.h>
#include <types.h>

ipNetworkProducer* g_ipNetworkProducer;

static inline void initializeProducer(ipNetworkProducer* producer) {
    void (*setCallback)(NtShared::ntConsumedDataCallback_t) = NtShared::ntSetConsumedDataCallback;
    setCallback(reinterpret_cast<NtShared::ntConsumedDataCallback_t>(ipNetworkProducer::networkInCallback));
    producer->clear();
}

ipNetworkProducer* ipNetworkProducer::getInstance() {
    if (!g_ipNetworkProducer) {
        ipNetworkProducer* producer = new (Heaps::SystemFW) ipNetworkProducer;
        if (producer) {
            initializeProducer(producer);
        }
        g_ipNetworkProducer = producer;
    }
    return g_ipNetworkProducer;
}

void ipNetworkProducer::networkInCallback(const u16* input) {
    if (!g_ipNetworkProducer) {
        ipNetworkProducer* producer = new (Heaps::SystemFW) ipNetworkProducer;
        if (producer) {
            NtShared::ntSetConsumedDataCallback(
                reinterpret_cast<NtShared::ntConsumedDataCallback_t>(networkInCallback));
            producer->clear();
        }
        g_ipNetworkProducer = producer;
    }
    g_ipNetworkProducer->push(input);
}

UnkIpNetworkMsg* ipNetworkProducer::front() {
    return &unk2 + unk1[0];
}

void ipNetworkProducer::pop() {
    unk0--;
}

void ipNetworkProducer::clear() {
    unk0 = 0;
    unk1[0] = 0xFF;
}
