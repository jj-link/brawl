#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_4610;

struct Vec3 {
    float x, y, z;
};

class Position {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Vec3 getPosition();
};

class Work {
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
    virtual float getValue(u32 id);
};

class Owner {
public:
    u8 pad0[0xdb4];
    Position position;
    u8 pad1[0x2aac - 0xdb8];
    Work work;
    u8 pad2[0x3d50 - 0x2ab0];
    Vec3 saved;

    bool useSaved() {
        return work.getValue(0x1100000d) >= lbl_27_rodata_4610;
    }
};

extern "C" Vec3 fn_27_28E968(Owner* owner) {
    if (owner->useSaved())
        return owner->saved;
    return owner->position.getPosition();
}
