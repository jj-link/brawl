#pragma force_active on
class soVirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual void v5();
};

extern "C" {
bool fn_27_CCA8C(soVirtBase* p) {
    return !p->v3();
}
}
