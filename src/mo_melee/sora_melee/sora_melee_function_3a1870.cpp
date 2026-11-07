#pragma force_active on
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>

class KineticView {
public:
    virtual void isNull();
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
    virtual void slot12();
    virtual Vec2f slot13(short*);
};

class EnergyView {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, Vec2f*, Vec3f*, soModuleAccesser*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    char pad[12];
    Vec2f accel;
    Vec2f brake;
    Vec2f limit;
    void setAccel(const Vec2f& v) { accel.m_x = v.m_x; accel.m_y = v.m_y; }
    void setBrake(const Vec2f& v) { brake.m_x = v.m_x; brake.m_y = v.m_y; }
    void setLimit(const Vec2f& v) { limit.m_x = v.m_x; limit.m_y = v.m_y; }
    void enable() { ((unsigned char*)this)[5] |= 0x80; }
    void disable() { ((signed char*)this)[5] &= ~0x80; }
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7E90;
}
extern "C" void fn_27_3A1870(void*, soModuleAccesser* a) {
    const soModuleEnumeration* e = a->m_enumerationStart;
    soWorkManageModule* work = e->m_workManageModule;
    soSituationModule* situation = e->m_situationModule;
    int prev = work->getInt(0x20000002);
    int kind = situation->getKind();
    if (kind == prev) return;
    EnergyView* stop = (EnergyView*)__dynamic_cast(a->m_enumerationStart->m_kineticModule->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    EnergyView* gravity = (EnergyView*)__dynamic_cast(a->m_enumerationStart->m_kineticModule->getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    short mask = 1;
    Vec2f speed;
    __memcpy(&speed, &((KineticView*)a->m_enumerationStart->m_kineticModule)->slot13(&mask), sizeof(speed));
    float limit = fn_27_192278(a, 0xFA1);
    if (a->m_enumerationStart->m_situationModule->getKind() == 2) {
        stop->slot5(6, &Vec2f(speed.m_x, lbl_27_rodata_7E90), &Vec3f(lbl_27_rodata_7E90, lbl_27_rodata_7E90, lbl_27_rodata_7E90), a);
        stop->setAccel(Vec2f(lbl_27_rodata_7E90, lbl_27_rodata_7E90));
        stop->setLimit(Vec2f(limit, lbl_27_rodata_7E90));
        stop->setBrake(Vec2f(lbl_27_rodata_7E90, lbl_27_rodata_7E90));
        stop->enable();
        gravity->slot5(0, &Vec2f(lbl_27_rodata_7E90, speed.m_y), &Vec3f(lbl_27_rodata_7E90, lbl_27_rodata_7E90, lbl_27_rodata_7E90), a);
        gravity->enable();
        a->m_enumerationStart->m_workManageModule->setInt(2, 0x20000002);
    } else {
        stop->slot5(0, &Vec2f(speed.m_x, lbl_27_rodata_7E90), &Vec3f(lbl_27_rodata_7E90, lbl_27_rodata_7E90, lbl_27_rodata_7E90), a);
        stop->setBrake(Vec2f(lbl_27_rodata_7E90, lbl_27_rodata_7E90));
        stop->enable();
        gravity->disable();
        a->m_enumerationStart->m_workManageModule->setInt(0, 0x20000002);
    }
}
