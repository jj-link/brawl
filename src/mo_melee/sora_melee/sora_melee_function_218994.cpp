#pragma force_active on
#include <types.h>
extern "C" s32 fn_27_218BA8(void*, void*, s32, s8);
extern "C" u32* fn_27_219188(void*);
struct Rec { u32 key; s32 count; u32* ptr; u32 pad; };
extern "C" void fn_27_218994(void* a0, Rec* recs, s32 n, u8* flags, s32 arg4, void* arg5, s8 arg6) {
    s32 i;
    u32* p;
    for (i = 0; i < n; i++) flags[i] = 0;
    if (fn_27_218BA8(a0, arg5, 0, arg6) > 0) {
        for (;;) {
            p = fn_27_219188(a0);
            if (p == 0) break;
            for (i = 0; i < n; i++) {
                if (recs[i].ptr != 0 && *p == recs[i].key) {
                    recs[i].ptr = p;
                    if (recs[i].count > 0) recs[i].count--;
                    flags[i] = 1;
                    break;
                }
            }
            if (i >= n) {
                for (i = 0; i < n; i++) {
                    if (recs[i].ptr == 0) {
                        recs[i].key = *p;
                        recs[i].count = arg4;
                        recs[i].ptr = p;
                        if (arg4 > 0) recs[i].count = arg4 - 1;
                        flags[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (flags[i] == 0 && recs[i].ptr != 0) recs[i].ptr = 0;
    }
}