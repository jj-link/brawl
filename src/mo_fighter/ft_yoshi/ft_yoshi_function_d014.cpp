#pragma force_active on
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_95_D014(char* p) {
    reinterpret_cast<Base*>(p + 0x21cd8)->v2();
}
