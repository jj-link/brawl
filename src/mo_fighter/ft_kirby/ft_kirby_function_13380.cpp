#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_96_data_28[];

extern "C" void* fn_96_13380(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 5);
    ((void**)self)[2] = lbl_96_data_28;
    ((void**)self)[0] = lbl_96_data_28 + 8;
    return self;
}
