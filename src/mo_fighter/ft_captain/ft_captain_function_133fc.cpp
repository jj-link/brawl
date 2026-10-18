#pragma force_active on
// Virtual dispatch thunk: forwards to the vtable slot at offset 0x40 on the same object.
class ftCaptainVirtualDispatch {
public:
    virtual void fn0() = 0;
    virtual void fn1() = 0;
    virtual void fn2() = 0;
    virtual void fn3() = 0;
    virtual void fn4() = 0;
    virtual void fn5() = 0;
    virtual void fn6() = 0;
    virtual void fn7() = 0;
    virtual void fn8() = 0;
    virtual void fn9() = 0;
    virtual void fn10() = 0;
    virtual void fn11() = 0;
    virtual void fn12() = 0;
    virtual void fn13() = 0;
    virtual void fn14() = 0;
    virtual void fn15() = 0;
    virtual void fn16() = 0;
};

extern "C" void fn_100_133FC(ftCaptainVirtualDispatch* self) {
    self->fn14();
}
