#pragma force_active on
#include <types.h>

struct Args {
    s32 a00;
    void* p04;
    void* p08;
    void* p0C;
    void* p10;
    s32 a14;
    s32 a18;
    void* p1C;
    s32 a20;
    s32 a24;
    s32 a28;
    u8 b2C;
    void* p30;
    void* p34;
    void* p38;
    void* p3C;
    s32 a40;
    void* p44;
    s32 a48;
    u8 b4C;
};

extern "C" void fn_11_0(Args* a);
extern "C" void* fn_800B03F0(void* resource, int id);
extern "C" void* fn_80015DB4(void* resource, int a, int b, int c, u16 d);
extern "C" void* g_GameGlobal;
extern "C" u8 lbl_1_rodata_708[0x8];

extern "C" void fn_1_DB54(void* arg0, s32 arg1) {
    u8* self = (u8*)arg0;
    s32 var_r9;
    int var_r31;
    u8* st;
    s32 temp_r0;
    u8 temp_r8;
    Args args;

    args.a00 = 0;
    args.p04 = 0;
    args.p08 = 0;
    args.p0C = 0;
    args.p10 = 0;
    args.a14 = 0;
    args.a18 = 1;
    args.p1C = 0;
    args.a20 = -1;
    args.a24 = 0xF0;
    args.a28 = 0;
    args.b2C = 1;
    args.p30 = 0;
    args.p34 = 0;
    args.p38 = 0;
    args.p3C = 0;
    args.a40 = 0;
    args.p44 = 0;
    args.a48 = 0;
    args.b4C = 0;

    var_r9 = 0;
    st = *(u8**)((u8*)g_GameGlobal + 0x10);
    temp_r0 = st[4];
    if ((temp_r0 >= 0xC) && (temp_r0 < 0x13)) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    if (arg1) {
        *(void**)(self + 0x38C) = fn_800B03F0(*(void**)(self + 0x450), 0x14);
        *(void**)(self + 0x390) = fn_800B03F0(*(void**)(self + 0x450), 0x50);
        *(void**)(self + 0x394) = fn_800B03F0(*(void**)(self + 0x450), 0x28);
        *(void**)(self + 0x398) = fn_800B03F0(*(void**)(self + 0x450), 0x1E);
        *(void**)(self + 0x39C) = fn_800B03F0(*(void**)(self + 0x450), 0x32);
        *(void**)(self + 0x3A0) = fn_800B03F0(*(void**)(self + 0x450), 0x5A);
        *(void**)(self + 0x3A4) = fn_80015DB4(*(void**)(self + 0x450), 0, 1, 0x46, (u16)0xFFFE);
        *(void**)(self + 0x3A8) = fn_80015DB4(*(void**)(self + 0x450), 0, 1, 0x3C, (u16)0xFFFE);
        var_r9 = *(s32*)(*(u8**)(self + 0x364) + 0x48);
    }

    temp_r8 = ((u8 (*)[2])lbl_1_rodata_708)[*(int*)(self + 0x444)][var_r31];
    args.a14 = var_r9;
    args.a00 = temp_r8;
    args.a18 = 1;
    args.p1C = self + 0x390;
    args.p30 = self + 0x38C;
    args.p34 = self + 0x394;
    args.p38 = self + 0x398;
    args.p3C = self + 0x39C;
    args.a28 = *(s32*)(self + 0x3A8);
    args.b2C = self[0x448];
    if (var_r31 != 0) {
        args.a40 = *(s32*)(self + 0x3A4);
        args.p44 = self + 0x3A0;
        args.a48 = 0x4B0;
        args.b4C = (st[6] != 0);
    }
    args.p04 = self + 0x3B0;
    args.p08 = self + 0x3B8;
    args.p10 = self + 0x438;
    args.p0C = self + 0x440;
    args.a20 = *(s32*)(self + 0x35C);
    args.a24 = *(s32*)(self + 0x360);
    fn_11_0(&args);
}
