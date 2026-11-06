#pragma force_active on

extern "C" void fn_112_7674(void* obj, unsigned char b);
extern "C" unsigned char lbl_112_data_7140[];

struct S {
    void* vtable;
    int pad4;
    void* data;
    int fieldC;
    int field10;
    int field14;
    int field18;
    void* p4;
    void* p8;
    void* pC;
    void* p18;
    void* p1C;
    void* p20;
    void* p24;
    void* p28;
    void* p2C;
    void* p30;
    void* p34;
    void* pad48;
    void* p0;
    void* p10;
    void* p14;
};

extern "C" S* fn_112_EFB8(S* self, unsigned char* param) {
    fn_112_7674(self, 0);
    self->fieldC = 0x7D;
    self->field10 = 0xF9F;
    self->field14 = 0x5DBF;
    self->field18 = 0;
    self->data = lbl_112_data_7140;
    self->vtable = &lbl_112_data_7140[8];
    self->p4 = param + 4;
    self->p8 = param + 8;
    self->pC = param + 0xC;
    self->p18 = param + 0x18;
    self->p1C = param + 0x1C;
    self->p20 = param + 0x20;
    self->p24 = param + 0x24;
    self->p28 = param + 0x28;
    self->p2C = param + 0x2C;
    self->p30 = param + 0x30;
    self->p34 = param + 0x34;
    self->p0 = param;
    self->p10 = param + 0x10;
    self->p14 = param + 0x14;
    return self;
}