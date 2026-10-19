#pragma force_active on
class Interface {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual int method4();
};

extern "C" bool fn_41_C568(Interface* object) {
    return object->method4() == 0;
}
