#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_27_rodata_45A8;
extern unsigned char lbl_27_data_5A900[];
}

struct Work {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x150 - 0x40];
    int field150;
    int field154;
    float field158;
};

extern "C" Work* fn_27_27C070(Work* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->vtable = lbl_27_data_5A900;
    self->field150 = 0;
    self->field154 = 0;
    self->field158 = lbl_27_rodata_45A8;
    return self;
}
