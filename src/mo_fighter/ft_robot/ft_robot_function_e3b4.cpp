#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct RobotSpeed {
    float x, y;
};

class RobotEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual RobotSpeed getSpeed();
};

extern "C" {
extern const char lbl_120_data_6FE4[], lbl_120_data_2208[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_120_BDBC(Vec2f*, const Vec2f*);
}

extern "C" void fn_120_E3B4(void*, soModuleAccesser* accesser) {
    if (accesser->getGroundModule().isTouch(2, 0) ||
        accesser->getGroundModule().isTouch(4, 0)) {
        RobotEnergyView* energy = static_cast<RobotEnergyView*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(2), 0,
            lbl_120_data_6FE4, lbl_120_data_2208, 1));

        Vec2f speed;
        RobotSpeed returnedSpeed = energy->getSpeed();
        __memcpy(&speed, &returnedSpeed, sizeof(speed));
        speed.m_x = -speed.m_x *
            soValueAccesser::getConstantFloat(accesser, 0xfcb, 0);

        fn_120_BDBC(
            reinterpret_cast<Vec2f*>(
                reinterpret_cast<unsigned char*>(energy) + 8),
            &speed);
    }
}
