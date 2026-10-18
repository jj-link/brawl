#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;
struct YoshiSpeed { float x, y; };

class YoshiEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual YoshiSpeed getSpeed();
};

extern "C" const float lbl_95_rodata_C;

extern "C" void fn_95_B724(Vec3f* result, YoshiEnergyView* energy) {
    YoshiSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_95_rodata_C;
}
