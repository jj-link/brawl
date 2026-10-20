#pragma force_active on
struct V2 {
    float x, y;
};

struct V3 {
    float x, y, z;

    V3(const V3& p) : x(p.x), y(p.y), z(p.z) {}
};

struct Data {
    char pad[0x3C];
    V3 pos;
};

struct Obj {
    int pad;
    Data* data;
};

extern "C" int fn_10_DC38(V2*);

inline V2 make(float x, float y) {
    V2 a;
    a.y = y;
    a.x = x;
    return a;
}

extern "C" void fn_10_1C514(Obj* o) {
    V3 p(o->data->pos);
    V2 b = make(p.x, p.y);
    fn_10_DC38(&b);
}
