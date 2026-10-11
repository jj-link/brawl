#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiGravitySpeed { float x, y; };
// Individual energy speed uses the original two-register POD return ABI.
class LuigiGravityEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual LuigiGravitySpeed getSpeed();
};
extern "C" {
extern const float lbl_99_rodata_10;
}

extern "C" void fn_99_C914(soKineticEnergy* energy, soModuleAccesser* accesser) {
    switch (accesser->getKineticModule().getKineticType()) {
    case 0x6a: {
        float impulse = accesser->getWorkManageModule().getFloat(0x21000005);
        if (impulse > lbl_99_rodata_10) {
            Vec2f speed;
            LuigiGravitySpeed returnedSpeed = reinterpret_cast<LuigiGravityEnergyView*>(energy)->getSpeed();
            __memcpy(&speed, &returnedSpeed, sizeof(speed));
            speed.m_y += impulse;
            if (speed.m_y > soValueAccesser::getConstantFloat(accesser, 0xfc2, 0))
                speed.m_y = soValueAccesser::getConstantFloat(accesser, 0xfc2, 0);
            *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x0c) = speed.m_y;
        }
        break;
    }
    case 0x66:
        if (accesser->getWorkManageModule().isFlag(0x22000014) == true)
            *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(energy) + 0x10) =
                -soValueAccesser::getConstantFloat(accesser, 0xfb8, 0);
        break;
    default:
        break;
    }
    energy->updateEnergy(accesser);
}

extern "C" void fn_99_CA80(void*) {}
