#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_110_data_8E80[];

extern "C" void* fn_110_20E14(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x31);
    char* data = lbl_110_data_8E80;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
