#pragma force_active on
struct Vec {
    float x, y, z;
    Vec() {}
};

class Work {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual float get(int);
};

struct OwnerBase {
    char pad[0x3c];
};

class Owner : public OwnerBase {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28();
    virtual void o29();
    virtual void o30();
    virtual void o31();
    virtual void o32();
    virtual void o33();
    virtual void o34();
    virtual void o35();
    virtual void o36();
    virtual void o37();
    virtual void o38();
    virtual void o39();
    virtual int kind();
};

class Empty {};

class Nullable {
public:
    virtual bool isNull();
    bool null;
};

class Model : private Empty, public Nullable {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual Vec get(int);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void set(int, const Vec&);
};

class Posture {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual float lr();
};

struct Modules {
    char pad[4];
    Model* model;
    char pad2[4];
    Posture* posture;
    char pad3[0x54];
    Work* work;
};

struct Fighter {
    char pad[8];
    Owner* owner;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" const float lbl_27_rodata_8080[];

extern "C" void fn_27_3C0D34(void*, Fighter* obj) {
    const float* constants = lbl_27_rodata_8080;
    float value = obj->modules->work->get(0x21000006);

    int kind = obj->owner->kind();
    int id = 4;
    if (kind == 5)
        id = 0x197;

    Vec a = obj->modules->model->get(id);
    a.x = constants[7] * value;
    obj->modules->model->set(id, a);

    kind = obj->owner->kind();
    id = 4;
    if (kind == 5)
        id = 0x197;

    Vec b = obj->modules->model->get(id);
    if (constants[3] == obj->modules->posture->lr())
        b.y = constants[4];
    else
        b.y = constants[1];

    obj->modules->model->set(id, b);
}
