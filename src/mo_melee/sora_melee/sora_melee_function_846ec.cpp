#pragma force_active on
class Interface {
public:
    virtual void unused();
    virtual void invoke();
};

extern "C" void fn_27_846EC(Interface* self) {
    self->invoke();
}
