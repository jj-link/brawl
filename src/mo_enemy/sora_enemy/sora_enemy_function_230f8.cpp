#pragma force_active on
extern "C" unsigned int fn_41_230D8(int);
extern "C" unsigned int lbl_41_data_3280[6];

extern "C" int fn_41_230F8(int x) {
    if (fn_41_230D8(x) == 1u) {
        return 8;
    }
    return lbl_41_data_3280[x];
}
