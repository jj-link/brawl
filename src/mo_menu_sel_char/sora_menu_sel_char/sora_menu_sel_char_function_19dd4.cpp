#pragma force_active on
extern "C" int fn_10_14620(void*, int);

class Class_148 {
public:
    virtual void fn_10_3F4();
    virtual void fn_10_BD70();
    virtual void fn_10_BD50();
    virtual void fn_10_BD30();
    virtual void fn_10_BD10();
    virtual void fn_10_BCF0(float);
};

struct Menu {
    char pad0[0x4C];
    Class_148* animation;
    char pad50[0x4C];
    void* state;
};

extern "C" void fn_10_19DD4(Menu* self) {
    self->animation->fn_10_BCF0(
        (float)fn_10_14620(self->state, 1)
    );
}
