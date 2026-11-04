#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
};
class Class_80466320 {
public:
    virtual void fn_801ADE54();
    virtual void fn_801AC4A8(int, int, Class_8042B6D0*);
    virtual void fn_801AD064();
    virtual void fn_801ADEEC();
    char pad[0xe4];
    Class_8042B6D0* inner;
};
extern "C" void fn_801ACD50(Class_80466320* self) {
    self->inner->fn_8004810C();
    self->fn_801AC4A8(0x10004, 0, self->inner);
}
