#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_40_rodata_380;
extern const float lbl_40_rodata_384;
extern unsigned char lbl_40_data_6D90[];
}

struct Work {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x150 - 0x40];
    unsigned char field150;
    float field154;
    float field158;
    float field15C;
    int field160;
    int field164;
    int field168;
    unsigned char pad16C[0x194 - 0x16C];
    int field194;
    int field198;
};

extern "C" Work* fn_40_24D88(Work* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = lbl_40_data_6D90;
    self->field150 = 0;
    self->field154 = lbl_40_rodata_380;
    self->field158 = lbl_40_rodata_380;
    self->field15C = lbl_40_rodata_384;
    self->field160 = 0;
    self->field164 = 0;
    self->field168 = 40;
    self->field194 = 0;
    self->field198 = 0;
    return self;
}
