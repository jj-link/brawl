#pragma force_active on
typedef unsigned int u32;

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x118];
    u32 field158;
    u32 field15C;
    u32 field160;
    u32 field164;
    u32 field168;
    u32 field16C;
    u32 field170;
    u32 field174;
    char field178;
    char pad179[3];
    u32 field17C;
};

extern "C" void fn_88_4368(Object*);
extern "C" char lbl_88_data_DF8[];

extern "C" Object* fn_88_4CFC(Object* self) {
    fn_88_4368(self);
    self->field158 = 0;
    self->vtable = lbl_88_data_DF8;
    self->field15C = 0;
    self->field160 = 0;
    self->field164 = 0;
    self->field168 = 0;
    self->field16C = 0;
    self->field170 = 0;
    self->field174 = 0;
    self->field178 = 0;
    self->field17C = 0;
    return self;
}
