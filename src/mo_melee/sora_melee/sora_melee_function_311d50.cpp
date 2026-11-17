#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Tmp {
    int x, y, z;
    Tmp() {}
    Tmp(const Tmp& t) : x(t.x), y(t.y), z(t.z) {}
};

struct Msg {
    int type;
    char flag;
    int mode;
    int x, y, z;
    float value;
};

#define V10(a) \
    virtual void a##0(); \
    virtual void a##1(); \
    virtual void a##2(); \
    virtual void a##3(); \
    virtual void a##4(); \
    virtual void a##5(); \
    virtual void a##6(); \
    virtual void a##7(); \
    virtual void a##8(); \
    virtual void a##9();

class Obj70 {
public:
    V10(a)
    V10(b)
    V10(c)
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void op(int, void*);
};

class Obj54 {
public:
    V10(a)
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void op(int, void*);
};

class ObjC {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void setTmp(const Tmp*);
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual Vec3 get(int);
    virtual void set(const Vec3*, int);
};

struct Mods {
    char p0[12];
    ObjC* c;
    char p1[0x44];
    Obj54* a;
    char p2[0x18];
    Obj70* b;
};

struct OwnerBase {
    char pad[0x3c];
};

class Owner : public OwnerBase {
public:
    V10(a)
    V10(b)
    V10(c)
    V10(d)
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void update();
};

struct Self {
    char p0[8];
    Owner* owner;
    char p1[0xcc];
    Mods* modules;
};

inline void finishPose(Self* self, const Msg& m, Vec3 v, Tmp t) {
    v.x = m.value;
    self->modules->c->setTmp(&t);
    self->modules->c->set(&v, 0);
}

extern "C" void fn_27_311D50(Self* self, int arg1, unsigned int arg2) {
    int n;
    if (arg2 == 1)
        n = 2;
    else if (arg1 == 2)
        n = 1;
    else
        n = 0;

    self->modules->b->op(n, self);

    if (arg2 == 1) {
        Msg m;
        m.type = 0x455;
        m.flag = 0;
        m.mode = 3;
        self->modules->a->op(3, &m);
        finishPose(self, m, self->modules->c->get(0), *(Tmp*)&m.x);
    } else {
        Msg m;
        m.type = 0x455;
        m.flag = 0;
        m.mode = 1;
        self->modules->a->op(3, &m);
        finishPose(self, m, self->modules->c->get(0), *(Tmp*)&m.x);
    }

    self->owner->update();
}
