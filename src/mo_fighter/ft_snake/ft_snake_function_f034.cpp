#include <mt/mt_vector.h>
#include <so/so_null.h>
#pragma force_active on

class soModuleAccesser;
struct SnakeSpeed {
    float x;
    float y;
};

class SnakeEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual SnakeSpeed getSpeed();
};

extern "C" const float lbl_122_rodata_C;

extern "C" void fn_122_F034(Vec3f* result, SnakeEnergyView* energy) {
    SnakeSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_122_rodata_C;
}
