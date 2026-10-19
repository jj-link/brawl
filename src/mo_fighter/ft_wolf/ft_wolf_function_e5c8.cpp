#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_125_data_50[];

extern "C" void* fn_125_E5C8(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x2c);
    char* data = lbl_125_data_50;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
