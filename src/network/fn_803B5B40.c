#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    char pad_00[0x1C];
    s32 *array_1C;
    u16 count_20;
    char pad_22[2];
    s32 flag_24;
    char pad_28[4];
    u32 size_2C;
    char pad_30[4];
    void *sub_34;
} Foo;

typedef struct {
    char pad_00[0x1C];
    s32 field_1C;
} Sub;

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 c;
    u32 unk_0C;
    u32 unk_10;
} Ent;

extern s32 fn_803B8708(Sub *, u16, s32 *, s32 *);
extern s32 fn_803B9170(Sub *, s32, s32 *, s32 *);
extern s32 fn_803B96F8(Sub *, s32, s32 *, s32 *);
extern Ent lbl_804169B0[];

s32 fn_803B5B40(Foo *arg0, u32 arg1, s32 *arg2, s32 *arg3, s32 arg4) {
    s32 spC = -1;
    s32 sp8 = arg4;
    u32 divisor;
    u32 quotient;
    s32 rem;
    s32 val;
    s32 result;
    Sub *sub;

    *arg3 = 0;

    if (arg0->flag_24 == 0) {
        return 0;
    }

    if (arg0->size_2C >= arg1) {
        divisor = arg0->count_20 + 1;
        quotient = arg1 / divisor;
        rem = arg1 % divisor;

        if (rem == 0) {
            *arg2 = arg0->array_1C[quotient];
            *arg3 = 1;
            goto done;
        }

        val = arg0->array_1C[quotient];
        while (rem != 0) {
            switch (((Sub *)arg0->sub_34)->field_1C) {
            case 0:
                result = fn_803B8708((Sub *)arg0->sub_34, (u16)val, &spC, &sp8);
                break;
            case 1:
                result = fn_803B9170((Sub *)arg0->sub_34, val, &spC, &sp8);
                break;
            case 2:
                result = fn_803B96F8((Sub *)arg0->sub_34, val, &spC, &sp8);
                break;
            default:
                result = 0xF;
                break;
            }

            if (result != 0) {
                return result;
            }
            if (spC == 0) {
                return 0xD;
            }

            val = spC;
            rem--;
        }

        if (spC == 0) {
            return 0xD;
        }
        sub = (Sub *)arg0->sub_34;
        if ((u32)spC == lbl_804169B0[sub->field_1C].c) {
            return 0;
        }

        *arg2 = spC;
        *arg3 = 1;
    } else {
        return 0;
    }

done:
    return 0;
}
