#include <types.h>
#pragma force_active on

typedef struct FnPkt {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
} FnPkt;

extern FnPkt* fn_8022EFF8(int);
extern void fn_80242908(void* p);

s32 fn_80246940(u32 arg0) {
    FnPkt* p = fn_8022EFF8(2);
    if (p == NULL) {
        return 0;
    }
    p->unk2 = 5;
    p->unk4 = 0;
    p->unk8 = 3;
    p->unk9 = 0x14;
    p->unkA = 2;
    p->unkB = arg0;
    p->unkC = (arg0 >> 8) & 0xff;
    fn_80242908(p);
    return 1;
}
