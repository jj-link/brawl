#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj27 {
    u8 pad_0[8];
    u32 flags_8;
};

extern "C" {
void fn_27_19A148(Obj27* self)
{
    self->flags_8 |= 0x00010000;
}
}
