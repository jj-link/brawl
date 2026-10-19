#pragma force_active on
class grCrayonBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_56_AEDC(grCrayonBase* obj) {
    return !obj->vf3();
}
}
