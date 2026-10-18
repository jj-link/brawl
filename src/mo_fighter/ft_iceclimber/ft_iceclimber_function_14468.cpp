#pragma force_active on
extern "C" unsigned char lbl_105_data_80D8[];

extern "C" void* fn_105_14468(void* object) {
    *(void**)object = (void*)lbl_105_data_80D8;
    return object;
}
