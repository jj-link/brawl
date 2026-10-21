#pragma force_active on
class Object {
public:
    virtual void unused();
    virtual void invoke();
};

extern "C" void fn_27_8481C(Object* self) {
    self->invoke();
}
