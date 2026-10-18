#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct Vec2f {
    float x, y;
};

struct EnergyView {
    virtual void f0();
    virtual void f1();
    virtual Vec2f get();
};

extern "C" const float lbl_119_rodata_1C;

extern "C" void fn_119_9144(Vec3f* result, EnergyView* energy) {
    Vec2f v = energy->get();
    result->x = v.x;
    result->y = v.y;
    result->z = lbl_119_rodata_1C;
}
