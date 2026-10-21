#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};

extern "C" void fn_27_3197C4(void* object) {
    reinterpret_cast<Interface*>(static_cast<char*>(object) + 0x10)->f13();
}
