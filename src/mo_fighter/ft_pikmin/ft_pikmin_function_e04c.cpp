#pragma force_active on
class ftPikminBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_113_E04C(ftPikminBase* p) {
    return !p->vf3();
}
