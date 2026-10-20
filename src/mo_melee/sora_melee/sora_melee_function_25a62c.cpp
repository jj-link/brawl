#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Object {
    u8 pad0[0x3C];
    void* vtable;
    u8 pad40[0xDB];
    u8 flag11B;
    u8 flag11C;
    u8 flag11D;
    u8 flag11E;
    u8 flag11F;
    u32 field120;
    u32 field124;
    u32 field128;
    u32 field12C;
};

extern "C" {
extern u8 lbl_27_data_539A0[0x30];
extern u8 lbl_27_data_539D0[0x90];
extern u32 lbl_27_data_53998[2];

void fn_27_255808(Object*, const void*);

Object* fn_27_25A62C(Object* self) {
    fn_27_255808(self, lbl_27_data_539A0);
    self->vtable = lbl_27_data_539D0;
    self->flag11B = 0;
    self->flag11C = 0;
    self->flag11D = 0;
    self->flag11E = 0;
    self->flag11F = 0;
    self->field128 = lbl_27_data_53998[0];
    self->field12C = 0;
    self->field124 = 0;
    return self;
}
}
