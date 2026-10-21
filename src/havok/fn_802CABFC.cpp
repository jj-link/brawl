#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f7(void* a, void* b, void* c);
};

struct Holder {
    void* vptr;
    Inner* inner;
};

struct Args {
    void* a;
    void* b;
    void* c;
};

extern "C" int fn_802CABFC(Args arg0, Holder* arg1, int arg2) {
    arg1->inner->f7(arg0.a, arg0.b, arg0.c);
    return arg2;
}
