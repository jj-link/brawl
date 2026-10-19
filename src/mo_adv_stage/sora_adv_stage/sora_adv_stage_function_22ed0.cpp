#pragma force_active on
typedef unsigned char u8;

extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern const float lbl_40_rodata_310;
extern char lbl_40_data_61D0[];

struct GimmickObj {
    char pad0[0x3c];
    void* vtbl;
    char pad1[0x14c - 0x40];
    u8 flag0;
    u8 flag1;
    char pad2[0x150 - 0x14e];
    float fval;
    int ival0;
    int ival1;
};

extern "C" {
GimmickObj* fn_40_22ED0(GimmickObj* self, const char* name) {
    __ct__9grGimmickFPCc(self, name);
    self->flag0 = 0;
    self->vtbl = lbl_40_data_61D0;
    self->flag1 = 0;
    self->fval = lbl_40_rodata_310;
    self->ival0 = 0;
    self->ival1 = 0;
    return self;
}
}
