#include <so/so_null.h>
#pragma force_active on

class soModuleAccesser;
struct FalcoSpeed {
    float x;
    float y;
};

class FalcoEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual FalcoSpeed getSpeed();
};

struct FalcoResult {
    float x;
    float y;
    float z;
};

extern "C" const float lbl_108_rodata_8;

extern "C" void fn_108_B08C(FalcoResult* result, FalcoEnergyView* energy) {
    FalcoSpeed speed = energy->getSpeed();
    result->x = speed.x;
    result->y = speed.y;
    result->z = lbl_108_rodata_8;
}
