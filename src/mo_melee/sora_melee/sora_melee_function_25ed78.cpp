#pragma force_active on
extern "C" int fn_27_21CBAC(void*, int);
extern "C" void fn_27_25F064(void*, int);

class soSoraVirtual {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf5();
};

extern "C" void fn_27_25ED78(soSoraVirtual* self) {
    int n = self->vf5();
    int result = fn_27_21CBAC(self, n - 1);
    fn_27_25F064(self, result);
}
