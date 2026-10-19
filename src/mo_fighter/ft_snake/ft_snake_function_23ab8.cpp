#pragma force_active on
class SnakeObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

extern "C" void fn_122_23AB8(char* owner) {
    reinterpret_cast<SnakeObj*>(owner + 0x14cc)->f6();
}
