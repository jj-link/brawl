#include <types.h>
#pragma force_active on

struct Src27 {
    u8 pad0[0x20];
    u32 m_20;
    u32 m_24;
    u32 m_28;
};

extern "C" Src27* fn_27_14D600();
extern "C" extern const float lbl_27_rodata_F3C[4];

struct Block27 {
    u8 pad[0x44];
    u32 m44;
    s32 m48;
    s32 m4c;
    float m50;
    s32 m54;
    u32 m58;
    s32 m5c;
    u32 m60;
    s32 m64;
    s32 m68;
    s32 m6c;
    s32 m70;
    s32 m74;
    u8 pad78[4];
    u8 m7c;
    u8 m7d;
    u8 m7e;
};

extern "C" void fn_27_10FDA4(Block27* self) {
    Src27* s = fn_27_14D600();
    self->m44 = (u32)s;
    self->m48 = -1;
    self->m4c = 0x7fffffff;
    self->m50 = lbl_27_rodata_F3C[0];
    self->m54 = -1;
    self->m58 = s->m_20;
    self->m5c = -1;
    self->m60 = s->m_28;
    self->m64 = 0;
    self->m68 = -1;
    self->m6c = -1;
    self->m70 = -1;
    self->m74 = -1;
    self->m7d = 0;
    self->m7e = 0;
    self->m7c = 1;
}
