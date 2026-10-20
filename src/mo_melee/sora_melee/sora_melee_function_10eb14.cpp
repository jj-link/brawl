#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Outer {
    unsigned int unk0;
    unsigned int unk4;
    Inner* inner;
};

extern "C" void fn_27_10EB14(Outer* p) {
    p->inner->f4();
}
