#pragma force_active on
class soGeneralWorkBase {
public:
    virtual ~soGeneralWorkBase();
    virtual void vf1();
    virtual void vf2();
    virtual bool isEmpty();
};

extern "C" {
bool fn_27_1D579C(soGeneralWorkBase* p) {
    return !p->isEmpty();
}
}
