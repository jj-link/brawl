#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/model/so_model_module_simple.h>
#pragma force_active on

struct LucasEnergySpeed {
    float x;
    float y;
};

class LucasEnergySpeedView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual LucasEnergySpeed getSpeed();
};

extern "C" {
float fn_114_B6DC(float, float);
extern const float lbl_114_rodata_64;
}

extern "C" void fn_114_11668(void*, soModuleAccesser* accesser) {
    soKineticModule& kinetic = accesser->getKineticModule();
    soPostureModule& posture = accesser->getPostureModule();
    soModelModule& model = accesser->getModelModule();

    Vec2f speed;
    LucasEnergySpeed raw =
        reinterpret_cast<LucasEnergySpeedView*>(kinetic.getEnergy(3))->getSpeed();
    __memcpy(&speed, &raw, sizeof(speed));

    float angle = fn_114_B6DC(speed.m_y, speed.m_x * posture.getLr());
    model.setNodeRotateZ(3, lbl_114_rodata_64 * angle);
}
