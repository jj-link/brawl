#pragma force_active on

struct V3 { float x, y, z; };

#define PAD8(n) virtual void a##n##0(); virtual void a##n##1(); virtual void a##n##2(); virtual void a##n##3(); virtual void a##n##4(); virtual void a##n##5(); virtual void a##n##6(); virtual void a##n##7();

class Sub4v {
public:
    char pad[8];
    PAD8(0)
    PAD8(1)
    PAD8(2)
    PAD8(3)
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual V3 getPos(int, int);
};

class Rate {
public:
    PAD8(0)
    virtual void a0();
    virtual float get();
};

class Own {
public:
    char pad[0x3c];
    PAD8(0)
    PAD8(1)
    PAD8(2)
    PAD8(3)
    PAD8(4)
    virtual int kind();
};

class A { public: virtual void v0(); virtual void v1(); virtual void* call(void*); };
class B { public: virtual void v0(); virtual void v1(); virtual void* call(); };

struct Mods {
    char p0[4];
    Sub4v* s4;
    char p1[4];
    Rate* rate;
    char p2[8];
    A* a;
};

struct Ctx {
    char p[8];
    Own* owner;
    char p2[0xcc];
    Mods* m;
};

extern "C" float fn_27_192278(void*, unsigned long);
extern "C" void fn_27_371BEC(int, void*, void*, V3*, int, int, float, float);
extern const float lbl_27_rodata_7B88;

extern "C" int fn_27_36E158(int a, int b, Ctx* c, int d) {
    float f31 = fn_27_192278(c, 0xfa0);
    float f30 = c->m->rate->get();
    V3 pos;
    if (c->owner->kind() == 5) {
        pos = c->m->s4->getPos(0x19b, 0);
    } else {
        pos = c->m->s4->getPos(0x21, 0);
    }
    pos.y += fn_27_192278(c, 0xfa1);
    pos.z = lbl_27_rodata_7B88;
    void* r31 = *(void**)((char*)c->owner + 0x28);
    void* r = c->m->a->call(c->owner);
    r = ((B*)r)->call();
    fn_27_371BEC(b, r31, r, &pos, -1, d, f30, f31);
    return 0;
}
