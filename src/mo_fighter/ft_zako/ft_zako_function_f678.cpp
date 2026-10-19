#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" char lbl_126_data_68A8[];

extern "C" void* fn_126_F678(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x35);
    char* data = lbl_126_data_68A8;
    *(char**)((char*)self + 8) = data;
    *(char**)self = data + 8;
    return self;
}
