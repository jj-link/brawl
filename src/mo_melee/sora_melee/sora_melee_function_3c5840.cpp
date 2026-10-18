#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Work {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual float get(unsigned);
};

struct Model {
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual Vec3 get(int);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void set(int, const Vec3*);
};

struct Posture {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float get();
};

struct Owner {
    char pad[60];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual int kind();
};

struct Modules {
    char pad[4];
    Model* model;
    char pad8[4];
    Posture* posture;
    char pad10[0x54];
    Work* work;
};

struct Object {
    char pad[8];
    Owner* owner;
    char padC[0xcc];
    Modules* modules;
};

extern "C" const float lbl_27_rodata_8080[];

extern "C" void fn_27_3C5840(void*, Object* o) {
    const float* data = lbl_27_rodata_8080;
    float f = o->modules->work->get(0x21000006);
    int kind = o->owner->kind();
    int id = 4;
    if (kind == 5)
        id = 0x197;

    const Vec3& ar = o->modules->model->get(id);
    Vec3& a = const_cast<Vec3&>(ar);
    a.x = data[7] * f;
    o->modules->model->set(id, &a);

    kind = o->owner->kind();
    id = 4;
    if (kind == 5)
        id = 0x197;

    Vec3 b = o->modules->model->get(id);
    if (data[3] == o->modules->posture->get())
        b.y = data[4];
    else
        b.y = data[1];

    o->modules->model->set(id, &b);
}
