#pragma force_active on
class soVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
    virtual void vf4();
    virtual void vf5();
};

extern "C" {
    bool fn_27_86930(soVirtualBase* p) {
        return !p->vf3();
    }
}
