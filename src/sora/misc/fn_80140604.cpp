#include <types.h>
#include <nt/nt_send.h>
#pragma force_active on

extern "C" {
void fn_8013E470(void* self, u16 a, s32 b);
void fn_8013FDD4(void* self);
void fn_80146F88(u8 a, s32 b);
void netReport__FPCce(const char*, ...);
}

struct Mgr {
    char pad0[0x50];
    s32 unk50;
    s32 unk54;
    char pad58[0xA8 - 0x58];
    s32 unkA8;
    char padAC[0x144 - 0xAC];
    u16 unk144;
    u16 unk146;
    char pad148[0x178 - 0x148];
    u8* unk178;
    char pad17C[0x194 - 0x17C];
    u32 unk194;
    char pad198[0x204 - 0x198];
    f32 unk204;
};

struct Arg {
    char pad0[4];
    u8 unk4;
    u8 unk5;
    char pad6[4];
    u8 unkA[4];
    u8 unkE;
    char padF[5];
    f32 unk14;
};

struct Pair {
    u8 a;
    u8 b;
};

extern Mgr* lbl_805A0390;
extern NtSend* lbl_805A03D4;
extern u8 lbl_805A0409;
extern u8 lbl_8059E742;
extern Pair lbl_805A0418[4];
extern char lbl_8045E1D0[];

extern "C" u32 fn_80140604(u8 arg0, u32 arg1, Arg* arg2) {
    u32 i;
    u32 temp_r3;
    u32 temp_r7;
    u8 t;
    u8* buf;

    if (arg1 < 0x18) {
        netReport__FPCce(lbl_8045E1D0);
        return arg1;
    }
    if (lbl_805A0390->unkA8 != 4) {
        lbl_805A0390->unkA8 = 4;
        fn_8013FDD4(lbl_805A0390);
        fn_8013E470(lbl_805A0390, (u16)(arg2->unk5 + (arg2->unk4 << 8)), 1);
        lbl_805A0390->unk146 = lbl_805A0390->unk144;
        i = 0;
        do {
            fn_80146F88((u8)i, arg2->unkA[(u8)i]);
            i++;
        } while (i < 4);
        lbl_805A0390->unk50 = lbl_805A0390->unk54 * lbl_805A0418[lbl_8059E742].b;
        lbl_805A0409 = arg2->unkE;
        lbl_805A0390->unk204 = arg2->unk14;
    }
    buf = lbl_805A0390->unk178;
    buf[0] = 8;
    buf[1] = 0xF8;
    t = buf[2] & 0xFC;
    buf[3] = 0x18;
    buf[2] = (u8)((t & 3) | 4);
    temp_r3 = arg2->unk5 + (arg2->unk4 << 8);
    buf[4] = (u8)(temp_r3 >> 8);
    buf[5] = (u8)temp_r3;
    temp_r7 = lbl_805A0390->unk194;
    buf[6] = (u8)(temp_r7 >> 24);
    buf[7] = (u8)(temp_r7 >> 16);
    buf[8] = (u8)(temp_r7 >> 8);
    buf[9] = (u8)temp_r7;
    lbl_805A03D4->pushback(arg0, buf, 0x18);
    return 0x18;
}
