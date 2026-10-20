#pragma force_active on
struct Obj {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x134];
    unsigned char a;
    char pad175[3];
    float b;
    unsigned int c, d, e, f;
    unsigned char g, h;
    char pad18E[2];
    unsigned int i;
};

extern "C" {
void fn_63_2B6C(Obj*);
extern const float lbl_63_rodata_48;
extern char lbl_63_data_BA8[];

Obj* fn_63_3488(Obj* self) {
    fn_63_2B6C(self);
    self->vtable = lbl_63_data_BA8;
    self->a = 0;
    self->b = lbl_63_rodata_48;
    self->c = 0;
    self->d = 0;
    self->e = 0;
    self->f = 0;
    self->g = 1;
    self->h = 0;
    self->i = 0;
    return self;
}
}
