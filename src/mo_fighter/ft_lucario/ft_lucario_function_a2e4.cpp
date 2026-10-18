#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual Vec2 get();
};

extern "C" const float lbl_118_rodata_C;

extern "C" void fn_118_A2E4(Vec3* out, Interface* object) {
    Vec2 value = object->get();
    out->x = value.x;
    out->y = value.y;
    out->z = lbl_118_rodata_C;
}
