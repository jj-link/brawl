#include <so/so_null.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soModuleAccesser;

struct LinkSpeed {
    float x;
    float y;
};

class LinkEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual LinkSpeed getSpeed();
};

extern "C" const float lbl_93_rodata_C;

extern "C" void fn_93_B130(Vec3f* result, LinkEnergyView* energy) {
    LinkSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_93_rodata_C;
}
