#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_104_data_30[];

extern "C" void* fn_104_DCB8(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0xD);
    char* data = lbl_104_data_30;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
