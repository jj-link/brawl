#pragma force_active on
extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_102_data_637C[];

extern "C" void* fn_102_14E50(void* object) {
    __ct__21ftExtendParamAccesserF6ftKind(object, 0x30);
    *(void**)((char*)object + 0x8) = lbl_102_data_637C;
    *(void**)object = lbl_102_data_637C + 0x8;
    return object;
}
