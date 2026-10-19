#pragma force_active on
struct Inner {
    virtual void v0();
    virtual Inner* v1();
    virtual void v2();
    virtual void v3();
};

struct Outer {
    int m_pad[2];
    Inner* m_inner;
};

extern "C" void fn_27_37E94(Inner* self, void* arg);

extern "C" void fn_27_37AC0(Outer* self, int unused, void* arg) {
    fn_27_37E94(self->m_inner->v1(), arg);
}
