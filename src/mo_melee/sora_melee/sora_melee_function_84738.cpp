#pragma force_active on
class Dispatch {
public:
    virtual void first();
    virtual void invoke();
};

extern "C" void fn_27_84738(Dispatch* self) {
    self->invoke();
}
