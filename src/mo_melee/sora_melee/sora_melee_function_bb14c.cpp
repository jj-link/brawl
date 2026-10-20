#pragma force_active on
class itValueAccesser {
public:
    enum ParamInt { PARAM_DUMMY = 0 };
};

struct Filler {
    char pad[0x3c];
};

class BaseItem : public Filler {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35();
    virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43();
    virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47();
    virtual void f48(); virtual void f49(); virtual void f50(); virtual void f51();
    virtual void f52(); virtual void f53(); virtual void f54(); virtual void f55();
    virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
    virtual void f60(); virtual void f61(); virtual void f62(); virtual void f63();
    virtual void f64(); virtual void f65(); virtual void f66(); virtual void f67();
    virtual void f68(); virtual void f69(); virtual void f70(); virtual void f71();
    virtual void f72(); virtual void f73(); virtual void f74(); virtual void f75();
    virtual void f76(); virtual void f77(); virtual void f78(); virtual void f79();
    virtual void f80(); virtual void f81(); virtual void f82(); virtual void f83();
    virtual void f84(); virtual void f85(); virtual void f86(); virtual void f87();
    virtual void f88(); virtual void f89(); virtual void f90(); virtual void f91();
    virtual void f92(); virtual void f93(); virtual void f94(); virtual void f95();
    virtual void f96(); virtual void f97(); virtual void f98(); virtual void f99();
    virtual void f100(); virtual void f101(); virtual void f102(); virtual void f103();
    virtual void f104(); virtual void f105(); virtual void f106(); virtual void f107();
    virtual void f108(); virtual void f109(); virtual void f110(); virtual void f111();
    virtual void f112(); virtual void f113(); virtual void f114(); virtual void f115();
    virtual void f116(); virtual void f117(); virtual void f118(); virtual void f119();
    virtual void f120(); virtual void f121(); virtual void f122(); virtual void f123();
    virtual void f124(); virtual void f125(); virtual void f126(); virtual void f127();
    virtual void f128(); virtual void f129(); virtual void f130(); virtual void f131();
    virtual void f132(); virtual void f133(); virtual void f134(); virtual void f135();
    virtual void f136(); virtual void f137(); virtual void f138(); virtual void f139();
    virtual void f140(int);
    int getParam(itValueAccesser::ParamInt p);
};

struct X {
    int a;
    BaseItem* item;
};

struct B {
    virtual void f0();
    virtual X* f1(int);
};

struct C {
    int f0;
    int f4;
    int f8;
};

class A {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13();
    virtual unsigned int f14();
    char pad[52];
    B* b;
    C* c;
};

extern "C" {
void fn_27_BB14C(A* self, int p) {
    if (self->f14() == 1) {
        int v1 = self->b->f1(p)->item->getParam((itValueAccesser::ParamInt)0x5b69);
        int v2 = self->b->f1(p)->item->getParam((itValueAccesser::ParamInt)0x5bce);
        int r;
        if (v1 == 0) {
            if (v2 & 2) {
                r = self->c->f4;
            } else {
                r = self->c->f0;
            }
        } else {
            r = self->c->f8;
        }
        self->b->f1(p)->item->f140(r);
    }
}
}
