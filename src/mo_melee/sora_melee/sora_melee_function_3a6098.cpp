#include <so/so_module_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

struct Object {
    char pad[0xD8];
    soModuleEnumeration* modules;
};

class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void setup(int, Vec2f*, Vec3f*, Object*);
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_29510[];
extern "C" char lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_7EE4;

extern "C" void fn_27_3A6098(void*, Object* object) {
    Target* target = (Target*)__dynamic_cast(
        object->modules->m_kineticModule->getEnergy(0), 0,
        lbl_27_data_29510, lbl_27_data_CDF8, 1);
    int kind = object->modules->m_groundModule->isTouch((grCollStatus::TouchMask)8, 0) ? 2 : 4;
    Vec3f pos;
    Vec2f size;
    pos.m_x = lbl_27_rodata_7EE4;
    pos.m_y = lbl_27_rodata_7EE4;
    pos.m_z = lbl_27_rodata_7EE4;
    size.m_x = lbl_27_rodata_7EE4;
    size.m_y = lbl_27_rodata_7EE4;
    target->setup(kind, &size, &pos, object);
}
