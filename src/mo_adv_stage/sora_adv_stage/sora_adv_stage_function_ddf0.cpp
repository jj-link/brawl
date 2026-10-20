#pragma force_active on
struct Object {
    unsigned int unk0;
    void* table;
    unsigned char pad[0x34];
    void* table3C;
    unsigned int value;
    Object* owner;
};

extern "C" {
extern unsigned char lbl_40_data_1A08[];
extern unsigned char lbl_40_data_1A68[];

Object* fn_27_234C6C(Object*, unsigned int, unsigned char);

Object* fn_40_DDF0(Object* self, unsigned int value, unsigned char flag) {
    fn_27_234C6C(self, value, flag);
    self->table = lbl_40_data_1A08;
    self->table3C = lbl_40_data_1A68;
    self->value = value;
    self->owner = self;
    return self;
}
}
