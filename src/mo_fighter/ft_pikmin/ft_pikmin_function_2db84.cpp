#pragma force_active on
struct WorkModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int getInt(int);
    virtual void setInt(int, int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void setFloat(int, float);
};
struct ModuleTable { char pad[0x64]; WorkModule* work; };
struct ModuleOwner { char pad[0xD8]; ModuleTable* modules; };
extern "C" void fn_27_1DE288(void*, ModuleOwner*);
extern float lbl_113_rodata_1B0;
extern "C" void fn_113_2DB84(void* self, ModuleOwner* owner) {
    fn_27_1DE288(self, owner);
    int v = owner->modules->work->getInt(0x10000007);
    owner->modules->work->setInt(v, 0x20000002);
    float f = (float)v * lbl_113_rodata_1B0;
    owner->modules->work->setFloat(0x21000001, f);
}
