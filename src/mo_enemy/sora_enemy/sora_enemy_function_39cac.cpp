#pragma force_active on
#define V(n) virtual void f##n();
#define T10(a) V(a##0) V(a##1) V(a##2) V(a##3) V(a##4) V(a##5) V(a##6) V(a##7) V(a##8) V(a##9)

struct A {
    T10(0) T10(1) T10(2) T10(3) T10(4) T10(5) T10(6) T10(7)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86)
    virtual void g(int);
};

struct B {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    virtual void g(int);
};

struct C {
    V(0) V(1) V(2)
    virtual void g5(float*);
    V(4) V(5) V(6) V(7) V(8)
    virtual void g11();
    virtual void g12();
};

struct DPad { char pad[0x3C]; };
struct D : DPad {
    T10(0) T10(1) T10(2) T10(3)
    V(40) V(41) V(42)
    virtual void g();
};

struct E {
    T10(0) V(10) V(11) V(12)
    virtual void g(int);
};

struct M {
    char pad[0x54];
    A* a;
};

struct P {
    char pad[8];
    D* d;
    char pad2[0xCC];
    M* m;
};

struct R {
    char pad[0x0C];
    C* c;
    char pad2[0x44];
    B* b;
    char pad3[0x0C];
    E* e;
};

struct Obj {
    char pad[0x60];
    P* p;
    char pad2[0x150];
    R* r;
};

struct V2 { float x, y; };

extern "C" {
void* getInstance__9itManagerFv();
void* getItemFromInstanceId__9itManagerFi(void*, int);
float getParamFloat__8BaseItemFUl(void*, unsigned long);
void fn_41_15A00(V2*);
extern float lbl_41_rodata_ECC;

int fn_41_39CAC(Obj* obj, int id) {
    obj->p->m->a->g(1);
    obj->r->b->g(4);
    void* it = getItemFromInstanceId__9itManagerFi(getInstance__9itManagerFv(), id);

    float v[3];
    v[0] = getParamFloat__8BaseItemFUl(it, 3);
    v[1] = getParamFloat__8BaseItemFUl(it, 4);
    v[2] = lbl_41_rodata_ECC;

    obj->r->c->g5(v);
    obj->p->d->g();
    getParamFloat__8BaseItemFUl(it, 8);
    obj->r->c->g12();

    V2 w;
    w.x = getParamFloat__8BaseItemFUl(it, 0x16);
    w.y = getParamFloat__8BaseItemFUl(it, 0x17);

    obj->r->c->g11();

    V2 u = w;
    fn_41_15A00(&u);

    obj->r->e->g(0x11000004);
    return 1;
}
}