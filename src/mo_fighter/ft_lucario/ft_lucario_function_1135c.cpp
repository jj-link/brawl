#pragma force_active on

extern "C" float* fn_118_8DF0(float*, float, float, float);
extern "C" const float lbl_118_rodata_98;

class Comp {
public:
    virtual ~Comp();
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
    virtual float get(int id);
    virtual void set(int id, float value);
};

class BaseP {
public:
    int m_a;
    int m_b;
};

class Obj : public BaseP {
public:
    virtual ~Obj();
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
    virtual void m31(int, float*);
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual int m35(int);
};

struct Inner {
    char pad0[4];
    Obj* obj;
    char pad8[0x5c];
    Comp* comp;
};

struct Outer {
    char pad0[0xd8];
    Inner* inner;
};

inline Comp* getComp(Inner* inner, Obj*& obj) {
    Comp* comp = inner->comp;
    obj = inner->obj;
    return comp;
}

extern "C" void fn_118_1135C(Outer* arg0) {
    Inner* inner = arg0->inner;
    Obj* obj;
    Comp* comp = getComp(inner, obj);
    float val = comp->get(0x21000004);
    int r = obj->m35(0x12e);
    float arr[3];
    obj->m31(r, fn_118_8DF0(arr, val, lbl_118_rodata_98,
                          lbl_118_rodata_98));
}
