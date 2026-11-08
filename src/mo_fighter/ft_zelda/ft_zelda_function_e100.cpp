#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#pragma force_active on

struct ZeldaSpeed {
    unsigned int x;
    unsigned int y;
};

class KineticView {
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
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
extern const char lbl_104_data_72B4[];
extern const float lbl_104_rodata_18;
}

extern "C" void fn_104_E100(void*, soModuleAccesser* accesser) {
    soSituationModule* situation = &accesser->getSituationModule();
    soKineticModule* kinetic = &accesser->getKineticModule();

    if (situation->getKind() == 0) {
        kinetic->clearSpeedAll();
        return;
    }

    float* params = *(float**)((char*)g_ftCommonDataAccesser.getData(
        static_cast<ftKind>(0xD)) + 0x84);

    char* stop = (char*)__dynamic_cast(
        kinetic->getEnergy(3), 0, lbl_104_data_7138, lbl_104_data_2404, 1);

    char* gravity = (char*)__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_104_data_72B4, lbl_104_data_2404, 1);

    short allMask = -1;
    ZeldaSpeed speed;
    ZeldaSpeed sum = ((KineticView*)kinetic)->getSumSpeed(allMask);
    speed = sum;
    float* values = (float*)&speed;

    kinetic->clearSpeedAll();

    values[0] /= params[0];
    values[1] /= params[1];

    *(float*)(gravity + 0xC) = values[1];
    gravity[5] |= 0x80;

    Vec2f newSpeed;
    newSpeed.m_x = values[0];
    newSpeed.m_y = lbl_104_rodata_18;
    *(float*)(stop + 8) = newSpeed.m_x;
    *(float*)(stop + 0xC) = newSpeed.m_y;
    stop[5] |= 0x80;
}
