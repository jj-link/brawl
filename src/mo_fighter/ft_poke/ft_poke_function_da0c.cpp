#pragma force_active on
extern "C" {
void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern unsigned char lbl_116_data_28[];
}

extern "C" void* fn_116_DA0C(void* self) {
    char* p = (char*)self;
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x1d);
    *(unsigned char**)(p + 8) = lbl_116_data_28;
    *(unsigned char**)(p + 0) = lbl_116_data_28 + 8;
    return self;
}
