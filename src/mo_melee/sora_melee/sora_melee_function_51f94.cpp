#pragma force_active on
class Interface {
public:
    virtual void unused();
    virtual void invoke();
};

struct Object {
    unsigned char padding[8];
    Interface interface;
};

extern "C" void fn_27_51F94(Object* object) {
    object->interface.invoke();
}
