#pragma force_active on
class Interface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void invoke();
};

struct Object {
    unsigned char padding[0x10];
    Interface interface;
};

extern "C" void fn_27_1B1618(Object* object) {
    object->interface.invoke();
}
