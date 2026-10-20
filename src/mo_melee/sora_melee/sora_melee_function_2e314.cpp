#pragma force_active on
typedef unsigned int u32;

class soOuter;

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u32 a, u32 b, soOuter* outer, u32 c);
};

class soOuter {
public:
    char pad[0x44];
    soInner* m_inner;
};

extern "C" void fn_27_2E314(soOuter* self, u32 a1, u32 a2, u32 a3) {
    self->m_inner->vf3(a2, a1, self, a3);
}
