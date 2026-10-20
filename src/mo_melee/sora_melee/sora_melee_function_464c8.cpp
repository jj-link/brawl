#pragma force_active on
struct Object {
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
    virtual void method11(int);
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19(int, int);
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38(int);
};

struct Event {
    unsigned int reserved[3];
    unsigned int flags;
};

extern "C" void fn_27_464C8(Object* self, void*, void*, const Event* event) {
    if (((event->flags >> 7) & 1) == 0) {
        self->method11(0);
        self->method19(0, 0);
        self->method38(0);
    }
}
