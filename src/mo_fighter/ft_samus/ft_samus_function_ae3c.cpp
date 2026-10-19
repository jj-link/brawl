#pragma force_active on
struct SamusSpeed {
    float x, y;
};

struct SamusVector {
    float x, y, z;
};

class soModuleAccesser;

class SamusSpeedEnergyView {
public:
    virtual ~SamusSpeedEnergyView();
    virtual void updateEnergy(soModuleAccesser*);
    virtual SamusSpeed getSpeed();
};

extern "C" const float lbl_94_rodata_C;

extern "C" void fn_94_AE3C(SamusVector* result, SamusSpeedEnergyView* energy) {
    SamusSpeed speed = energy->getSpeed();
    result->x = speed.x;
    result->y = speed.y;
    result->z = lbl_94_rodata_C;
}
