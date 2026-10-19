#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_93_data_8C[];

extern "C" void* fn_93_E9BC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 2);

    unsigned char* data = lbl_93_data_8C;
    *(unsigned char**)((char*)self + 8) = data;
    *(unsigned char**)((char*)self + 0) = data + 8;

    return self;
}
