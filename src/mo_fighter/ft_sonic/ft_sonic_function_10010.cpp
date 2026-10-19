#pragma force_active on
extern "C" unsigned char lbl_123_data_64B8[];

extern "C" void fn_123_10010(void *object) {
    *(void **)object = lbl_123_data_64B8;
}
