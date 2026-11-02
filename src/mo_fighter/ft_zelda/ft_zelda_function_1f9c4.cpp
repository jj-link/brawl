#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#pragma force_active on

struct ZeldaSpeed {
    float x, y;
};

class ZeldaKineticView {
public:
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
    virtual void slot12();
    virtual ZeldaSpeed getSumSpeed(const short&);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_104_CDE4(Vec2f*, const Vec2f*);
extern const char lbl_104_data_72B4[];
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
extern const float lbl_104_rodata_180;
}

extern "C" void fn_104_1F9C4(void*, soModuleAccesser* accesser) {
    soSituationModule* situation = &accesser->getSituationModule();
    soKineticModule* kinetic = &accesser->getKineticModule();

    char* params = *(char**)((char*)
        g_ftCommonDataAccesser.getData(static_cast<ftKind>(14)) + 0x84);

    short mask = 1;
    char* gravity = (char*)__dynamic_cast(
        kinetic->getEnergy(1), 0,
        lbl_104_data_72B4, lbl_104_data_2404, mask);
    char* stop = (char*)__dynamic_cast(
        kinetic->getEnergy(3), 0,
        lbl_104_data_7138, lbl_104_data_2404, mask);

    Vec2f speed;
    ZeldaSpeed returnedSpeed = ((ZeldaKineticView*)kinetic)->getSumSpeed((short)mask);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));

    if (situation->getKind() == 0) {
        kinetic->changeKinetic(6, accesser);
        speed.m_x *= *(float*)(params + 0x28);
        speed.m_y = lbl_104_rodata_180;
        fn_104_CDE4((Vec2f*)(stop + 8), &speed);
    } else {
        kinetic->changeKinetic(10, accesser);
        speed.m_x *= *(float*)(params + 0x28);
        speed.m_y *= *(float*)(params + 0x28);
        *(float*)(gravity + 0xc) = speed.m_y;
        speed.m_y = lbl_104_rodata_180;
        fn_104_CDE4((Vec2f*)(stop + 8), &speed);
    }
}
