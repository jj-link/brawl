#pragma force_active on
class soGeneralWorkBase {
public:
    virtual ~soGeneralWorkBase();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_1253BC(soGeneralWorkBase* p) {
    return !p->vf3();
}
