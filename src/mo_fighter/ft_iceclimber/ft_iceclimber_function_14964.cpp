#pragma force_active on
extern "C" unsigned char lbl_105_data_8150[];

extern "C" void *fn_105_14964(void *object) {
    *(void **)object = (void *)lbl_105_data_8150;
    return object;
}
