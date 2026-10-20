#pragma force_active on
struct ObjectBase {
    unsigned char padding[0x3C];
};

struct Object : ObjectBase {
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
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
};

struct Stage {
    unsigned char padding[0x1040];
    Object* object;
};

extern "C" void fn_82_3D00(Stage* stage) {
    stage->object->method27();
}
