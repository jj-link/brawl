#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_36028(void* a, s32 b, s32 c);
extern "C" void fn_27_41654(void* a, void* b);
extern "C" s32 fn_27_3786C(s32 index);

extern "C" float lbl_27_rodata_4B8;

struct Self {
    s32 id;
    s16 off;
    s16 cnt;
    float f8;
    float fc;
    s32 f10;
    float f14;
    float f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s8 f30;
    s8 f31;
    s8 f32;
    s8 f33;
};

class Obj {
public:
    virtual void* f0();
    virtual void* f1(s32);
};

extern "C" void fn_27_41B40(Self* self, s32 arg1, Obj* arg2, s32 arg3, float f1, float f2, float f3) {
    self->f8 = f1;
    self->fc = f2;
    self->f10 = arg3;
    self->f14 = f3;
    self->f2c = 0;
    if (self->id != -1) {
        float tmp = lbl_27_rodata_4B8;
        self->f1c = 0;
        self->f18 = tmp;
        self->f20 = 0;
        self->f31 = 0;
        self->f24 = 0;
        self->f32 = 0;
        self->f28 = 0;
        self->f33 = 1;
        self->f30 = 0;
        fn_27_3786C(arg3);
        s32 vret;
        s32 i = 0;
        while (i < self->cnt) {
            vret = (s32)arg2->f1(self->off + i);
            s32 h = fn_27_36028((void*)arg1, i, self->id);
            fn_27_41654((void*)vret, (void*)h);
            i++;
        }
    }
}