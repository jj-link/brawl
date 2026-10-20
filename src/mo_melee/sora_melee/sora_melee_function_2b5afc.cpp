#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

struct Holder {
    char pad[8];
    Vec2f v;
};

struct Pair {
    unsigned int a;
    unsigned int b;
};

union Conv {
    Vec2f f;
    Pair p;
};

extern "C" Pair fn_27_2B5AFC(Holder* h) {
    Conv c;
    c.f.y = h->v.y;
    c.f.x = h->v.x;
    return c.p;
}
