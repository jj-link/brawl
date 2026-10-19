#pragma force_active on
class fnBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_67_8B8C(fnBase* p) {
    return !p->vf3();
}
