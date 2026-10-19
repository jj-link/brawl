#pragma force_active on
extern "C" unsigned int fn_41_23144(int x);
extern "C" unsigned int lbl_41_data_32B0[];

extern "C" unsigned int fn_41_231D4(int x) {
    if (fn_41_23144(x) == 1) {
        return 0;
    }
    return lbl_41_data_32B0[x - 9];
}
