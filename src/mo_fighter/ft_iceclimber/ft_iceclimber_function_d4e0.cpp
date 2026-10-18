#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

class IceClimberEnergyView {
public:
    virtual void updateEnergy();
    virtual Vec2f getSpeed();
    virtual Vec2f getSpeedAgain();
};

extern "C" const float lbl_105_rodata_10;

extern "C" void fn_105_D4E0(Vec3f* result, IceClimberEnergyView* energy) {
    Vec2f speed = energy->getSpeedAgain();
    result->x = speed.x;
    result->y = speed.y;
    result->z = lbl_105_rodata_10;
}
