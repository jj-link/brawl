#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_126_data_5DF0[];

extern "C" void* fn_126_D704(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x34);
    char* data = lbl_126_data_5DF0;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
