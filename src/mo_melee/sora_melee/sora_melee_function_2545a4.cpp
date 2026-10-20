#pragma force_active on
extern "C" {
extern char lbl_27_data_52AC0[];
extern char lbl_27_data_52AD8[];
extern const float lbl_27_rodata_4118;
extern const float lbl_27_rodata_411C;

void* fn_27_241E30(void*, const char*);
}

struct Object {
    char pad0[0x2C];
    unsigned char flagsHigh : 6;
    unsigned char flag : 1;
    unsigned char flagsLow : 1;
    char pad2D[0x0F];
    void* table;
    unsigned char kind;
    char pad41[7];
    unsigned int field48;
    unsigned int field4C;
    char pad50[0x30];
    float field80;
    float field84;
    float field88;
    float field8C;
    float field90;
    float field94;
    float field98;
    float field9C;
    float fieldA0;
    unsigned char fieldA4;
};

extern "C" void* fn_27_2545A4(Object* self) {
    fn_27_241E30(self, lbl_27_data_52AC0);
    self->field9C = lbl_27_rodata_4118;
    self->table = lbl_27_data_52AD8;
    self->flag = 0;
    self->kind = 3;
    self->field48 = 0;
    self->field4C = 0;
    self->field98 = lbl_27_rodata_411C;
    self->field9C = lbl_27_rodata_4118;
    self->fieldA0 = lbl_27_rodata_4118;
    self->fieldA4 = 0;
    self->field80 = lbl_27_rodata_4118;
    self->field84 = lbl_27_rodata_4118;
    self->field88 = lbl_27_rodata_4118;
    self->field8C = lbl_27_rodata_4118;
    self->field90 = lbl_27_rodata_4118;
    self->field94 = lbl_27_rodata_4118;
    return self;
}
