#pragma force_active on
extern "C" void fn_99_7288(void*, void*, int, void*, int, void*, int);

struct ModuleData {
    unsigned char data[8];
};

class Module : public ModuleData {
public:
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
    virtual void initialize();
};

extern "C" void* fn_99_7788(unsigned char* self) {
    fn_99_7288(self + 0x1C0, self, 0x4D, self + 0x134,
               0x20, self + 0x1B4, 3);
    reinterpret_cast<Module*>(self + 0x1C0)->initialize();
    return self;
}
