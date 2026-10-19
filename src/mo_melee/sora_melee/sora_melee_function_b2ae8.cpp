#pragma force_active on
struct fn_27_Inner {
    virtual void v0();
    virtual void v1(float f);
};

struct fn_27_Outer {
    char pad[0x18];
    fn_27_Inner* m_inner;
};

extern "C" void fn_27_B1D5C(float f);

extern "C" void fn_27_B2AE8(fn_27_Outer* self, float f) {
    self->m_inner->v1(f);
    fn_27_B1D5C(f);
}
