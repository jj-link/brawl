#pragma force_active on
struct Ctx {
    unsigned short unk0;
    unsigned char pad002[0x0A];
    unsigned int unkC;
    unsigned char pad010[0x08];
    unsigned short unk18;
    unsigned char pad01A[0x06];
    unsigned char unk20;
    unsigned char pad021;
    unsigned char unk22;
    unsigned char pad023[0x05];
    unsigned int unk28;
    unsigned char pad02C[0x1F84 - 0x2C];
    int unk1F84;
    unsigned char pad1F88[0x1FC0 - 0x1F88];
    int (*unk1FC0)(int);
};

inline int inline_fn(struct Ctx *arg0) {
    return arg0->unk0 - 1;
}

extern int fn_803E8DC0(void *, unsigned short *, unsigned int, unsigned int, unsigned short);

int fn_803E2468(struct Ctx *arg0, int arg1, int *arg2) {
    unsigned short temp_r28;
    unsigned short var_r27;
    int var_r26;
    unsigned int var_r25;
    unsigned char buf[4];
    unsigned short temp_r9;
    unsigned short temp_r0;
    int temp_r3;
    int temp_r3_2;
    int (*temp_r12)(int);
    unsigned int temp_r0_3;
    unsigned short sp8;

    temp_r0 = (unsigned short)(arg1 + (arg1 >> 1));
    temp_r9 = arg0->unk18;
    var_r25 = 1;
    var_r27 = (unsigned short)(arg0->unk28 + ((int)temp_r0 >> arg0->unk20));
    temp_r28 = (unsigned short)(temp_r0 & inline_fn(arg0));
    if (temp_r9 & 0x80) {
        var_r25 = temp_r9 & 7;
    }

    do {
        if ((int)temp_r28 < (int)inline_fn(arg0)) {
            var_r26 = fn_803E8DC0(arg0, (unsigned short *)buf, (unsigned short)var_r27, temp_r28, 2);
        } else {
            temp_r3 = fn_803E8DC0(arg0, (unsigned short *)buf, (unsigned short)var_r27, temp_r28, 1);
            var_r26 = temp_r3;
            if (temp_r3 == 0) {
                var_r26 = fn_803E8DC0(arg0, (unsigned short *)(buf + 1),
                                      (unsigned short)var_r27 + 1, 0, 1);
            }
        }
        if (var_r26 == 0x1000) {
            temp_r12 = arg0->unk1FC0;
            if (temp_r12 != 0) {
                temp_r3_2 = temp_r12(arg0->unk1F84);
                if (temp_r3_2 == 0) {
                    continue;
                }
                if (temp_r3_2 == 1) {
                    if (arg0->unk22 >= 2 && var_r25 < arg0->unk22) {
                        var_r25 += 1;
                        var_r27 += (unsigned short)arg0->unkC;
                        continue;
                    }
                }
            }
        }
        if (var_r26 != 0) {
            *arg2 = -1;
            return var_r26;
        }
    } while (var_r26 != 0);

    sp8 = *(unsigned short *)buf;
    temp_r0_3 = ((sp8 >> 8) & 0xFF) | (((unsigned int)sp8 << 8) & 0xFF00);
    if (arg1 & 1) {
        *arg2 = (temp_r0_3 >> 4) & 0xFFF;
    } else {
        *arg2 = temp_r0_3 & 0xFFF;
    }
    return 0;
}