#pragma force_active on
class fnBase {
public:
    virtual void f0();
    virtual fnBase* f1(int arg);
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_27_1CC6F4(fnBase* self, fnBase* src, int arg) {
    fnBase* r = self->f1(arg);
    *(void**)r = *(void**)src;
}
