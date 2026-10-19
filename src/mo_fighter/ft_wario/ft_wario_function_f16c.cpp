#pragma force_active on
extern "C" unsigned char lbl_110_data_6910[];

extern "C" void* fn_110_F16C(void** object) {
    *object = lbl_110_data_6910;
    return object;
}
