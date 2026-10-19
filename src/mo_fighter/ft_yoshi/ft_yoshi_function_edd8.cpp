#pragma force_active on
extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_95_data_28[];

extern "C" void* fn_95_EDD8(void* object) {
    __ct__21ftExtendParamAccesserF6ftKind(object, 4);
    *(void**)((char*)object + 8) = lbl_95_data_28;
    *(void**)object = lbl_95_data_28 + 8;
    return object;
}
