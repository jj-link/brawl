#pragma force_active on
extern "C" int fn_800B61C0(void*);

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050();
    virtual void fn_801B3248(void* p);
};

struct Inner {
    char pad0[0x10];
    void* field10;
};

struct Outer {
    Class_8042B6D0* obj;
    Inner* inner;
    char pad8[0xDC - 0x8];
    int fieldDC;
};

extern "C" int fn_8010582C(Outer* self) {
    Inner* inner = self->inner;
    if (fn_800B61C0(inner) != 0) {
        self->obj->fn_801B3248(inner->field10);
        return 0;
    }
    return self->fieldDC;
}
