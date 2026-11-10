#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct TableEntry { s32 field0, field4; u32 field8; s32 fieldC, field10; };
extern struct TableEntry lbl_804169B0[];
struct Inner { s32 pad[7]; s32 state; };
struct Outer {
    s32 pad[7];
    u32 *ptr;
    u16 unk20, unk22;
    u32 unk24, unk28, unk2C;
    s32 pad2;
    struct Inner *inner;
};
extern s32 fn_803B5984(struct Outer *, u32, s32 *, u32 *);
extern s32 fn_803B89DC(struct Inner *, u16, u16);
extern s32 fn_803B932C(struct Inner *, u32, u32);
extern s32 fn_803B98C4(struct Inner *, u32, u32);

s32 fn_803B5EB8(struct Outer *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    s32 val;
    s32 spC;
    u32 sp8 = arg4;
    u32 quotient;
    u32 divisor;
    u32 count;
    u32 max;
    u32 *ptr;
    switch (arg0->inner->state) {
    case 0:
        if (arg3 > 0xfffU) val = 0x10;
        else val = fn_803B89DC(arg0->inner, (u16)arg1, (u16)arg3);
        break;
    case 1:
        if (arg3 > 0xffffU) val = 0x10;
        else val = fn_803B932C(arg0->inner, arg1, arg3);
        break;
    case 2:
        if (arg3 > 0xfffffffU) val = 0x10;
        else val = fn_803B98C4(arg0->inner, arg1, arg3);
        break;
    default:
        val = 0xf;
        break;
    }
    if (val != 0) return val;
    if ((ptr = arg0->ptr) != 0 && sp8 == 1) {
        if (arg3 == 0) {
            divisor = arg0->unk20 + 1;
            quotient = arg2 / divisor;
            if (arg0->unk28 >= quotient) {
                if (arg2 % divisor == 0) ptr[quotient] = 0;
                if (arg0->unk2C >= arg2) {
                    u32 n = arg2 - 1;
                    arg0->unk2C = n;
                    divisor = arg0->unk20 + 1;
                    arg0->unk24 = n / divisor;
                    arg0->unk22 = n % divisor;
                }
            }
        } else if (arg1 != lbl_804169B0[arg0->inner->state].field8) {
            val = fn_803B5984(arg0, arg2, &spC, &sp8);
            if (val != 0) return val;
            if (sp8 == 0) {
                count = arg0->unk24;
                max = arg0->unk28;
                if (max > count && max != 0) {
                    if (arg2 == count * (arg0->unk20 + 1)) {
                        arg0->unk22 = 0;
                        arg0->ptr[count] = arg1;
                        arg0->unk24++;
                    } else {
                        arg0->unk22++;
                    }
                    arg0->unk2C = arg2;
                }
            }
        }
    }
    return 0;
}
