#pragma force_active on
extern "C" int fn_800305B0(int);
extern "C" int fn_80030548(int);
extern "C" int fn_80030DEC(int, int);
extern "C" void fn_8004EEC8(int, int);
extern "C" int fn_80030F2C(int);
extern int lbl_2_bss_70;
extern int lbl_2_bss_5C;
extern int lbl_2_data_5220;
extern int g_GameGlobal;

extern "C" int fn_2_3D0D8() {
    if (!fn_800305B0(0)) {
        lbl_2_bss_70 = 1;
        return 0;
    }
    int result = fn_80030548(lbl_2_data_5220);
    lbl_2_bss_5C = result;
    if (!result) {
        lbl_2_bss_70 = 2;
        return 0;
    }
    int value = fn_80030DEC(result, 0);
    if (!value) {
        lbl_2_bss_70 = 3;
        return 0;
    }
    fn_8004EEC8(g_GameGlobal, value);
    if (!fn_80030F2C(lbl_2_bss_5C)) {
        lbl_2_bss_70 = 4;
        return 0;
    }
    return 1;
}