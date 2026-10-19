#pragma force_active on
typedef struct Vec2f {
    float x;
    float y;
} Vec2f;

typedef struct ScaleObj {
    char pad[0x10];
    float sx;
    float sy;
} ScaleObj;

extern "C" void fn_27_2BE4DC(ScaleObj *obj, const Vec2f *v)
{
    Vec2f tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    obj->sx *= tmp.x;
    obj->sy *= tmp.y;
}
