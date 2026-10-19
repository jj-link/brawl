#pragma force_active on
extern "C" void fn_27_B1CF4(void* a, void* b);

struct Inner {
    virtual void* v0();
    virtual void* v3(void* p);
};

struct Outer {
    char pad[0x18];
    Inner* m_inner;
};

extern "C" {
void fn_27_B2A58(Outer* self, void* a, void* b) {
    void* r = self->m_inner->v3(b);
    fn_27_B1CF4(r, a);
}
}
