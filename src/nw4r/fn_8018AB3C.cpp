#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(void* a);
};

extern "C" {
int fn_8018AB3C(void* a, Base* b) {
    return b->v3(a);
}
}
