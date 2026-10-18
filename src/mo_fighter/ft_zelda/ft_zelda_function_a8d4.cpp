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

class ZeldaEnergyView {
public:
    virtual void updateEnergy();
    virtual void unused();
    virtual Vec2f getPosition();
};

extern "C" const float lbl_104_rodata_8;

extern "C" void fn_104_A8D4(Vec3f* result, ZeldaEnergyView* energy) {
    Vec2f position = energy->getPosition();
    result->x = position.x;
    result->y = position.y;
    result->z = lbl_104_rodata_8;
}
