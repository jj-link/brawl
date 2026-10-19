#pragma force_active on
typedef int ftKind;
extern "C" char lbl_121_data_8C[];

struct ftExtendParamAccesser {
    void* p0;
    char pad[4];
    void* p8;
};

extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(ftExtendParamAccesser*, ftKind);

extern "C" ftExtendParamAccesser* fn_121_E9B8(ftExtendParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 41);
    self->p8 = lbl_121_data_8C;
    self->p0 = lbl_121_data_8C + 8;
    return self;
}
