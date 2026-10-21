#pragma force_active on
class Interface {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
};

struct Object {
    unsigned char padding[12];
    Interface member;
};

extern "C" void fn_27_D6FF8(Object* object) {
    object->member.method4();
}
