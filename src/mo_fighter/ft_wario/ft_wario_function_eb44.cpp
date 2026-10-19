#pragma force_active on
extern "C" unsigned char lbl_110_data_6848[];

extern "C" void fn_110_EB44(void *object) {
    *(void **)object = lbl_110_data_6848;
}
