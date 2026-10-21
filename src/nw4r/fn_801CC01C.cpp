#pragma force_active on
struct Base {
    virtual void vf0();
    virtual void vf1(int a, int b, int c, int d, int e, int f);
    virtual void vf2();
};

extern "C" {
void fn_801CC01C(Base* p, int a, int b, int c, int d, int e) {
    p->vf1(a, b, c, d, 0, e);
}
}
