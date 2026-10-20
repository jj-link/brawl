#pragma force_active on
extern "C" void fn_27_2464C8(void*, int);
extern "C" const float lbl_27_rodata_3FB8;
extern "C" unsigned char lbl_27_data_4EB90[];

struct Object {
    unsigned char pad0[0x3C];
    void* field3C;
    unsigned char field40;
    unsigned char pad41[0xB];
    float field4C;
};

extern "C" void* fn_27_247088(Object* self) {
    fn_27_2464C8(self, 1);
    self->field3C = lbl_27_data_4EB90;
    self->field40 = 0;
    self->field4C = lbl_27_rodata_3FB8;
    return self;
}
