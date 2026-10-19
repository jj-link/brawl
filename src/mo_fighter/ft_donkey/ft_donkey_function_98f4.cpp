#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct DonkeySpeed {
    float x, y;
};

class soModuleAccesser;

class DonkeySpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DonkeySpeed getSpeed();
};

extern "C" const float lbl_92_rodata_8;

extern "C" void fn_92_98F4(Vec3f* result, DonkeySpeedEnergyView* energy) {
    DonkeySpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_92_rodata_8;
}
