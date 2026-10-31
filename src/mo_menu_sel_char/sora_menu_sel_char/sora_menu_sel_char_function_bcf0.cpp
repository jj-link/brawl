#pragma force_active on
struct fn_10_BCF0_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

struct fn_10_BCF0_Holder {
    char pad[8];
    fn_10_BCF0_Base* m_obj;
};

extern "C" void fn_10_BCF0(fn_10_BCF0_Holder* self) {
    fn_10_BCF0_Base* obj = self->m_obj;
    if (obj == 0) {
        return;
    }
    obj->vf5();
}
