#pragma force_active on
class fnBase {
public:
    virtual void f0();
    virtual fnBase* f3(void* p);
};

extern "C" void fn_27_F44E4(fnBase* self, fnBase* src, void* p) {
    fnBase* r = self->f3(p);
    *(void**)r = *(void**)src;
}
