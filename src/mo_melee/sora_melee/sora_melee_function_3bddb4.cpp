#include <types.h>
#include <math.h>
#pragma force_active on

class fnA {
public:
    virtual void vf0();
    virtual void vf1(void*);
    virtual u64 vf2();

    u8 pad4;
    u8 pad5 : 1;
    u8 pad5rest : 7;
    u8 field6;
};

class fnB {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(f32, u32);
};

extern "C" void fn_27_3BDDB4(fnA* self, u32 unused, void* arg2) {
    if ((u32)(self->pad5 != 0) == 1 && self->field6 == 0) {
        self->vf1(arg2);
    }

    union {
        u64 bits;
        f32 f[2];
    } value;

    value.bits = self->vf2();
    f64 magnitude = fabs((f64)value.f[0]);
    fnB* obj = *(fnB**)(*(u8**)((u8*)arg2 + 0xD8) + 0x64);
    obj->vf13((f32)magnitude, 0x21000005);
}
