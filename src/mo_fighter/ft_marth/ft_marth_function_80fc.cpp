#pragma force_active on
extern const float lbl_106_rodata_8;

struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

class Source {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Vec2f getPos();
};

extern "C" void fn_106_80FC(Vec3f* out, Source* source) {
    Vec2f pos = source->getPos();
    out->x = pos.x;
    out->y = pos.y;
    out->z = lbl_106_rodata_8;
}
