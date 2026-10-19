#pragma force_active on
struct fn27Inner {
    virtual void v0();
    virtual void* v1(void* p);
};

struct fn27Outer {
    char pad[0x28];
    fn27Inner* m_inner;
};

extern "C" {
void* fn_27_2EBBC(void* a, void* b);

void* fn_27_26458(fn27Outer* self, void* a, void* b) {
    void* r = self->m_inner->v1(b);
    return fn_27_2EBBC(r, a);
}
}
