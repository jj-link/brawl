#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct ZeldaSpeed {
    float x, y;
};

class ZeldaEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual ZeldaSpeed getSpeed();
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern const char lbl_104_data_72B4[];
extern const char lbl_104_data_7138[];
extern const char lbl_104_data_2404[];
extern const float lbl_104_rodata_180;
extern const float lbl_104_rodata_184;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_104_CDE4(Vec2f*, const Vec2f*);
}

extern "C" void fn_104_1FB70(void*, soModuleAccesser* accesser) {
    Vec2f speed;
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soSituationModule* situation = &accesser->getSituationModule();
    soKineticModule* kinetic = &accesser->getKineticModule();

    char* params = *(char**)((char*)
        getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 14) + 0x84);

    char* gravity = (char*)__dynamic_cast(
        kinetic->getEnergy(1), 0,
        lbl_104_data_72B4, lbl_104_data_2404, 1);

    char* stop = (char*)__dynamic_cast(
        kinetic->getEnergy(3), 0,
        lbl_104_data_7138, lbl_104_data_2404, 1);

    if (situation->getKind() == 2) {
        if (work->isFlag(0x22000011)) {
            float scale = soValueAccesser::getConstantFloat(accesser, 0xbd8, 0);
            Vec2f value(
                scale * *(float*)(params + 0x20),
                lbl_104_rodata_180);
            fn_104_CDE4((Vec2f*)(stop + 0x28), &value);
            gravity[6] = 0;
        } else {
            ZeldaSpeed returnedSpeed = ((ZeldaEnergyView*)gravity)->getSpeed();
            __memcpy(&speed, &returnedSpeed, sizeof(speed));
            speed.m_y -= speed.m_y / lbl_104_rodata_184;
            *(float*)(gravity + 0xc) = speed.m_y;
            gravity[6] = 1;
        }
    }
}
