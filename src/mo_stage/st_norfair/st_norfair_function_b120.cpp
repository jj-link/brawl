#pragma force_active on
struct StNorfairBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
    virtual void vf4();
    virtual int vf5();
};

extern "C" bool fn_54_B120(StNorfairBase* self) {
    return self->vf3() == 0;
}
