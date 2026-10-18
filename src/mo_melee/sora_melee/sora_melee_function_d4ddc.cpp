#pragma force_active on
typedef short s16;
typedef signed char s8;

class fn_27_Base {
public:
    virtual void vfunc2(s16 a, s8 b);
};

extern "C" {
void fn_27_D4DDC(fn_27_Base* self, s16 a, s8 b) {
    self->vfunc2(a, b);
}
}
