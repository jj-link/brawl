#pragma force_active on
class soVirtIface {
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
};

extern "C" void fn_27_F086C(soVirtIface* p) {
    ((soVirtIface*)((char*)p + 0x10))->f8();
}
