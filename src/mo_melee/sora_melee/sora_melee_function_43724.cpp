#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void* f1(void* arg);
    virtual void f2();
    virtual void f3();
};

struct Outer {
    unsigned char pad0[0x30];
    void* m30;
    unsigned char pad1[0x58 - 0x34];
    Inner* m58;
};

extern "C" void fn_27_41F7C(void* a, void* b, void* c);

extern "C" void fn_27_43724(Outer* self, void* p1, void* p2) {
    void* r = self->m58->f1(p2);
    fn_27_41F7C(r, self->m30, p1);
}
