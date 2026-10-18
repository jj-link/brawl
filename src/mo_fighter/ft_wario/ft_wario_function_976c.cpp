#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

struct WarioSpeed {
    float x;
    float y;
};

class WarioSpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual WarioSpeed getSpeed();
};

extern "C" const float lbl_110_rodata_8;

extern "C" void fn_110_976C(Vec3f* result, WarioSpeedEnergyView* energy) {
    WarioSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_110_rodata_8;
}
