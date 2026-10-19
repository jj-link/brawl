#pragma force_active on
struct fnBase {
    virtual void f0();
    virtual fnBase* f1(void* p);
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_2945F4(fnBase* self, fnBase* other, void* arg) {
    fnBase* ret = self->f1(arg);
    *(void**)ret = *(void**)other;
}
