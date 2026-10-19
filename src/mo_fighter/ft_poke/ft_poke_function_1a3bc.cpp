#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern char lbl_116_data_7D34[];

extern "C" void* fn_116_1A3BC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x1e);
    char* data = lbl_116_data_7D34;
    ((char**)self)[2] = data;
    ((char**)self)[0] = data + 8;
    return self;
}
