#pragma force_active on
extern "C" {
struct Obj {
    void *vtable;
    unsigned char flag;
    unsigned char pad[3];
    void *arg;
    int value;
    int count;
    unsigned char tail;
};

extern char lbl_27_data_17C58[];

void fn_27_C319C(Obj *self, void *arg) {
    self->flag = 0;
    self->vtable = lbl_27_data_17C58;
    self->arg = arg;
    self->value = -1;
    self->count = 12;
    self->tail = 0;
}
}
