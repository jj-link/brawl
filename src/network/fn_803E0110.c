#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 fn_803DFDB4(void*, u32, s32*, u32*, s32);
extern s32 fn_803E2A70(void*, u16, s32*, s32);
extern s32 fn_803E2FB0(void*, s32, s32*, s32);
extern s32 fn_803E3490(void*, s32, s32*, s32);

struct TableEntry {
    s32 field0;
    s32 field4;
    u32 field8;
    s32 fieldC;
    s32 field10;
};
extern struct TableEntry lbl_8041B0E0[];

struct Inner {
    s32 pad[7];
    s32 state;
};

struct Outer {
    s32 pad[7];
    s32* ptr;
    u16 unk20;
    u16 unk22;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 pad2;
    struct Inner* inner;
};

s32 fn_803E0110(struct Outer* arg0, s32 arg1, u32 arg2, s32* arg3, u32* arg4, s32 arg5) {
    s32 result;
    s32 val;
    s32 temp;
    s32 count;
    s32 max;

    *arg3 = -1;
    if (arg0->ptr != 0 && *arg4 == 1) {
        result = fn_803DFDB4(arg0, arg2, arg3, arg4, arg5);
        if (result != 0) {
            return result;
        }
    }
    if (arg0->ptr != 0 && *arg4 != 0)
        goto exit;
    val = arg0->inner->state;
    switch (val) {
    case 0:
        result = fn_803E2A70(arg0->inner, (u16)arg1, arg3, arg5);
        break;
    case 1:
        result = fn_803E2FB0(arg0->inner, arg1, arg3, arg5);
        break;
    case 2:
        result = fn_803E3490(arg0->inner, arg1, arg3, arg5);
        break;
    default:
        result = 0xF;
        break;
    }
    if (result != 0) {
        return result;
    }
    temp = *arg3;
    if (temp == 0) {
        return 0xD;
    }
    if ((u32)(temp + 0x10000) == 0xFFFF) {
        return 6;
    }
    if (arg0->ptr != 0) {
        if ((u32)temp == lbl_8041B0E0[arg0->inner->state].field8) {
            goto exit;
        }
        count = arg0->unk24;
        max = arg0->unk28;
        if ((u32)max > (u32)count && max != 0) {
            if (arg2 == (u32)(count * (arg0->unk20 + 1))) {
                arg0->unk22 = 0;
                arg0->ptr[count] = temp;
                arg0->unk24++;
            } else {
                arg0->unk22++;
            }
            arg0->unk2C = (s32)arg2;
        }
    }
exit:
    return 0;
}