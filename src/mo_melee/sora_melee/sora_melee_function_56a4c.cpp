#pragma force_active on
class soVirtBase {
public:
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6(unsigned int a, unsigned int b) = 0;
    virtual void vf7(unsigned int a, unsigned int b, unsigned int c, unsigned int d) = 0;
};

extern "C" {
void fn_27_56A4C(soVirtBase* self, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5) {
    self->vf6(a2, a5);
    self->vf7(a1, a3, a4, a5);
}
}
