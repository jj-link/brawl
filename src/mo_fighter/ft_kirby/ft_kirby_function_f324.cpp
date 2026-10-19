#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct KirbySpeed {
    float x, y;
};

class soModuleAccesser;

class KirbySpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual KirbySpeed getSpeed();
};

extern "C" const float lbl_96_rodata_8;

extern "C" void fn_96_F324(Vec3f* result, KirbySpeedEnergyView* energy) {
    KirbySpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_96_rodata_8;
}
