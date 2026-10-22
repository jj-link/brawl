#pragma force_active on
struct Sub2 {
    virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
    virtual int a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19(int, int);
    virtual void a20();
    virtual int a21();
};
struct In { char pad[0xBD]; char f; };
struct Obj { char pad[0x10]; In* in; Sub2* s; };

extern "C" void fn_801CF330(Obj* self) {
    self->in->f = 1;
    if (self->s != 0) {
        if (self->s->a21() != 0) {
            if (self->s->a10() != 0) {
                self->s->a19(0, 0);
            } else {
                self->s->a18();
            }
        }
    }
}
