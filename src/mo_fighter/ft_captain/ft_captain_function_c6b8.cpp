#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_100_data_28[];

extern "C" void* fn_100_C6B8(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 9);
    *(void**)((char*)self + 8) = lbl_100_data_28;
    *(void**)self = lbl_100_data_28 + 8;
    return self;
}
