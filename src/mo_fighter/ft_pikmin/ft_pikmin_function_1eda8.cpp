#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct PikSpeed { float x, y; };
extern "C" {
extern const float lbl_113_rodata_90;
void fn_113_BC00(Vec2f* dst, const Vec2f* src);
}

class PikminKineticView : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(void*, int, int, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual void* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(void*, int);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual PikSpeed getSumSpeed(const short*);
};

extern "C" void fn_113_1EDA8(void*, unsigned char* energy, soModuleAccesser* accesser) {
    struct FlagArg {
        unsigned char padding[2];
        short value;
    } flag;
    flag.value = 1;

    Vec2f speed;
    PikSpeed sum = reinterpret_cast<PikminKineticView&>(
        accesser->getKineticModule()).getSumSpeed(&flag.value);
    Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&sum));

    accesser->getKineticModule().unableEnergyAll();

    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    flag.padding[1] = 0;

    Vec2f value1;
    Vec2f value2;
    Vec2f value3;
    Vec2f value4;

    value1.m_x = speed.m_x;
    value1.m_y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2f*>(energy + 0x18), &value1);

    value2.m_x = params->getParamFloat(accesser, 0xfc7, 0);
    value2.m_y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2f*>(energy + 0x28), &value2);

    value3.m_x = params->getParamFloat(accesser, 0xfc8, 0);
    value3.m_y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2f*>(energy + 0x30), &value3);

    value4.m_x = params->getParamFloat(accesser, 0xfc9, 0);
    value4.m_y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2f*>(energy + 0x38), &value4);

    energy[0x15] |= 0x80;
    flag.padding[0] = 0;
    *reinterpret_cast<float*>(energy + 0x58) = speed.m_y;
    *reinterpret_cast<float*>(energy + 0x5c) =
        -params->getParamFloat(accesser, 0xfd4, 0);
    *reinterpret_cast<float*>(energy + 0x60) =
        params->getParamFloat(accesser, 0xfd5, 0);
    energy[0x55] |= 0x80;
}