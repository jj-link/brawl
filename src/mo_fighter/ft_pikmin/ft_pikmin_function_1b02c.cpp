#pragma force_active on
class CompB {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
    virtual void f5(int, int);
};

class CompA {
public:
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
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59(int);
};

struct Inner {
    char pad[0x1c];
    CompA* comp_a;
    char pad2[0x44];
    CompB* comp_b;
};

struct Mid {
    char pad[0xd8];
    Inner* inner;
};

struct Outer {
    char pad[0x60];
    Mid* mid;
};

extern "C" void fn_113_1B02C(Outer* a) {
    int c = 0x1000000D;
    CompB* b = a->mid->inner->comp_b;
    int result = b->f4(c);
    if (result < 0) return;
    CompA* ca = a->mid->inner->comp_a;
    ca->f59(0);
    CompB* b2 = a->mid->inner->comp_b;
    b2->f5(-1, c);
}
