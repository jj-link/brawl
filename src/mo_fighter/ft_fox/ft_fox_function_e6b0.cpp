#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern "C" char lbl_97_data_50[];

extern "C" void* fn_97_E6B0(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 6);
    ((void**)self)[2] = lbl_97_data_50;
    ((void**)self)[0] = lbl_97_data_50 + 8;
    return self;
}
