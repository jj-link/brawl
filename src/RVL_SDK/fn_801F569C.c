#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern short *__cpReg;

#define A (*(int *)(__GXData->UNK_0x564 + 0x88))
#define B (*(int *)(__GXData->UNK_0x564 + 0x8c))
#define C (*(unsigned int *)(__GXData->UNK_0x564 + 0x90))
#define U8 WGPIPE.uc
#define U32 WGPIPE.ui
#define XF(v) { U8 = 0x10; U32 = 0x1006; U32 = (v); }
#define BP(v) { U8 = 0x61; U32 = (v); }
#define CP(v) { C = GX_BITSET(C, 24, 4, (v)); U8 = 8; U8 = 0x20; U32 = C; }

void fn_801F569C(unsigned int a, unsigned int b) {
    switch (A) {
    case 0: case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 9: case 10: case 34:
        XF(0);
        break;
    case 11: case 12: case 13: case 14: case 15: case 16:
    case 17: case 18: case 19: case 20: case 21: case 22:
    case 23: case 24: case 25: case 26:
        BP(0x23000000);
        break;
    case 27: case 28: case 29: case 30: case 31: case 32: case 33:
        BP(0x24000000);
        break;
    case 35: break;
    }
    switch (B) {
    case 0: case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 21:
        BP(0x67000000);
        break;
    case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        C &= ~0xf0;
        U8 = 8;
        U8 = 0x20;
        U32 = C;
        break;
    case 17: case 18: case 19: case 20:
        __cpReg[3] = 0;
        break;
    case 22: break;
    }
    A = a;
    switch (a) {
    case 0: XF(0x273); break;
    case 1: XF(0x14a); break;
    case 2: XF(0x16b); break;
    case 3: XF(0x84); break;
    case 4: XF(0xc6); break;
    case 5: XF(0x210); break;
    case 6: XF(0x252); break;
    case 7: XF(0x231); break;
    case 8: XF(0x1ad); break;
    case 9: XF(0x1ce); break;
    case 34: XF(0x21); break;
    case 10: XF(0x153); break;
    case 11: BP(0x2300ae7f); break;
    case 12: BP(0x23008e7f); break;
    case 13: BP(0x23009e7f); break;
    case 14: BP(0x23001e7f); break;
    case 15: BP(0x2300ac3f); break;
    case 16: BP(0x2300ac7f); break;
    case 17: BP(0x2300acbf); break;
    case 18: BP(0x2300acff); break;
    case 19: BP(0x2300ad3f); break;
    case 20: BP(0x2300ad7f); break;
    case 21: BP(0x2300adbf); break;
    case 22: BP(0x2300adff); break;
    case 23: BP(0x2300ae3f); break;
    case 24: BP(0x2300a27f); break;
    case 25: BP(0x2300a67f); break;
    case 26: BP(0x2300aa7f); break;
    case 27: BP(0x2402c0c6); break;
    case 28: BP(0x2402c16b); break;
    case 29: BP(0x2402c0e7); break;
    case 30: BP(0x2402c108); break;
    case 31: BP(0x2402c129); break;
    case 32: BP(0x2402c14a); break;
    case 33: BP(0x2402c1ad); break;
    case 35: break;
    }

    B = b;
    switch (b) {
    case 0: BP(0x67000042); break;
    case 1: BP(0x67000084); break;
    case 2: BP(0x67000063); break;
    case 3: BP(0x67000129); break;
    case 8: BP(0x67000252); break;
    case 21: BP(0x67000021); break;
    case 4: BP(0x6700014b); break;
    case 5: BP(0x6700018d); break;
    case 6: BP(0x670001cf); break;
    case 7: BP(0x67000211); break;
    case 9: CP(2); break;
    case 10: CP(3); break;
    case 11: CP(4); break;
    case 12: CP(5); break;
    case 13: CP(6); break;
    case 14: CP(7); break;
    case 15: CP(9); break;
    case 16: CP(8); break;
    case 17: __cpReg[3] = 2; break;
    case 18: __cpReg[3] = 3; break;
    case 19: __cpReg[3] = 4; break;
    case 20: __cpReg[3] = 5; break;
    case 22: break;
    }

    __GXData->lastWriteWasXF = 0;
}
