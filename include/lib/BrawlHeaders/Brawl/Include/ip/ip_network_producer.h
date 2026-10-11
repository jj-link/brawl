#pragma once

#include <nt/network.h>
#include <types.h>

// TODO
struct UnkIpNetworkMsg {
    u16 unk0[8];
};

// This class has a 2-byte header followed by some record, likely encoding
// controller inputs
// byte 0: size
// byte 1: "front" index
// TODO: relationship to ipPadStatus and/or ipPadButton?
class ipNetworkProducer {
    u8 unk0;
    u8 unk1[1];
    UnkIpNetworkMsg unk2;

    void push(const u16* input) {
        u8 slot = 0;
        if (unk0) {
            slot = unk1[unk0 - 1] + 1;
        }
        if (slot >= 1) {
            slot = 0;
        }
        unk1[unk0] = slot;
        UnkIpNetworkMsg* message = &unk2 + slot;
        for (s32 i = 0; i < 8; i++) {
            message->unk0[i] = input[i];
        }
        unk0++;
    }

public:
    static ipNetworkProducer* getInstance();
    static void networkInCallback(const u16*);
    UnkIpNetworkMsg* front();
    void pop();
    void clear();
};
// TODO size
