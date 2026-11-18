#pragma force_active on

struct FnObj {
    unsigned char pad0[0x1bc];
    int unk1BC;
    unsigned char pad1[0x1414 - 0x1C0];
    int unk1414;
    int unk1418;
    unsigned char pad2[0x1428 - 0x141C];
    int unk1428;
    unsigned char pad3[0x1442 - 0x142C];
    unsigned char unk1442;
    unsigned char unk1443;
};

static inline void helper(FnObj* arg0, int arg1, int temp_r9) {
    int var_r8;
    int temp_r7;
    {
        temp_r7 = arg0->unk1428;
        var_r8 = 0;
        int base = arg0->unk1414;
        arg0->unk1428 = temp_r7 + arg1;
        temp_r7 = base - temp_r7;
        if (arg0->unk1442 == 0 && arg0->unk1418 < 0) {
            var_r8 = 1;
        }
        int temp_r6 = arg0->unk1428;
        int var_r5;
        if (temp_r6 < 0) {
            var_r5 = 0;
            if (var_r8 != 0 && temp_r6 <= arg1) {
                var_r5 = 1;
            }
            arg0->unk1443 = var_r5;
            int mask = ((-var_r5) | var_r5) >> 31;
            arg0->unk1428 = temp_r9 & mask;
        } else if (temp_r6 > temp_r9) {
            var_r5 = 0;
            if (var_r8 != 0 && temp_r6 >= temp_r9 + arg1) {
                var_r5 = 1;
            }
            arg0->unk1443 = var_r5;
            int mask = ((-var_r5) | var_r5) >> 31;
            arg0->unk1428 = temp_r9 & ~mask;
        }
        int finalPosition = arg0->unk1428;
        arg0->unk1442 = 1;
        arg0->unk1414 = finalPosition + temp_r7;
    }
}
extern "C" void fn_40_467B8(FnObj* arg0, int arg1) {
    int temp_r9 = arg0->unk1BC - 3;
    if (temp_r9 > 0) {
        helper(arg0, arg1, temp_r9);
    }
}
