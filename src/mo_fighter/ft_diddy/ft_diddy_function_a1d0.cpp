#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

struct DiddySpeed {
    f32 x;
    f32 y;
};

class DiddySpeedEnergyView {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual void reserved();
    virtual DiddySpeed getSpeed();
};

extern "C" const float lbl_115_rodata_C;

extern "C" void fn_115_A1D0(Vec3f* result, DiddySpeedEnergyView* energy) {
    DiddySpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_115_rodata_C;
}
