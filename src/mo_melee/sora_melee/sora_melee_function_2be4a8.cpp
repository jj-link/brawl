#pragma force_active on
typedef struct {
    float x;
    float y;
} Vec2;

typedef struct {
    int unk0;
    int unk4;
    float x;
    float y;
} Obj;

extern "C" void fn_27_2BE4A8(Obj* obj, Vec2* v) {
    Vec2 tmp;
    tmp.x = v->x;
    tmp.y = v->y;
    obj->x *= tmp.x;
    obj->y *= tmp.y;
}
