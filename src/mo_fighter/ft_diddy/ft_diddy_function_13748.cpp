#pragma force_active on
extern "C" void fn_115_6654(void*, unsigned char);
extern "C" unsigned char lbl_115_data_8184[];
struct S {
    void* vtable;
    int pad4;
    void* data;
    int fieldC, field10, field14, field18;
    unsigned char* p[10];
    void* pad44;
    unsigned char* p0;
    unsigned char* pC;
    unsigned char* p10;
    unsigned char* p14;
    unsigned char* p30;
};
extern "C" S* fn_115_13748(S* self, unsigned char* param) {
    fn_115_6654(self, 0);
    self->fieldC = 0x37;
    self->field10 = 0xF9F;
    self->field14 = 0x5DBF;
    self->field18 = 0;
    self->data = lbl_115_data_8184;
    self->vtable = &lbl_115_data_8184[8];
    self->p[0] = param + 4;
    self->p[1] = param + 8;
    self->p[2] = param + 0x18;
    self->p[3] = param + 0x1C;
    self->p[4] = param + 0x20;
    self->p[5] = param + 0x24;
    self->p[6] = param + 0x28;
    self->p[7] = param + 0x2C;
    self->p[8] = param + 0x34;
    self->p[9] = param + 0x38;
    self->p0 = param;
    self->pC = param + 0xC;
    self->p10 = param + 0x10;
    self->p14 = param + 0x14;
    self->p30 = param + 0x30;
    return self;
}