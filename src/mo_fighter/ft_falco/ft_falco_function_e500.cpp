#pragma force_active on
extern "C" {
extern char lbl_108_data_50[];
void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
}

struct ftFalcoParamAccesser {
    char* vptr;
    int unk4;
    char* sub;
};

extern "C" ftFalcoParamAccesser* fn_108_E500(ftFalcoParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x13);
    self->sub = lbl_108_data_50;
    self->vptr = lbl_108_data_50 + 8;
    return self;
}
