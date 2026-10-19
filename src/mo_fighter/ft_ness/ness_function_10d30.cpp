#pragma force_active on
struct ftExtendParamAccesser {
    unsigned char* base;
    unsigned char data[4];
    unsigned char* table;
};

extern "C" {
void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern unsigned char lbl_101_data_28[];
}

extern "C" ftExtendParamAccesser* fn_101_10D30(ftExtendParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 10);
    self->table = lbl_101_data_28;
    self->base = lbl_101_data_28 + 8;
    return self;
}
