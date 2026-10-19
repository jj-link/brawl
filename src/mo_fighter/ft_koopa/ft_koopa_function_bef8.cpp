#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_102_data_8[];

struct KoopaParamAccesser {
    void* vtbl;
    int unk4;
    void* data;
};

extern "C" {
KoopaParamAccesser* fn_102_BEF8(KoopaParamAccesser* p) {
    __ct__21ftExtendParamAccesserF6ftKind(p, 0xb);
    p->data = lbl_102_data_8;
    p->vtbl = lbl_102_data_8 + 8;
    return p;
}
}
