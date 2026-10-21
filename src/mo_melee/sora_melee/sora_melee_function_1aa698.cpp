#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Object {
    char padding[12];
    Interface part;
};

extern "C" void fn_27_1AA698(Object* object) {
    object->part.f4();
}
