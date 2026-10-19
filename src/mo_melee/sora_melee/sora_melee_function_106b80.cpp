#pragma force_active on
class soVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_27_106B80(soVirtBase* p) {
    return !p->vf3();
}
}
