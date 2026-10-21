#pragma force_active on

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

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Actor;

struct Status {
    PAD10(s)
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int kind();
};

struct Gate {
    virtual void g0();
    virtual int test(Actor*);
};

struct Work {
    char pad[8];
    PAD10(w0)
    PAD10(w1)
    PAD10(w2)
    PAD10(w3)
    PAD10(w4)
    virtual void* get(int);
    PAD10(w5)
    PAD10(w6)
    PAD10(w7)
    PAD10(w8)
    PAD10(w9)
    PAD10(w10)
    PAD10(w11)
    PAD10(w12)
    PAD10(w13)
    PAD10(w14)
    virtual Gate* gate();
};

struct Position {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3 get();
    virtual void set(const Vec3*);
};

struct Owner {
    char pad[0x3c];
    PAD10(o0)
    PAD10(o1)
    PAD10(o2)
    PAD10(o3)
    virtual void o40();
    virtual void o41();
    virtual void o42();
    virtual void update();
};

#undef PAD10

struct Modules {
    char pad0[0xc];
    Position* pos;
    Work* work;
    char pad1[0x70 - 0x14];
    Status* status;
};

struct Actor {
    char pad0[8];
    Owner* owner;
    char pad1[0xd8 - 0xc];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_25E8;
void fn_801348D8(void*, Vec3*, float);

void fn_27_18E528(void*, Actor* actor) {
    if (actor->modules->status->kind() == 0x7c) {
        if (actor->modules->work->gate()->test(actor) == 0) {
            Vec3 pos = actor->modules->pos->get();
            Vec3 out;
            void* value = actor->modules->work->get(0);
            fn_801348D8(value, &out, lbl_27_rodata_25E8);
            pos.x = out.x;
            pos.y = out.y;
            actor->modules->pos->set(&pos);
            actor->owner->update();
        }
    }
}
}
