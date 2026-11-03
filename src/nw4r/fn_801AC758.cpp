#pragma force_active on
class Class_80466278 {
public:
    virtual void fn_801AC270();
    virtual void fn_801AB9D8(int, int, int);
    virtual void fn_801AC1AC();
    virtual void fn_801AC328();
    virtual void fn_801AC2F8();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    char padding[0x2884];
    Class_80466278* target;
};

extern "C" void fn_801AC758(Class_80466278* self) {
    if (self->target) {
        self->target->fn_801AAFE8();
    }
    self->fn_801AB9D8(8, 0, 0);
}