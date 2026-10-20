#pragma force_active on
extern "C" int fn_27_9EFD8(void* self, int flag);
extern "C" void fn_27_9F284(void* self, int value);

class soSeqBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" void fn_27_9F67C(soSeqBase* self) {
    int v = self->vfunc3();
    fn_27_9F284(self, fn_27_9EFD8(self, v - 1));
}
