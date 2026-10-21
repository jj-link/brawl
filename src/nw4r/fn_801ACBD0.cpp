#pragma force_active on
class Base {
public:
    virtual void v0();
    virtual void target(int a, int b, int c);
};

extern "C" void fn_801ACBD0(Base* self) {
    self->target(3, 0, 0);
}
