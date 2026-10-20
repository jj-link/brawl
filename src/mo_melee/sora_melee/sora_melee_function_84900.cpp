#pragma force_active on
class fnBase {
public:
    virtual void fn0();
    virtual void fn1();
};

extern "C" void fn_27_84900(fnBase* self) {
    self->fn1();
}
