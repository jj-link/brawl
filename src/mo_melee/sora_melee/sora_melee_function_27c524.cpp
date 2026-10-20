#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_27_rodata_45B0;
extern unsigned char lbl_27_data_5AAE4[];

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x114];
    unsigned int field154;
    unsigned char field158;
    char pad159[3];
    float field15C;
    char pad160[0x30];
    unsigned int field190;
    unsigned int field194;
};

extern "C" Object* fn_27_27C524(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->field154 = 0;
    self->vtable = lbl_27_data_5AAE4;
    self->field158 = 0;
    self->field15C = lbl_27_rodata_45B0;
    self->field190 = 0;
    self->field194 = 0;
    return self;
}
