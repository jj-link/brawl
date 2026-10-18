#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" void fn_116_213E4(void* self) {
    reinterpret_cast<Obj*>(static_cast<char*>(self) + 0x10000 + 0xb68)->f2();
}
