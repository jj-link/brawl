#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/model/so_model_module_simple.h>

struct NessEnergySpeed { float x; float y; };
// The original kinetic energy speed uses a two-register POD return, unlike
// the shared vector class's return ABI.
class NessEnergySpeedView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual NessEnergySpeed getSpeed();
};

extern "C" {
float fn_101_BD7C(float, float);
extern const float lbl_101_rodata_5C;
}

extern "C" void fn_101_1203C(void*, soModuleAccesser* accesser) {
    soKineticModule& kinetic = accesser->getKineticModule();
    soPostureModule& posture = accesser->getPostureModule();
    soModelModule& model = accesser->getModelModule();
    Vec2f speed;
    NessEnergySpeed raw = reinterpret_cast<NessEnergySpeedView*>(kinetic.getEnergy(3))->getSpeed();
    __memcpy(&speed, &raw, sizeof(speed));
    float angle = fn_101_BD7C(speed.m_y, speed.m_x * posture.getLr());
    model.setNodeRotateZ(5, lbl_101_rodata_5C * angle);
}
