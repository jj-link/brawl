#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_107_data_8[];

extern "C" void* fn_107_FDF4(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x12);
    char* p = lbl_107_data_8;
    ((void**)self)[2] = p;
    ((void**)self)[0] = p + 8;
    return self;
}
