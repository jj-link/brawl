#pragma force_active on
extern "C" {
extern const float lbl_98_rodata_8;

struct Vec2 {
    float x;
    float y;
};

class Obj {
public:
    virtual void a();
    virtual void b();
    virtual Vec2 c();
};

void fn_98_9F24(float* dest, Obj* src) {
    Vec2 v = src->c();
    dest[0] = v.x;
    dest[1] = v.y;
    dest[2] = lbl_98_rodata_8;
}
}
