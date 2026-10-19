#pragma force_active on
struct fnVal {
    unsigned int v;
};

struct fnBase {
    virtual void vf0();
    virtual fnVal* vf1(unsigned int a);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_1C77D4(fnBase* self, fnVal* p, unsigned int a) {
    fnVal* d = self->vf1(a);
    *d = *p;
}
