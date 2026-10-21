#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void target();
};

struct Object {
    char padding[16];
    Interface member;
};

extern "C" void fn_27_2931FC(Object* self) {
    self->member.target();
}
