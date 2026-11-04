#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_41_rodata_18;

class VirtBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14(f32 a, f32 b, s32 c);
};

struct Sub {
    char pad[0x64];
    VirtBase* ptr;
};

struct Outer {
    char pad[0x1B4];
    Sub* sub;
};

extern "C" void fn_41_68EC(Outer* self, f32* fp, s32 s, u32 unused) {
    Sub* sub = self->sub;
    VirtBase* obj = sub->ptr;
    f32 x = fp[0];
    f32 y = fp[2];
    f32 mul = soValueAccesser::getValueFloat(
        reinterpret_cast<soModuleAccesser*>(reinterpret_cast<char*>(self) + 0xDC), 0x1100000C, 0);
    if (lbl_41_rodata_18 != fp[1]) {
        x = x + fp[1] * mul;
    }
    if (lbl_41_rodata_18 != fp[3]) {
        y = y + fp[3] * mul;
    }
    if (x > y) {
        y = x;
    }
    obj->m14(x, y, s);
}
