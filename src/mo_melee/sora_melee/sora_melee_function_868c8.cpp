#pragma force_active on
class soBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual bool v5();
};

extern "C" {
bool fn_27_868C8(soBase* p) {
    return !p->v3();
}
}
