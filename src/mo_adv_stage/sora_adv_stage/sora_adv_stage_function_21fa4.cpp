#pragma force_active on
class grBase {
public:
    virtual ~grBase();
    virtual void vf0();
    virtual void vf1();
    virtual bool vf5();
};

extern "C" bool fn_40_21FA4(grBase* p) {
    return !p->vf5();
}
