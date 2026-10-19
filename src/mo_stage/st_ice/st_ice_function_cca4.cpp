#pragma force_active on
struct stVirtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_62_CCA4(stVirtBase* obj) {
    return obj->v3() == 0;
}
