#pragma force_active on
extern "C" {
    void* __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
    extern char lbl_123_data_28[];
}

extern "C" void* fn_123_EDA4(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x2F);
    char* data = lbl_123_data_28;
    ((void**)self)[2] = data;
    ((void**)self)[0] = data + 8;
    return self;
}
