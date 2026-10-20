#pragma force_active on
struct Ret {
    int a;
    int b;
};

struct Inner {
    virtual void f0();
    virtual Ret* f1();
};

struct Outer {
    int pad[4];
    Inner inner;
};

extern "C" int fn_27_2EABE8(Outer* p) {
    Inner* ip = &p->inner;
    return ip->f1()->b;
}
