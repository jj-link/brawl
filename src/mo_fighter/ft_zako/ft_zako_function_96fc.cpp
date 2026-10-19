#pragma force_active on
extern "C" {
void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_126_data_28[];
}

extern "C" void* fn_126_96FC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x32);
    void** p = (void**)self;
    p[2] = (void*)lbl_126_data_28;
    p[0] = (void*)(lbl_126_data_28 + 8);
    return self;
}
