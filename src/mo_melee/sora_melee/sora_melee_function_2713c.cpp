#pragma force_active on
struct Inner {
    virtual void vf0();
    virtual int vf1(int b);
};

struct Outer {
    char pad[0x28];
    Inner* m_inner;
};

extern "C" int fn_27_2EF7C(int r, int a);

extern "C" int fn_27_2713C(Outer* self, int a, int b) {
    int r = self->m_inner->vf1(b);
    return fn_27_2EF7C(r, a);
}
