#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

struct KoopaSpeed {
    float x;
    float y;
};

class KoopaEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual KoopaSpeed getSpeed();
};

extern "C" const float lbl_102_rodata_8;

extern "C" void fn_102_907C(Vec3f* result, KoopaEnergyView* energy) {
    KoopaSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_102_rodata_8;
}
