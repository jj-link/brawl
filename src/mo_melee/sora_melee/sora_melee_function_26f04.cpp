#pragma force_active on
struct soInner {
    virtual void f0();
    virtual void* f1(void* a);
    virtual void f2();
    virtual void f3();
};

struct soOuter {
    char pad[0x28];
    soInner* m_inner;
};

extern "C" void fn_27_2EF0C(void* a, void* b, int c);

extern "C" void fn_27_26F04(soOuter* self, void* a, void* b) {
    fn_27_2EF0C(self->m_inner->f1(b), a, 0);
}
