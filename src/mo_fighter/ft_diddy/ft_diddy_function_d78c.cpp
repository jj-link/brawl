#pragma force_active on
extern "C" {
extern char lbl_115_data_30[];
void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
}

struct ftDiddyParamAccesser {
    char* vptr;
    int unk4;
    char* sub;
};

extern "C" ftDiddyParamAccesser* fn_115_D78C(ftDiddyParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x1B);
    self->sub = lbl_115_data_30;
    self->vptr = lbl_115_data_30 + 8;
    return self;
}
