#pragma force_active on
extern "C" void fn_27_B1D18(float* p1, const float* p2);

class Inner {
public:
    virtual void v0();
    virtual float* v1(const float* p);
};

class Outer {
public:
    char pad[0x18];
    Inner* m_inner;
};

extern "C" {
void fn_27_B2AA0(Outer* self, const float* a, const float* b) {
    fn_27_B1D18(self->m_inner->v1(b), a);
}
}
