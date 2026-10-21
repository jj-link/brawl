#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

#define VIRTUAL4(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3();
#define VIRTUAL16(p) \
    VIRTUAL4(p##a) VIRTUAL4(p##b) VIRTUAL4(p##c) VIRTUAL4(p##d)

struct Model {
    char pad[8];
    VIRTUAL16(a)
    VIRTUAL16(b)
    VIRTUAL4(c)
    virtual Vec3 get(int, int);
};

struct Scale {
    char pad[8];
    VIRTUAL16(a)
    VIRTUAL16(b)
    VIRTUAL16(c)
    VIRTUAL16(d)
    VIRTUAL16(e)
    VIRTUAL16(f)
    VIRTUAL4(g)
    VIRTUAL4(h)
    VIRTUAL4(i)
    virtual void j0();
    virtual void j1();
    virtual void j2();
    virtual float get();
};

struct Motion {
    VIRTUAL4(a)
    VIRTUAL4(b)
    virtual void c0();
    virtual float get();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual int get();
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual Work* get();
};

#undef VIRTUAL16
#undef VIRTUAL4

struct Modules {
    char pad[4];
    Model* model;
    char pad8[4];
    Motion* motion;
    Scale* scale;
    char pad14[4];
    Status* status;
};

struct Owner {
    char pad[0x28];
    int value;
};

struct Object {
    char pad[8];
    Owner* owner;
    char padC[0xcc];
    Modules* modules;
};

extern "C" void fn_27_2DD698(int, int, int, int, Vec3*, int, float);

extern "C" int fn_27_2D9204(void*, int a, Object* object, int b, int node) {
    Vec3 pos = object->modules->model->get(node, 0);
    pos.z = object->modules->scale->get();
    Status* status = object->modules->status;
    int value = object->owner->value;
    float f = object->modules->motion->get();
    Work* work = status->get();
    int result = work->get();
    fn_27_2DD698(a, value, b, result, &pos, 0, f);
    return 0;
}
