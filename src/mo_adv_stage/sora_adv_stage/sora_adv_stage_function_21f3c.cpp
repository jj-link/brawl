#pragma force_active on
class grBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_40_21F3C(grBase* obj) {
    return !obj->vf3();
}
}
