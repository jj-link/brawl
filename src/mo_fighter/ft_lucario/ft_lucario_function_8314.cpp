#pragma force_active on
extern "C" void* fn_118_7E14(void*, void*, unsigned int, void*, unsigned int,
                            void*, unsigned int);

struct Work {
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
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
};

extern "C" void* fn_118_8314(void* object) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_118_7E14(storage + 0x1C0, object, 0x4D,
                 storage + 0x134, 0x20, storage + 0x1B4, 3);
    reinterpret_cast<Work*>(storage + 0x1C0)->method25();
    return object;
}
