#pragma force_active on
struct StBase {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
};

extern "C" bool fn_74_A440(StBase* obj) {
    return obj->v3() == 0;
}
