#pragma force_active on
struct FoxSpeed {
    float x;
    float y;
};

class FoxEnergyView {
public:
    virtual void updateEnergy();
    virtual void unused();
    virtual FoxSpeed getSpeed();
};

extern "C" const float lbl_97_rodata_8;

extern "C" void fn_97_B1E8(float* result, FoxEnergyView* energy) {
    FoxSpeed speed = energy->getSpeed();
    result[0] = speed.x;
    result[1] = speed.y;
    result[2] = lbl_97_rodata_8;
}
