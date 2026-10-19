#pragma force_active on
struct Vec2f {
    float x, y;
};

struct Vec3f {
    float x, y, z;
};

class Source {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Vec2f getPos();
};

extern float lbl_41_rodata_C9C;

extern "C" void fn_41_1F500(Vec3f* out, Source* source) {
    Vec2f pos = source->getPos();
    out->x = pos.x;
    out->y = pos.y;
    out->z = lbl_41_rodata_C9C;
}
