#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual f32 s12(u32 a, void* b);
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual u32 s17(u32 a);
};

struct Vec3 {
    f32 x, y, z;
};

class Position {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual Vec3 get();
};

extern "C" void* getInstance__16CameraControllerFv();
extern f32 lbl_27_rodata_7C8C;

extern "C" void fn_27_388A44(f32* self, void* unused, u8* arg) {
    Obj* obj = *(Obj**)(*(u8**)(arg + 0xD8) + 0x64);
    self[0] = obj->s12(0x11000013, arg);

    u8* cam = (u8*)getInstance__16CameraControllerFv();
    self[1] = *(f32*)(cam + 0x150);

    obj = *(Obj**)(*(u8**)(arg + 0xD8) + 0x64);
    u32 r = obj->s17(0x1200003F);
    if (r == 1) {
        self[2] = lbl_27_rodata_7C8C;
        return;
    }

    Position* n = *(Position**)(*(u8**)(arg + 0xD8) + 0xC);
    self[2] = n->get().z;
}
