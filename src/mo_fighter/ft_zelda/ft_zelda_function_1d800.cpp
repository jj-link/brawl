#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" char lbl_104_data_8984[];

extern "C" void* fn_104_1D800(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0xE);
    *(void**)((char*)self + 8) = lbl_104_data_8984;
    *(void**)self = lbl_104_data_8984 + 8;
    return self;
}
