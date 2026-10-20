#pragma force_active on
struct Interface {
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void call(signed short);
};

struct Object {
    unsigned int padding[2];
    Interface* interface;
};

extern "C" void fn_27_1B17E8(Object* object, int value) {
    object->interface->call(static_cast<signed short>(value));
}
