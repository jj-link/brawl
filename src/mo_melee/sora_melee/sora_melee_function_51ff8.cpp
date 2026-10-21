#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Object {
    unsigned char padding[8];
    Interface member;
};

extern "C" void fn_27_51FF8(Object* object) {
    object->member.f4();
}
