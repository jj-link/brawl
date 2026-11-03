#pragma force_active on
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef unsigned char u8;

struct InnerObj;

struct Obj1 {
    u8 pad00[0x19D0];
    struct InnerObj* unk19D0;
};

struct Obj0 {
    u8 pad00[4];
    u8 unk04;
    u8 pad05[3];
    s32 unk08;
    u8 pad0C[0x10];
    u8 unk1C;
    u8 unk1D;
};

struct InnerObj {
    u8 pad00[8];
    s32 unk08;
    u8 pad0C[0x20];
    u8 unk2C;
    u8 unk2D;
    u8 pad2E[0x68E];
    u16 unk6BC;
    u8 pad6BE[0x16];
    s32 unk6D4;
    s32 unk6D8;
    s32 unk6DC;
};

extern s32 fn_80261244(void* arg0, s32 arg1, s32 arg2);

s32 fn_80265310(struct Obj0* arg0, struct Obj1* arg1, s32 arg2, s32 arg3) {
    struct InnerObj* inner;
    s32 val6D4;
    s32 computed;
    s32 r5_val;
    s32 result;

    inner = arg1->unk19D0;
    val6D4 = inner->unk6D4;
    if (val6D4 == 0) {
        return -0xA0;
    }
    if (inner->unk6D8 == 0) {
        return -0xA0;
    }
    if (inner->unk6BC != 6) {
        return -0xA0;
    }
    computed = inner->unk6DC - arg3 + (inner->unk6D8 + val6D4);
    if ((u32)computed > (u32)arg0->unk08) {
        return -0xA0;
    }
    r5_val = inner->unk6D8 - (computed - arg2);
    if ((u32)computed <= (u32)arg2) {
        r5_val = inner->unk6D8;
    }
    if (arg0->unk1C != 1) {
        return -1;
    }
    if (arg0->unk04 != 4 && arg0->unk04 != 6) {
        return -4;
    }
    if (arg0->unk1D != 1) {
        return -1;
    }
    inner->unk2D = 0;
    inner->unk2C = arg0->unk1D;
    inner->unk08 = (s32)arg0->unk04;
    result = fn_80261244(arg1, inner->unk6DC + inner->unk6D4, r5_val);
    return result & (result >> 31);
}