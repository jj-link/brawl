#pragma force_active on
extern "C" unsigned int fn_41_23144(int);
extern "C" void* lbl_41_data_3298[6];

extern "C" void* fn_41_23184(int x) {
    if (fn_41_23144(x) == 1u) return 0;
    return lbl_41_data_3298[x - 9];
}
