#pragma force_active on
extern "C" void fn_27_302A8(float, float, float);

class SoSubObj {
public:
    virtual void vfunc0();
    virtual void vfunc1(float, float, float);
};

struct SoOuter {
    char pad[0x28];
    SoSubObj* m_sub;
};

extern "C" void fn_27_2A860(SoOuter* self, float a, float b, float c) {
    self->m_sub->vfunc1(a, b, c);
    fn_27_302A8(a, b, c);
}
