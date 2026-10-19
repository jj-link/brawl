#pragma force_active on
class soObjBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_86CD8(soObjBase* obj) {
    return !obj->vf3();
}
