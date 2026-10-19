#pragma force_active on
typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y; } Vec2;

struct Sub {
    char pad[0x3c];
    Vec3 pos;
};

struct Obj {
    int id;
    Sub* sub;
};

struct Pair {
    Vec2 t;
    Vec3 v;
};

extern "C" Vec2 fn_10_1BC38(Obj* o)
{
    Pair p;
    p.t.x = o->sub->pos.x;
    p.t.y = o->sub->pos.y;
    p.v.x = o->sub->pos.x;
    p.v.y = o->sub->pos.y;
    p.v.z = o->sub->pos.z;
    return p.t;
}
