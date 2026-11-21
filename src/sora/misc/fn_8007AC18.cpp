#include <types.h>
#pragma force_active on

struct Entry {
    s32 state;
    u8 pad[12];
    u8 active;
    u8 pad2[3];
};

extern "C" s32 fn_8007AC18(Entry* arg0) {
    Entry* p;
    s32 result;
    s32 state = 3;
    s32 i;
    s32 hit;
    for (;;) {
        result = state;
        p = arg0;
        for (i = 0; i < 30; p++, i++) {
            hit = 0;
            if (p->active != 0 && p->state == state) {
                hit = 1;
            }
            if (hit != 0) {
                result = 0x1C;
                break;
            }
        }
        if (result == 0x1C) {
            state++;
            if ((u32)state <= 6) {
                continue;
            }
        }
        break;
    }
    return result;
}
