#pragma force_active on
class fnVirtualBase {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
};

extern "C" {
void fn_27_69748(fnVirtualBase* self) {
    self->f3();
}
}
