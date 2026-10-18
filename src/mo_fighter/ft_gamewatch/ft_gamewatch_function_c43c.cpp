#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

class GameWatchEnergyView {
public:
    virtual void update();
    virtual void updateEnergy(void*);
    virtual Vec2f getSpeed();
};

extern "C" const float lbl_107_rodata_C;

extern "C" void fn_107_C43C(float* result, GameWatchEnergyView* energy) {
    Vec2f speed = energy->getSpeed();
    result[0] = speed.x;
    result[1] = speed.y;
    result[2] = lbl_107_rodata_C;
}
