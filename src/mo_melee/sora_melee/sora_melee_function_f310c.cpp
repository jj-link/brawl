#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void second();
};

struct Object {
    unsigned char padding[16];
    Interface member;
};

extern "C" void fn_27_F310C(Object* object) {
    object->member.second();
}
