#pragma force_active on
struct ftIkeVirtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
bool fn_119_A8E4(ftIkeVirtBase* p) {
    return !p->v3();
}
}
