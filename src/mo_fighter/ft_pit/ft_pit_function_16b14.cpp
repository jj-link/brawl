#pragma force_active on
class PitObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

extern "C" void fn_112_16B14(char* owner) {
    reinterpret_cast<PitObj*>(owner + 0x175c)->f6();
}
