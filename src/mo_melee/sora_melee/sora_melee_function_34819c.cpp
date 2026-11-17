#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* posture;
    char pad1[0x54];
    Object_vptr_0* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    char pad[8];
    float x;
    float y;
};

inline float deltaY(Accesser* accesser) {
    Object_vptr_0* workY = accesser->modules->work;
    return workY->slot12(0x21000005) - accesser->modules->posture->slot4().m_y;
}

extern "C" float lbl_27_rodata_78C4;

extern "C" void fn_27_34819C(Self* self, void*, Accesser* accesser) {
    float y = deltaY(accesser);
    Object_vptr_0* work = accesser->modules->work;
    float x = work->slot12(0x21000004) - accesser->modules->posture->slot4().m_x;
    Vec2f delta(x, y);
    float s = lbl_27_rodata_78C4 - soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xfda, 0);
    delta.m_x *= s;
    delta.m_y *= s;
    self->x = delta.m_x;
    self->y = delta.m_y;
}