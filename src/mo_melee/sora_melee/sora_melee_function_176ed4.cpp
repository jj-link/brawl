#include <so/posture/so_posture_module_simple.h>

#pragma force_active on

struct Outer {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float getValue(unsigned int id);
    virtual void setValue(unsigned int id, float value);
};

struct Modules {
    char pad0[0xC];
    soPostureModule* inner;
    char pad1[0x54];
    Outer* outer;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_176ED4(void* arg1, Object* obj, float target_x, float target_y) {
    Vec3f local = obj->modules->inner->getPos();

    float cur_x = obj->modules->outer->getValue(0x21000004);
    if (cur_x != target_x) {
        local.m_x += target_x - cur_x;
        obj->modules->outer->setValue(0x21000004, target_x);
    }

    float cur_y = obj->modules->outer->getValue(0x21000005);
    if (cur_y != target_y) {
        local.m_y += target_y - cur_y;
        obj->modules->outer->setValue(0x21000005, target_y);
    }

    obj->modules->inner->setPos(&local);
}
