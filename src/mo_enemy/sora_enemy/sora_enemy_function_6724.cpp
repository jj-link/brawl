#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern const float lbl_41_rodata_18;

class fnVirtBase {
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
    virtual void vf13(float f, u32 p);
};

struct fnSub {
    char pad[0x64];
    fnVirtBase* unk64;
};

struct fnOuter {
    char pad[0x1b4];
    fnSub* unk1b4;
};

extern "C" void fn_41_6724(fnOuter* self, float* p, u32 p2) {
    fnSub* sub = self->unk1b4;
    fnVirtBase* obj = sub->unk64;
    float f31 = p[0];
    float f1 = soValueAccesser::getValueFloat(
        reinterpret_cast<soModuleAccesser*>(reinterpret_cast<char*>(self) + 0xdc), 0x1100000C, 0);
    if (lbl_41_rodata_18 != p[1]) {
        f31 = f31 + p[1] * f1;
    }
    obj->vf13(f31, p2);
}
