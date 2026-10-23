#pragma force_active on

extern "C" void fn_27_1744D4(void*, void*);
extern "C" void fn_27_174C08(void*, void*, void*);

struct Out {
    int a, b;
    float x, y, z, p, q, r, s;
};

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Position {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3 get();
    virtual void set(const Vec3*);
};

#define PAD10(n) \
    virtual void n##0(); \
    virtual void n##1(); \
    virtual void n##2(); \
    virtual void n##3(); \
    virtual void n##4(); \
    virtual void n##5(); \
    virtual void n##6(); \
    virtual void n##7(); \
    virtual void n##8(); \
    virtual void n##9();

struct Owner {
    char pad[0x3c];
    PAD10(a)
    PAD10(b)
    PAD10(c)
    PAD10(d)
    virtual void o40();
    virtual void o41();
    virtual void o42();
    virtual void update();
};

#undef PAD10

struct Modules {
    char pad[0xc];
    Position* pos;
};

struct Actor {
    char pad0[8];
    Owner* owner;
    char pad1[0xd8 - 0xc];
    Modules* modules;
};

extern "C" void fn_27_178034(void* a, Actor* b) {
    Out out;
    fn_27_1744D4(a, b);
    out.a = 0x17;
    out.b = 0;
    fn_27_174C08(a, &out, b);

    Vec3 v = b->modules->pos->get();
    v.x = out.x;
    v.y = out.y;
    b->modules->pos->set(&v);
    b->owner->update();
}
