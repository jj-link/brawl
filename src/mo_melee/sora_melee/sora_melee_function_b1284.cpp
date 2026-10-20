#pragma force_active on
class soObjBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" {
bool fn_27_B1284(soObjBase* obj) {
    return !obj->vf3();
}
}
