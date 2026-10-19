#pragma force_active on
extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_110_data_28[];

struct ftWarioParamAccesser {
    char* vtbl0;
    void* unk4;
    char* vtbl8;
};

extern "C" ftWarioParamAccesser* fn_110_C754(ftWarioParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x15);
    self->vtbl8 = lbl_110_data_28;
    self->vtbl0 = lbl_110_data_28 + 8;
    return self;
}
