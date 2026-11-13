#include <types.h>
#pragma force_active on

struct Ent {
    u8 pad[0x19];
    u8 f19;
    u8 f1a;
    u8 pad2;
    u8 f1c;
    u8 f1d;
    u8 pad3[0x40 - 0x1e];
};

static inline bool isA(u8 y, u8 x, u8 z) {
    if (x == 6) return false;
    if (y == 3) {
        switch ((s32)x) {
        case 4:
        case 5:
            return true;
        case 2:
        case 3:
            if (z == 0) return true;
            break;
        }
        return false;
    }
    return true;
}

static inline bool isB(s32 y, s32 x, s32 z) {
    switch (y) {
    case 0:
        return true;
    case 1:
        switch (x) {
        case 2:
        case 3:
        case 4:
        case 5:
            if (z == 0) return false;
            break;
        }
        return true;
    case 2:
    case 3:
        return false;
    }
    return true;
}

extern "C" {
void fn_48_A4E0(s32 n, Ent *e, s32 *cntA, s32 *cntB, s16 *outA, s16 *outB) {
    s32 a = 0;
    s32 b = 0;
    s16 i = 0;
    for (s32 k = 0; k < n; k++, i++, e++) {
        if ((e->f19 & 3) == 1) {
            u8 x = e->f1c;
            u8 y = e->f1a;
            u8 z = e->f1d;
            if (isA(y, x, z)) {
                if (isB(y, x, z)) {
                    *outA++ = i;
                    a++;
                } else {
                    *outB++ = i;
                    b++;
                }
            }
        }
    }
    *cntA = a;
    *cntB = b;
}
}
