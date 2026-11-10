#pragma force_active on

typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 unk0;
    char pad2[0xA];
    u32 unkC;
    char pad10[0x8];
    u16 unk18;
    char pad1A[0x6];
    u8 unk20;
    char pad21;
    u8 unk22;
    char pad23[0x5];
    u32 unk28;
    char pad2C[0x8];
    s32 unk34;
    char pad38[0x1870 - 0x38];
    void *unk1870;
    char pad1874[0x1890 - 0x1874];
    s32 (*unk1890)(void *);
} Unk;

extern s32 fn_803BFFC8(void *, void *, u32, u32, s32);

s32 fn_803B900C(Unk *arg0, u32 arg1, u32 *arg2)
{
    u16 sp8;
    s32 cbret;
    u32 temp_r7;
    u16 temp_r8;
    u32 var_r28;
    u32 var_r27;
    s32 ret;
    u32 var_r31;
    s32 (*cb)(void *);

    if (arg0 == 0) {
        *arg2 = -1;
        return 0xA;
    }
    if ((arg1 < 2 || arg1 >= (u32)(arg0->unk34 + 2)) &&
        arg1 != 0 && arg1 != 1) {
        *arg2 = -1;
        return 0xE;
    }

    temp_r8 = arg0->unk18;
    temp_r7 = arg1 * 2;
    var_r31 = 1;
    var_r28 = (u16)(arg0->unk28 + (temp_r7 >> arg0->unk20));
    var_r27 = (u16)(temp_r7 & (arg0->unk0 - 1));
    if (temp_r8 & 0x80) {
        var_r31 = temp_r8 & 7;
    }

    for (;;) {
        ret = fn_803BFFC8(arg0, &sp8, var_r28, var_r27, 2);
        if (ret == 0x1000) {
            cb = arg0->unk1890;
            if (cb != 0) {
                cbret = cb(arg0->unk1870);
                if (cbret == 0) {
                    goto check;
                }
                if (cbret == 1 && arg0->unk22 >= 2 &&
                    var_r31 < arg0->unk22) {
                    var_r31 += 1;
                    var_r28 += arg0->unkC;
                    goto check;
                }
            }
        }
        if (ret != 0) {
            *arg2 = -1;
            return ret;
        }
check:
        if (ret == 0) {
            break;
        }
    }

    *arg2 = ((sp8 >> 8) & 0xFF) | ((sp8 << 8) & 0xFF00);
    return 0;
}
