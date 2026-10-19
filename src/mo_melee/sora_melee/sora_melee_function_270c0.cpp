#pragma force_active on
struct Inner {
    virtual void dummy();
    virtual void* vf3(void* p);
};

struct Outer {
    unsigned char pad[0x28];
    Inner* m_inner;
};

extern "C" void fn_27_2EF60(void* self, void* p);

extern "C" void fn_27_270C0(Outer* self, void* a, void* b) {
    void* r = self->m_inner->vf3(b);
    fn_27_2EF60(r, a);
}
