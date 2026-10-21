#pragma force_active on
struct Object;

struct Interface {
    unsigned char padding[8];
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method(Object*);
};

struct Object {
    unsigned char padding[0x8D0];
    Interface* interface;
};

extern "C" void fn_27_288704(Object* object) {
    object->interface->method(object);
}
