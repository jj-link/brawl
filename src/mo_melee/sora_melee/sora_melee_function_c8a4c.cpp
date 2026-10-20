#pragma force_active on
struct fnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getCount();
};

extern "C" void* fn_27_C8F28(void*, int);
extern "C" void fn_27_C91D4(void*, void*);

extern "C" void fn_27_C8A4C(fnBase* self) {
    int n = self->getCount();
    void* r = fn_27_C8F28(self, n - 1);
    fn_27_C91D4(self, r);
}
