#pragma force_active on
extern "C" void fn_93_1AC4(void*, int);
extern "C" unsigned char lbl_93_data_3194[];

struct Obj_93_47AC {
    void* secondary;
    unsigned char pad[4];
    void* vtable;
    void* value1;
    void* value2;
    void* value3;
    void* value4;
    void* value5;
    void* value6;
};

extern "C" Obj_93_47AC* fn_93_47AC(
    Obj_93_47AC* self,
    void* a,
    void* b,
    void* c,
    void* d,
    void* e,
    void* f
) {
    fn_93_1AC4(self, 0);
    self->vtable = lbl_93_data_3194;
    self->secondary = lbl_93_data_3194 + 8;
    self->value1 = a;
    self->value2 = b;
    self->value3 = c;
    self->value4 = d;
    self->value5 = e;
    self->value6 = f;
    return self;
}
