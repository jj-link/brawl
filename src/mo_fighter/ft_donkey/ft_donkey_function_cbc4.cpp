#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

struct DonkeySpeed {
    float x, y;
};

class DonkeyKineticView {
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
    virtual DonkeySpeed getSumSpeed(const short&);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_92_BA0C(Vec2f*, const Vec2f*);
extern const char lbl_92_data_639C[], lbl_92_data_1874[], lbl_92_data_62B8[];
extern const float lbl_92_rodata_10;
}

extern "C" void fn_92_CBC4(void*, soModuleAccesser* accesser)
{
    soSituationModule* situation = &accesser->getSituationModule();
    soKineticModule* kinetic = &accesser->getKineticModule();

    float* params = *(float**)((char*)g_ftCommonDataAccesser.getData(static_cast<ftKind>(1)) + 0x80);

    short one = 1;
    char* gravity = (char*)__dynamic_cast(kinetic->getEnergy(1), 0, lbl_92_data_639C, lbl_92_data_1874, one);
    char* stop = (char*)__dynamic_cast(kinetic->getEnergy(3), 0, lbl_92_data_62B8, lbl_92_data_1874, one);

    short mask = -1;
    Vec2f speed;
    DonkeySpeed returnedSpeed = ((DonkeyKineticView*)kinetic)->getSumSpeed(mask);
    __memcpy(&speed, &returnedSpeed, sizeof(speed));

    if (situation->getKind() == 0) {
        kinetic->changeKinetic(6, accesser);
    } else {
        kinetic->changeKinetic(10, accesser);
        speed.m_x /= params[0];
        speed.m_y = lbl_92_rodata_10;
        fn_92_BA0C((Vec2f*)(stop + 8), &speed);

        Vec2f temp;
        temp.m_x = params[1];
        temp.m_y = lbl_92_rodata_10;
        fn_92_BA0C((Vec2f*)(stop + 0x20), &temp);

        *(float*)(gravity + 0xc) = lbl_92_rodata_10;
        *(float*)(gravity + 0x10) = -params[2];
        gravity[5] &= 0xFFFFFF7F;
    }
}
