#pragma force_active on
class soBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
bool fn_27_86A00(soBase* p) {
    return !p->v3();
}
}
