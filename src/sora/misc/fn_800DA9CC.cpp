#pragma force_active on
class Class_804664C0 {
public:
    virtual void fn_801B4A50();
    virtual void fn_801B45A0();
    virtual void fn_801B4918();
    virtual void fn_801B4AE8();
    virtual void fn_801B4AB8();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AAA70();
    virtual void fn_801ABE70();
    virtual void fn_801ABFFC();
    virtual void fn_801AC0B8(void*);
};
struct Self {
    char pad[0x54];
    void* field54;
    Class_804664C0* field58;
    int field5c;
};
extern "C" void fn_801B4CB0(void*, void*, int);
extern "C" void fn_800DA9CC(Self* self, int flag) {
    self->field58->fn_801AC0B8(self->field54);
    if (flag) {
        fn_801B4CB0(self->field58, self->field54, self->field5c);
    }
}