#pragma force_active on
struct ftBase {
    virtual int vf0();
    virtual int vf1();
    virtual int vf2();
    virtual int vf3();
    virtual int vf4();
    virtual int vf5();
};

extern "C" bool fn_113_12484(ftBase* p) {
    return !p->vf3();
}
