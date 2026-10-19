#pragma force_active on
class fn27Base {
public:
    virtual void v0();
    virtual fn27Base* v1(void* p);
};

extern "C" void fn_27_F311C(fn27Base* self, fn27Base* src, void* arg) {
    fn27Base* dst = self->v1(arg);
    *(void**)dst = *(void**)src;
}
