#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" char lbl_120_data_28[];

extern "C" void* fn_120_CCAC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x23);
    *(void**)((char*)self + 8) = lbl_120_data_28;
    *(void**)self = lbl_120_data_28 + 8;
    return self;
}
