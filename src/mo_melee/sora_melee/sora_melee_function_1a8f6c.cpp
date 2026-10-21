#pragma force_active on
class Interface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void invoke();
};

struct Object {
    char padding[12];
    Interface interface;
};

extern "C" void fn_27_1A8F6C(Object* object) {
    object->interface.invoke();
}
