#pragma force_active on
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Work {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual float get(int);
};

struct Model {
    char pad[8];
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual Vec get(int);
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void set(int, const Vec&);
};

struct Posture {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual float get();
};

struct Modules {
    char p[4];
    Model* model;
    void* u;
    Posture* posture;
    char q[0x54];
    Work* work;
};

struct Owner {
    char pad[0x3c];
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual int get();
};

struct Obj {
    char p[8];
    Owner* owner;
    char q[0xcc];
    Modules* modules;
};

extern const float lbl_27_rodata_8080[];

extern "C" void fn_27_3C6D50(void*, Obj* o) {
    const float* c = lbl_27_rodata_8080;
    float v = o->modules->work->get(0x21000006);

    int id;
    if (o->owner->get() == 5)
        id = 0x197;
    else
        id = 4;

    Vec a = o->modules->model->get(id);
    a.x = c[7] * v;
    o->modules->model->set(id, a);

    if (o->owner->get() == 5)
        id = 0x197;
    else
        id = 4;

    Vec b = o->modules->model->get(id);
    if (c[3] == o->modules->posture->get())
        b.y = c[4];
    else
        b.y = c[1];

    o->modules->model->set(id, b);
}
