#pragma force_active on
class ZeldaIface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void callback();
};

extern "C" void fn_104_13298(char* owner) {
    reinterpret_cast<ZeldaIface*>(owner + 0x17f8)->callback();
}
