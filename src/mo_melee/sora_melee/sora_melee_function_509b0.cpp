#pragma force_active on
class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

class Outer {
public:
    int pad[4];
    Inner inner;
};

extern "C" {
void fn_27_509B0(Outer* p) {
    p->inner.v1();
}
}
