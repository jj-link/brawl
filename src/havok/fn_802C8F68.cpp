#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
};
class Class_804871B0 {
public:
    virtual void fn_802CA8B8(int);
    virtual void fn_80080A64();
    virtual void fn_802CA48C();
    virtual void fn_802CA51C();
    virtual void fn_802CA32C();
    virtual void fn_802CA70C();
    virtual void fn_802C8F68();
    char pad[8];
    Class_8042B6D0* inner;
};
extern "C" void fn_802C8F68(Class_804871B0* self) {
    self->inner->fn_801B269C();
    if (self) {
        self->fn_802CA8B8(1);
    }
}
