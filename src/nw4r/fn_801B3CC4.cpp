#pragma force_active on
extern unsigned char lbl_8040ABF8[];
class Class_804664C0 {
public:
    virtual int fn_801B4A50(void*);
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
    char pad[0xe4];
    int value;
};
class Class_80466418 {
public:
    virtual void fn_801B3BDC();
    virtual int fn_801B35D0(Class_804664C0*, int, int);
    virtual void fn_801B3C80();
    virtual void fn_801B3C74();
    virtual void fn_801B3C44();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual int fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AAA70();
    virtual void fn_801ABE70();
    virtual int fn_801ABFFC(int);
};
struct Self {
    void* vtable;
    Class_80466418* first;
    Class_80466418* second;
};
extern "C" int fn_801B3CC4(Self* self, Class_804664C0* arg, int a, int b) {
    if (!self->second->fn_801AAFDC())
        return self->second->fn_801B35D0(arg, a, b);
    Class_80466418* inner = self->second;
    bool matches = false;
    if (arg) {
        unsigned char* type = lbl_8040ABF8;
        if (arg->fn_801B4A50(&type))
            matches = true;
    }
    Class_804664C0* cast = matches ? arg : 0;
    bool found = false;
    if (cast && inner->fn_801ABFFC(cast->value))
        found = true;
    if (found)
        return 0;
    return self->first->fn_801B35D0(arg, a, b);
}