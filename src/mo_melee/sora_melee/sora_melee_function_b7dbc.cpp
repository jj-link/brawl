#pragma force_active on
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

typedef struct Holder {
    char pad[8];
    Vec2 v;
} Holder;

extern "C" {
Vec2 fn_27_B7DBC(Holder *self)
{
    Vec2 tmp;
    tmp.y = self->v.y;
    tmp.x = self->v.x;
    return tmp;
}
}
