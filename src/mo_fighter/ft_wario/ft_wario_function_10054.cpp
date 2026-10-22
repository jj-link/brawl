#pragma force_active on

extern "C" void fn_110_6D2C(void* object, unsigned int value);
extern "C" unsigned char lbl_110_data_6EB8[];

struct S {
    void* vtable;
    int pad4;
    void* data;
    int fieldC;
    int field10;
    int field14;
    int field18;
    unsigned char* p[37];
};

extern "C" void* fn_110_10054(S* self, unsigned char* a) {
    fn_110_6D2C(self, 0);
    self->fieldC = 0x60;
    self->field10 = 0xF9F;
    self->field14 = 0x5DBF;
    self->field18 = 0;
    self->data = lbl_110_data_6EB8;
    self->vtable = &lbl_110_data_6EB8[8];
    self->p[0] = a;
    self->p[1] = a + 4;
    self->p[2] = a + 8;
    self->p[3] = a + 0xC;
    self->p[4] = a + 0x10;
    self->p[5] = a + 0x14;
    self->p[6] = a + 0x18;
    self->p[7] = a + 0x1C;
    self->p[8] = a + 0x20;
    self->p[9] = a + 0x24;
    self->p[10] = a + 0x28;
    self->p[11] = a + 0x30;
    self->p[12] = a + 0x34;
    self->p[13] = a + 0x38;
    self->p[14] = a + 0x3C;
    self->p[15] = a + 0x40;
    self->p[16] = a + 0x44;
    self->p[17] = a + 0x48;
    self->p[18] = a + 0x4C;
    self->p[19] = a + 0x50;
    self->p[20] = a + 0x54;
    self->p[21] = a + 0x58;
    self->p[22] = a + 0x5C;
    self->p[23] = a + 0x60;
    self->p[24] = a + 0x64;
    self->p[25] = a + 0x68;
    self->p[26] = a + 0x6C;
    self->p[27] = a + 0x78;
    self->p[28] = a + 0x84;
    self->p[29] = a + 0x88;
    self->p[30] = a + 0x8C;
    self->p[31] = a + 0x90;
    self->p[32] = a + 0x94;
    self->p[33] = a + 0x98;
    self->p[35] = a + 0x2C;
    self->p[36] = a + 0x70;
    self->p[37] = a + 0x74;
    self->p[38] = a + 0x7C;
    self->p[39] = a + 0x80;
    return self;
}
