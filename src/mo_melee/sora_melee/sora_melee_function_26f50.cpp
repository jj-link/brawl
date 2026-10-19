#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void* v1(void* p);
};

struct Outer {
    char pad[0x28];
    Inner* m_inner;
};

extern "C" void fn_27_2EE74(void* a, void* b, int c);

extern "C" {
void fn_27_26F50(Outer* self, void* a, void* b) {
    fn_27_2EE74(self->m_inner->v1(b), a, 1);
}
}
