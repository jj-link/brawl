#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_100_data_6474[], lbl_100_data_16D4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct SpeedBits {
    u32 x;
    u32 y;
};

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

class CaptainEnergy {
public:
    virtual void v1();
    virtual void v2();
    virtual SpeedBits getSpeed();
    float pad;
    Vec2f speed;
};

extern "C" void fn_100_DB04(void*, soModuleAccesser* accesser) {
    Object_vptr_0* obj = *(Object_vptr_0**)((unsigned char*)*(void**)((unsigned char*)accesser + 0xD8) + 0x7C);
    void* p = obj->slot6(0);
    CaptainEnergy* e = (CaptainEnergy*)__dynamic_cast(p, 0, lbl_100_data_6474, lbl_100_data_16D4, 1);
    float limit = soValueAccesser::getConstantFloat(accesser, 0xbd0, 0);
    SpeedBits t;
    SpeedBits s = e->getSpeed();
    t = s;
    if (*(float*)&t.y < -limit) {
        *(float*)&t.y = -limit;
        e->speed.m_x = *(float*)&t.x;
        e->speed.m_y = (float)(-(double)limit);
    }
}
