#pragma force_active on
struct stVBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct stMidObj {
    char pad[0xc];
    stVBase* base;
};

struct stOuterObj {
    char pad[0xd8];
    stMidObj* mid;
};

extern "C" float fn_27_323B58(void* unused, stOuterObj* obj) {
    return -obj->mid->base->v9();
}
