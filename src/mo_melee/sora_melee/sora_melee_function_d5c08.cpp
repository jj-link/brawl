#pragma force_active on
struct Dispatch {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void target();
};

extern "C" void fn_27_D5C08(void* object) {
    reinterpret_cast<Dispatch*>(static_cast<char*>(object) + 12)->target();
}
