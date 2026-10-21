#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void target();
};

struct Object {
    char padding[0x10];
    Interface member;
};

extern "C" void fn_27_FA7BC(Object* self) {
    self->member.target();
}
