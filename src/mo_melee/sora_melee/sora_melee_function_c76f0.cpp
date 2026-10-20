#pragma force_active on
class soProbe {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
bool fn_27_C76F0(soProbe* p) {
    return !p->v3();
}
}
