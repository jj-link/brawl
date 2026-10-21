#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void call();
};

struct Object {
    char padding[16];
    Interface member;
};

extern "C" void fn_27_11B1A8(Object* self) {
    self->member.call();
}
