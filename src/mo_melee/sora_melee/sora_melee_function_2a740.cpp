#pragma force_active on
struct Vec2 { float x, y; };
struct Result { unsigned int unused; void* value; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Result* slot1(int);
};
struct Context { unsigned char padding[0x28]; Object_vptr_0* provider; };
extern "C" int fn_80136D14(void*, Vec2*, int);
extern "C" int fn_27_2A740(Context* context, Vec2* v, int kind, int arg) {
    if (kind == 0) {
        float b, a;
        a = v->x; b = v->y;
        Vec2 tmp;
        tmp.x = a;
        Object_vptr_0* p = context->provider;
        tmp.y = b;
        return fn_80136D14(p->slot1(arg)->value, &tmp, 1);
    } else if (kind == 1) {
        float b, a;
        a = v->x; b = v->y;
        Vec2 tmp;
        tmp.x = a;
        Object_vptr_0* p = context->provider;
        tmp.y = b;
        return fn_80136D14(p->slot1(arg)->value, &tmp, 0);
    } else if (kind == 2) {
        float b, a;
        a = v->x; b = v->y;
        Vec2 tmp;
        tmp.x = a;
        Object_vptr_0* p = context->provider;
        tmp.y = b;
        return fn_80136D14(p->slot1(arg)->value, &tmp, 3);
    }
    return 0;
}