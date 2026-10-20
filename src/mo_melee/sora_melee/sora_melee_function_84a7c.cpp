#pragma force_active on
class soVirtualBase {
public:
    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
};

extern "C" void fn_27_84A7C(soVirtualBase* p) {
    p->func1();
}
