#pragma force_active on
struct Interface {
    virtual void first();
    virtual void second();
};

struct Object {
    char padding[16];
    Interface interface;
};

extern "C" void fn_27_1E6B4C(Object* object) {
    object->interface.second();
}
