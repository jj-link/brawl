#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" unsigned char lbl_122_data_170[];

extern "C" void* fn_122_13B94(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x2e);
    *(void**)((char*)self + 8) = lbl_122_data_170;
    *(void**)self = lbl_122_data_170 + 8;
    return self;
}
