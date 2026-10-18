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

extern "C" const float lbl_99_rodata_8;

struct Vec2Source {
    virtual void unused0();
    virtual void unused1();
    virtual Vec2f get();
};

extern "C" void fn_99_898C(Vec3f* out, Vec2Source* source) {
    Vec2f value = source->get();
    out->x = value.x;
    out->y = value.y;
    out->z = lbl_99_rodata_8;
}
