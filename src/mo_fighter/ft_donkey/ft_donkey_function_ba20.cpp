#include <types.h>
#pragma force_active on

extern "C" const float lbl_92_rodata_8;
extern "C" const float lbl_92_rodata_C;

struct Vec2fLocal {
    float m_x;
    float m_y;
};

extern "C" Vec2fLocal* fn_92_BA0C(Vec2fLocal* dst, const Vec2fLocal* src);

struct FtDonkeyVecState {
    u8 pad0[0x8];
    Vec2fLocal v8;
    Vec2fLocal v10;
    Vec2fLocal v18;
    Vec2fLocal v20;
    Vec2fLocal v28;
    u8 f30;
    u8 f31;
    u8 f32;
};

extern "C" void fn_92_BA20(FtDonkeyVecState* self) {
    Vec2fLocal t1;
    Vec2fLocal t2;
    t1.m_x = lbl_92_rodata_8;
    t1.m_y = lbl_92_rodata_8;

    fn_92_BA0C(&self->v8, fn_92_BA0C(&self->v10, fn_92_BA0C(&self->v20, &t1)));

    t2.m_x = lbl_92_rodata_C;
    t2.m_y = lbl_92_rodata_C;
    fn_92_BA0C(&self->v18, fn_92_BA0C(&self->v28, &t2));
    self->f31 = 0;
    self->f30 = 0;
    self->f32 = 1;
}
