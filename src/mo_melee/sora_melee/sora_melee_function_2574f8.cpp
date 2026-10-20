#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 lbl_27_data_53050;

struct Object {
    u8 pad0[0x11B];
    u8 flag1 : 1;
    u8 rest1 : 7;
    u8 flag2 : 1;
    u8 rest2 : 7;
    u8 pad1[0x1F];
    u32 field13c;
    u32 field140;
};

extern "C" void fn_27_2574F8(Object* self) {
    self->flag1 = 1;
    self->flag2 = 0;
    self->field13c = lbl_27_data_53050;
    self->field140 = 0;
}
