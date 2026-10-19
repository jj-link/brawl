#pragma force_active on
class fnBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_56_AFAC(fnBase* p) {
    return !p->v3();
}
