#pragma force_active on
struct acInnerBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual int vf7(int a, int b, int c);
};

struct acOuter {
    int unk0;
    acInnerBase* m_inner;
};

extern "C" {
int fn_802CAC60(acOuter* self, int unused, int a, int b, int c) {
    return self->m_inner->vf7(a, b, c);
}
}
