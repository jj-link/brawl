#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_118_data_28[];

extern "C" void* fn_118_D2BC(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x21);
    unsigned char* data = lbl_118_data_28;
    *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 8) = data;
    *reinterpret_cast<unsigned char**>(self) = data + 8;
    return self;
}
