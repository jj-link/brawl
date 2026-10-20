#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void* f1();
};

class Outer {
public:
    char pad[0x30];
    Inner* m_inner;
};

extern "C" void fn_27_A76E8(void* a, float f, void* b);

extern "C" void fn_27_A46DC(Outer* self, float f, int unused, void* p) {
    void* r = self->m_inner->f1();
    fn_27_A76E8(r, f, p);
}
