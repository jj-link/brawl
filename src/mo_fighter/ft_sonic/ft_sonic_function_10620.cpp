#pragma force_active on
extern "C" unsigned char lbl_123_data_66C8[];

extern "C" void* fn_123_10620(void** object) {
    *object = lbl_123_data_66C8;
    return object;
}
