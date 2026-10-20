#pragma force_active on
class Interface {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual int query();
};

struct Component {
    unsigned char padding[8];
    Interface interface;
};

struct Object {
    unsigned char padding[0x154];
    Component* component;
};

extern "C" bool fn_27_109BD4(Object* __restrict object) {
    return object->component->interface.query() != 0;
}
