#pragma force_active on
struct fn27Inner {
    virtual ~fn27Inner();
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

struct fn27Outer {
    char pad[0x30];
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_A762C(void* a, void* b);

void fn_27_A4600(fn27Outer* self, void* unused, void* arg) {
    void* r = self->m_inner->vf0();
    fn_27_A762C(r, arg);
}
}
