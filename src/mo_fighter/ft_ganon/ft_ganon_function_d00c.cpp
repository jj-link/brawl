#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

extern "C" {
extern const char lbl_109_data_6530[], lbl_109_data_1670[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_109_D00C(void* arg0, float farg0, float farg1) {
    char* base = reinterpret_cast<char*>(arg0);
    Object_vptr_0* holder = *reinterpret_cast<Object_vptr_0**>(*reinterpret_cast<char**>(base + 0xd8) + 0x7c);
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(holder->slot6(1), 0, lbl_109_data_6530, lbl_109_data_1670, 1));
    Vec2f speed = energy->getSpeed();
    Vec3f rot2;
    Vec3f rot = energy->getRotation();
    rot2.m_x = rot.m_x;
    rot2.m_y = rot.m_y;
    rot2.m_z = rot.m_z;
    energy->resetEnergy(0, &speed, &rot2, reinterpret_cast<soModuleAccesser*>(arg0));
    char* e = reinterpret_cast<char*>(energy);
    *reinterpret_cast<float*>(e + 0x10) = -farg0;
    *reinterpret_cast<float*>(e + 0x1c) = farg1;
    *reinterpret_cast<float*>(e + 0x14) = farg1;
    e[5] |= 0x80;
}
