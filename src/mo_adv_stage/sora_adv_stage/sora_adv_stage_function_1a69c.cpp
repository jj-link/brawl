#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_40_rodata_280;
extern unsigned char lbl_40_data_46F8[];
}

struct Work {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x11C];
    int field15C;
    int field160;
    unsigned char pad164[8];
    unsigned char field16C;
    unsigned char field16D;
    unsigned char field16E;
    float field170;
    unsigned char field174;
    unsigned char field175;
    unsigned char pad176[2];
    int field178;
    float field17C;
    unsigned char field180;
    unsigned char field181;
    unsigned char pad182[2];
    int field184;
    float field188;
    unsigned char field18C;
    unsigned char field18D;
    unsigned char pad18E[2];
    int field190;
    float field194;
    unsigned char field198;
    unsigned char field199;
    unsigned char pad19A[2];
    int field19C;
    float field1A0;
    unsigned char field1A4;
    unsigned char pad1A5[3];
    float field1A8;
    int field1AC;
    int field1B0;
    unsigned char pad1B4[0x2C];
    int field1E0;
    int field1E4;
};

extern "C" Work* fn_40_1A69C(Work* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = lbl_40_data_46F8;
    self->field15C = 0;
    self->field160 = 0;
    self->field16C = 0;
    self->field16D = 0;
    self->field16E = 0;
    self->field170 = lbl_40_rodata_280;
    self->field1A4 = 2;
    self->field1A8 = lbl_40_rodata_280;
    self->field1AC = 0x3C;
    self->field1B0 = 0x3C;
    self->field1E0 = 0;
    self->field1E4 = 0;
    self->field174 = 0;
    self->field175 = 0;
    self->field178 = -1;
    self->field17C = lbl_40_rodata_280;
    self->field180 = 0;
    self->field181 = 0;
    self->field184 = -1;
    self->field188 = lbl_40_rodata_280;
    self->field18C = 0;
    self->field18D = 0;
    self->field190 = -1;
    self->field194 = lbl_40_rodata_280;
    self->field198 = 0;
    self->field199 = 0;
    self->field19C = -1;
    self->field1A0 = lbl_40_rodata_280;
    return self;
}
