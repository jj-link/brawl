#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Object {
    unsigned char padding[0x10];
    Interface member;
};

extern "C" void fn_27_D9E34(Object* object) {
    object->member.f3();
}
