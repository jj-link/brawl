#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

struct Src {
    int pad0;
    int pad1;
    float x;
    float y;
};

extern "C" {
Vec2 fn_27_8B194(const Src *s) {
    Vec2 v;
    v.y = s->y;
    v.x = s->x;
    return v;
}
}
