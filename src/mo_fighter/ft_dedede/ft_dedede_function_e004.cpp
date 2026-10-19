#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_117_data_C0[];

extern "C" void* fn_117_E004(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x20);
    char* data = lbl_117_data_C0;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
