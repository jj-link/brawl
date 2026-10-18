#include <so/so_null.h>
#pragma force_active on

class soModuleAccesser;

struct ZakoSpeed {
    float x;
    float y;
};

class ZakoEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual ZakoSpeed getSpeed();
};

struct ZakoVec3 {
    float x;
    float y;
    float z;
};

extern "C" const float lbl_126_rodata_8;

extern "C" void fn_126_73D8(ZakoVec3* result, ZakoEnergyView* energy) {
    ZakoSpeed speed = energy->getSpeed();
    result->x = speed.x;
    result->y = speed.y;
    result->z = lbl_126_rodata_8;
}
