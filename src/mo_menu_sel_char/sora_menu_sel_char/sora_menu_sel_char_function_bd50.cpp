#pragma force_active on
typedef unsigned int u32;

struct Inner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
};

struct Outer {
    u32 unk0;
    u32 unk4;
    Inner* m_inner;
};

extern "C" void fn_10_BD50(Outer* self) {
    if (!self->m_inner) {
        return;
    }
    self->m_inner->vfunc2();
}
