#include <so/so_null.h>
#include <mt/mt_vector.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

class soModuleAccesser;

// The energy getter returns its trivial two-float result in r3/r4.
class DededeSpeedEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual DededeSpeed getSpeed();
};

extern "C" const float lbl_117_rodata_C;

extern "C" void fn_117_A5B4(Vec3f* result, DededeSpeedEnergyView* energy) {
    DededeSpeed speed = energy->getSpeed();
    result->m_x = speed.x;
    result->m_y = speed.y;
    result->m_z = lbl_117_rodata_C;
}
