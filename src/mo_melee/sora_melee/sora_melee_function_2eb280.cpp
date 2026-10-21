#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void call();
};

struct Object {
    char padding[0x10];
    Interface member;
};

extern "C" void fn_27_2EB280(Object* self) {
    self->member.call();
}
