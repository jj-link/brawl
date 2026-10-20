#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_27_rodata_4410;
extern unsigned char lbl_27_data_57530[];
}

struct Work {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x154 - 0x40];
    int field154;
    unsigned char field158;
    unsigned char pad159[3];
    float field15C;
    unsigned char pad160[0x190 - 0x160];
    int field190;
    int field194;
};

extern "C" Work* __ct__15grGimmickSpringFPCc(Work* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = lbl_27_data_57530;
    self->field154 = 0;
    self->field158 = 0;
    self->field15C = lbl_27_rodata_4410;
    self->field190 = 0;
    self->field194 = 0;
    return self;
}
