#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf10(int) = 0;
    virtual int vf11(int) = 0;
};

struct Mid {
    char pad[0x54];
    Inner* inner;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_18F5E8(void* unused, Obj* obj, int id) {
    if (id != 0xf8) {
        if (obj->mid->inner->vf11(4)) {
            obj->mid->inner->vf10(4);
        }
    }
}
