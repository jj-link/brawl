#pragma force_active on
typedef unsigned char u8;

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class Outer {
public:
    u8 pad[0xc];
    Inner inner;
};

extern "C" {
void fn_27_D6178(Outer* p) {
    p->inner.vf4();
}
}
