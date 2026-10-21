#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void second();
    virtual void call();
};

struct Object {
    unsigned char padding[8];
    Interface member;
};

extern "C" void fn_27_51FA4(Object* object) {
    object->member.call();
}
