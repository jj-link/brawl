#pragma force_active on
class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

struct Outer {
    unsigned int pad[4];
    Inner inner;
};

extern "C" {
void fn_27_295364(Outer* p) {
    Inner* in = &p->inner;
    in->vf13();
}
}
