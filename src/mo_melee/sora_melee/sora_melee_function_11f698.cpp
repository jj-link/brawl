#include <types.h>
#pragma force_active on
struct Entry { s32 a; s32 b; s32 c; char pad[0x24]; };
extern "C" {
s32 fn_27_1444C4(s32, s32, s32, s32, s32, u8, s32, s32, s32);
extern s32 lbl_27_bss_31F8;
void fn_27_11F698(u8* self, s32 a1, s32 a2, void* a3, s32 a4) {
    u8 i;
    s32 res;
    s32 off;
    u8* slot;
    s32 mask;
    s32 t;
    for (i = 0; i < 8; i++) {
        off = i * 0x30;
        slot = self + off;
        if (a2 == *(s32*)(slot + 0x330) && a1 == *(s32*)(slot + 0x338)) {
            if (self[0x15F] != 1) {
                res = 0;
                mask = ~*(s32*)(slot + 0x334) & 0xE00;
                if (mask != 0) {
                    t = mask & 0x600;
                    if (t != 0) {
                        res = fn_27_1444C4(lbl_27_bss_31F8, a2, *(s32*)(self + 0x174), *(s32*)(self + 0x174), t, self[0x15B], (s32)a3 + 0x20, *(s32*)(self + 0x168), 0);
                    }
                    if (mask & 0x800) {
                        res |= fn_27_1444C4(lbl_27_bss_31F8, a2, *(s32*)(self + 0x174), a1, 0x800, self[0x15B], *(s32*)(self + a4 * 0x14 + 0x490), *(s32*)(self + 0x168), 1);
                    }
                    (*(Entry*)(self + 0x330 + off)).b |= res;
                }
            } else {
                res = 0;
            }

            if (res != 0) {
                *(s32*)(self + 4) = 1;
                return;
            }
            if ((*(Entry*)(self + 0x330 + off)).c == -1) {
                *(s32*)(slot + 0x338) = a1;
            }
            return;
        }
    }
    for (i = 0; i < 8; i++) {
        u8* slot;
        s32 off;
        s32 res;
        off = i * 0x30;
        slot = self + off;
        if (*(s32*)(slot + 0x338) == -1) {
            if (self[0x15F] != 1) {
                res = 0;
                mask = ~*(s32*)(slot + 0x334) & 0xE00;
                if (mask != 0) {
                    t = mask & 0x600;
                    if (t != 0) {
                        res = fn_27_1444C4(lbl_27_bss_31F8, a2, *(s32*)(self + 0x174), *(s32*)(self + 0x174), t, self[0x15B], (s32)a3 + 0x20, *(s32*)(self + 0x168), 0);
                    }
                    if (mask & 0x800) {
                        res |= fn_27_1444C4(lbl_27_bss_31F8, a2, *(s32*)(self + 0x174), a1, 0x800, self[0x15B], *(s32*)(self + a4 * 0x14 + 0x490), *(s32*)(self + 0x168), 1);
                    }
                    (*(Entry*)(self + 0x330 + off)).b |= res;
                }
            } else {
                res = 0;
            }

            if (res != 0) {
                (*(Entry*)(self + 0x330 + off)).a = a2;
                *(s32*)(slot + 0x338) = a1;
                *(s32*)(self + 4) = 1;
            }
            return;
        }
    }
}
}