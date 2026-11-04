#pragma force_active on
struct Vec { float x, y, z; };
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C(int, int);
    char padding[0xd8];
    Vec pos;
};
struct Object { char padding[0x10]; Class_8042B6D0* obj; };
extern "C" void fn_800B6E08(Object* self, const Vec* v) {
    float x = v->x;
    float y = v->y;
    Class_8042B6D0* dest = self->obj;
    dest->pos.x = x;
    float z = v->z;
    dest->pos.y = y;
    dest->pos.z = z;
    Class_8042B6D0* obj = self->obj;
    obj->fn_801B269C(2, 0);
    obj->fn_801B269C(5, 0);
}