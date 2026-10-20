#pragma force_active on
extern "C" void* fn_27_2AD89C(void* self, int flag);
extern "C" void fn_27_2ADB40(void* self, void* value);

class soSelfBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" {
void fn_27_2AF178(soSelfBase* self) {
    int n = self->vfunc3();
    void* r = fn_27_2AD89C(self, n - 1);
    fn_27_2ADB40(self, r);
}
}
