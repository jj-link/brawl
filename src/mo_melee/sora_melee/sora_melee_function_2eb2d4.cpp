#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void target();
};

struct Object {
    char padding[0x10];
    Interface member;
};

extern "C" void fn_27_2EB2D4(Object* self) {
    self->member.target();
}
