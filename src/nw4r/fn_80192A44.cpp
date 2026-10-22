#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef signed char s8;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
    u16 unk1C;
    u16 unk1E;
    s32 unk20;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
};

extern "C" s32 fn_80192A44(Obj **arg0, Obj **arg1, u16 *arg2, u16 *arg3, s32 *arg4, f32 *arg5, f32 *arg6, s8 *arg7) {
    Obj *p = *arg0;
    if (p->unk18 & 1) {
        return 0;
    }
    if (arg1 != 0) {
        s32 off = p->unk10;
        u32 result;
        if (off != 0) {
            result = (u32)p + off;
        } else {
            result = 0;
        }
        *arg1 = (Obj *)result;
    }
    if (arg2 != 0) {
        *arg2 = (*arg0)->unk1C;
    }
    if (arg3 != 0) {
        *arg3 = (*arg0)->unk1E;
    }
    if (arg4 != 0) {
        *arg4 = p->unk20;
    }
    if (arg5 != 0) {
        *arg5 = p->unk28;
    }
    if (arg6 != 0) {
        *arg6 = p->unk2C;
    }
    if (arg7 != 0) {
        u32 val = (u32)p->unk24;
        u32 lz = __cntlzw(val ^ 1);
        *arg7 = (s8)(val << lz >> 31);
    }
    return 1;
}
