#pragma force_active on
extern "C" unsigned char lbl_27_data_15808[];

struct Object {
    void* vtable;
    unsigned char flag;
    unsigned char pad5[3];
    void* table;
    unsigned char enabled : 1;
    unsigned char remaining : 7;
    unsigned char padD[3];
    int value;
    int index;
    unsigned char state;
};

extern "C" void fn_27_A78C0(Object* self) {
    self->flag = 0;
    self->enabled = 1;
    self->table = lbl_27_data_15808;
    self->vtable = lbl_27_data_15808 + 8;
    self->value = 0;
    self->index = -1;
    self->state = 0;
}
