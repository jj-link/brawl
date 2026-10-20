#pragma force_active on
class Inner27 {
public:
    Inner27() { }
    virtual ~Inner27() { }
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void fn();
};

class Outer27 {
public:
    char pad[16];
    Inner27 inner;
    Outer27() { }
    virtual ~Outer27();
    virtual void w0();
    virtual void w1();
    virtual void w2();
};

extern "C" void fn_27_1BCE90(Outer27* a) {
    a->inner.fn();
}
