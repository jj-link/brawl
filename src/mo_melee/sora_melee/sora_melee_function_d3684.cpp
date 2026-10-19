#pragma force_active on
class IVirtualCheck {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_D3684(IVirtualCheck* p) {
    return !p->vf3();
}
