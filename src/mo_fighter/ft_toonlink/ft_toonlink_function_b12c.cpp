#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

struct ToonLinkSpeed {
    float x;
    float y;
};

class ToonLinkSpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual ToonLinkSpeed getSpeed();
};

extern "C" const float lbl_121_rodata_C;

extern "C" void fn_121_B12C(Vec3f* result, ToonLinkSpeedEnergyView* energy) {
    ToonLinkSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_121_rodata_C;
}
