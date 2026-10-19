#pragma force_active on
class soBase {
public:
    virtual ~soBase();
    virtual void vf0();
    virtual void vf1();
    virtual bool vf2();
};

extern "C" {
bool fn_27_1D23D8(soBase* p) {
    return !p->vf2();
}
}
