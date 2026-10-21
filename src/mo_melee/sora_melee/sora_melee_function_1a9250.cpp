#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void target();
};

struct Object {
    unsigned char padding[12];
    Interface member;
};

extern "C" void fn_27_1A9250(Object* object) {
    object->member.target();
}
