#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

class EnergyView {
public:
    virtual void update();
    virtual void padding();
    virtual Vec2f getSpeed();
};

extern "C" const float lbl_109_rodata_8;

extern "C" void fn_109_90F0(Vec2f* result, EnergyView* energy) {
    Vec2f speed = energy->getSpeed();
    result->x = speed.x;
    result->y = speed.y;
    *(float*)((char*)result + 8) = lbl_109_rodata_8;
}
