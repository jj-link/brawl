#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, int, bool, Vec2f*);
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5(Vec3f*);
};

struct Modules {
    char pad[0xc];
    Object_vptr_0* posture;
    char pad2[0x4c - 0x10];
    Object_vptr_0* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Access* access;
};

struct Param {
    char pad[8];
    float x;
    float y;
};

extern "C" const float lbl_105_rodata_BC;
extern "C" const float lbl_105_rodata_B4;

extern "C" void fn_105_1B97C(Fighter* self, Param* p) {
    if (!(p->x <= lbl_105_rodata_BC)) {
        float f = p->x * soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(self->access), 0xfa0, 0);

        Vec3f v = reinterpret_cast<soModuleAccesser*>(self->access)->getPostureModule().getPos();
        v.m_y -= f;
        self->access->modules->posture->slot5(&v);

        if (p->y > lbl_105_rodata_BC) {
            Vec2f a(lbl_105_rodata_BC, lbl_105_rodata_B4);
            Object_vptr_0* obj = self->access->modules->other;
            int i = soValueAccesser::getConstantInt(
                reinterpret_cast<soModuleAccesser*>(self->access), 0x5dc3, 0);
            obj->slot2(0, i, false, &a);
        }
    }
}
