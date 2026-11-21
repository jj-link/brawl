#pragma force_active on
#include <types.h>
#include <snd/snd_system.h>
#include <nw4r/math.h>

extern const float lbl_805A1AC8;
extern const float lbl_805A1ACC;

class ScaleClass {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(s32, f32);
};

void sndSystem::setBGMVol(bool setImmediately, float volume) {
    char* self = (char*)this;
    f32 one = lbl_805A1AC8;
    f32 difference = one - volume;
    f32 zero = lbl_805A1ACC;
    f32 clamped = nw4r::math::FSelect(difference, volume, one);
    clamped = nw4r::math::FSelect(zero - clamped, zero, clamped);
    *(f32*)(self + 0x700) = clamped;
    if (!setImmediately) {
        return;
    }
    f32 c = *(f32*)(self + 0x700);
    f32 f = *(f32*)(self + 0x714) * (*(f32*)(self + 0x704) * (c * *(f32*)(self + 0x708)));
    ScaleClass* obj = *(ScaleClass**)(self + 0x6E0);
    if (obj != 0) {
        obj->v12(0, f);
    }
}
