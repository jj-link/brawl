#pragma force_active on
struct emVirtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_41_C59C(emVirtBase* p) {
    return !p->v3();
}
