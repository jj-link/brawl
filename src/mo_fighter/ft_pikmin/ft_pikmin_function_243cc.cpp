#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_113_243CC(char* owner) {
    reinterpret_cast<Obj*>(owner + 0x80)->f3();
}
