#pragma force_active on
struct Target {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8();
    virtual void f9(bool a, bool b);
};
struct Inner { char pad[0x3c]; Target* t; };
struct Owner { char pad[0xd8]; Inner* in; };

extern "C" void fn_109_CCF8(void* a, Owner* o, int id) {
    if (id < 0x11c && id >= 0x11a) return;
    bool z = false;
    o->in->t->f9(z, z);
}