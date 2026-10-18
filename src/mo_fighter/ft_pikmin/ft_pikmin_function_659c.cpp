#pragma force_active on
extern "C" unsigned char lbl_113_data_71D4[];

typedef struct {
    void *vtable;
    void *field;
} Obj;

extern "C" void fn_113_659C(Obj *self, void *value) {
    self->field = value;
    self->vtable = lbl_113_data_71D4;
}
