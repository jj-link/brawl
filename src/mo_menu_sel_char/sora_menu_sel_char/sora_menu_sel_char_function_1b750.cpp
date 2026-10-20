#pragma force_active on
struct V2 { float x, y; };
struct Obj { char pad[0x90]; V2 v; };
extern "C" int fn_10_DC38(V2*);
inline V2 make(float x, float y) {
    V2 a;
    a.y = y;
    a.x = x;
    return a;
}
extern "C" void fn_10_1B750(Obj* o) {
    float y = o->v.y;
    float x = o->v.x;
    V2 b = make(x, y);
    fn_10_DC38(&b);
}
