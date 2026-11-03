#include <so/so_module_accesser.h>
#pragma force_active on
struct Object { char pad[0xd8]; soModuleEnumeration* modules; };
class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setup(int, Vec2f*, Vec3f*, Object*);
};
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_29510[];
extern "C" char lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_63AC;
extern "C" void fn_27_2DEE00(void*, Object* object) {
    Target* target = (Target*)__dynamic_cast(object->modules->m_kineticModule->getEnergy(0), 0, lbl_27_data_29510, lbl_27_data_CDF8, 1);
    int kind = object->modules->m_groundModule->isTouch((grCollStatus::TouchMask)8, 0) ? 2 : 4;
    Vec3f pos;
    pos.m_x = lbl_27_rodata_63AC;
    pos.m_y = lbl_27_rodata_63AC;
    pos.m_z = lbl_27_rodata_63AC;
    Vec2f size;
    size.m_x = lbl_27_rodata_63AC;
    size.m_y = lbl_27_rodata_63AC;
    target->setup(kind, &size, &pos, object);
}