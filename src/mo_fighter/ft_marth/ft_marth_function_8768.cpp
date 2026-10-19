#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Object {
    char padding[0x7fb8];
    Interface member;
};

extern "C" void fn_106_8768(Object* object) {
    object->member.f2();
}
