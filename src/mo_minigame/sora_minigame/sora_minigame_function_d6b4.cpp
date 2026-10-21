#pragma force_active on
#pragma global_optimizer off

extern "C" {
void fn_20_2CF4(void*);
extern char lbl_20_data_AE8[];
extern const float lbl_20_rodata_390[];
}

struct Object {
    void* table;
    char pad04[0x14];
    void* table18;
    void* table1C;
    unsigned char field20;
    unsigned char field21;
    char pad22[2];
    float field24;
    int field28;
    float field2C;
    float field30;
    int field34;
    char pad38[0x2C];
    float field64;
    float field68;
    float field6C;
    float field70;
};

extern "C" Object* fn_20_D6B4(Object* self) {
    const float* k = lbl_20_rodata_390;
    fn_20_2CF4(self);
    self->table = lbl_20_data_AE8;
    self->table18 = lbl_20_data_AE8 + 0x18;
    self->table1C = lbl_20_data_AE8 + 0x34;
    self->field34 = 0;
    self->field64 = k[0];
    self->field68 = k[0];
    self->field6C = k[0];
    self->field70 = k[1];
    self->field21 = 0;
    self->field24 = k[2];
    self->field2C = k[2];
    self->field28 = 0;
    self->field30 = k[0];
    return self;
}
