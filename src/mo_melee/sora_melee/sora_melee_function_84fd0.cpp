#pragma force_active on
class soBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
};

extern "C" bool fn_27_84FD0(soBase* p) {
    return !p->v4();
}
