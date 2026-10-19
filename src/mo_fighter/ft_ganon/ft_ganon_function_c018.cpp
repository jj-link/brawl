#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_109_data_28[];

extern "C" void* fn_109_C018(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x14);
    *(void**)((char*)self + 8) = lbl_109_data_28;
    *(void**)self = lbl_109_data_28 + 8;
    return self;
}
