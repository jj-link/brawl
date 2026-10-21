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

extern "C" void fn_27_1C8B8C(Object* object) {
    object->member.target();
}
