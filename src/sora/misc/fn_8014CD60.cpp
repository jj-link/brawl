#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct fn_8014CD60_work {
    u8 m0;
    u8 pad1[3];
    u32 m4;
    u32 m8;
    u32 mC;
    u32 m10;
};

extern "C" void fn_8014CD60(fn_8014CD60_work* self, u32 value) {
    self->m4 = value;
    self->m10 = 0;
    self->mC = 0;
    self->m0 = 0;
    self->m8 = 0;
}
