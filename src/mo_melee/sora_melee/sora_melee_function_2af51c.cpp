#pragma force_active on
class soBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v5();
};

extern "C" bool fn_27_2AF51C(soBase* p) {
    return !p->v5();
}
