#pragma force_active on
struct Object {
    unsigned char pad00[0x2C];
    unsigned char flags2C;
    unsigned char pad2D[0xF];
    void* table;
    unsigned char pad40[2];
    unsigned char flags42a : 2;
    unsigned char flag42 : 1;
    unsigned char flags42b : 5;
    unsigned char pad43[0x169];
    void* field1AC;
};

extern "C" void fn_800FB408(Object*, void*, int, int);
extern "C" unsigned char lbl_6_data_270[];

extern "C" Object* fn_6_180(Object* self, void* arg) {
    fn_800FB408(self, arg, 0xF0, 0xFF);
    self->table = lbl_6_data_270;
    self->field1AC = 0;
    self->flag42 = 1;
    self->flags2C &= ~2;
    return self;
}
