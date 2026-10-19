#pragma force_active on
extern "C" unsigned int fn_41_23144(int x);
extern "C" unsigned char lbl_41_data_32C8[];

extern "C" int fn_41_23224(int x) {
    if (fn_41_23144(x) == 1u) {
        return 0;
    }
    return lbl_41_data_32C8[x - 9];
}
