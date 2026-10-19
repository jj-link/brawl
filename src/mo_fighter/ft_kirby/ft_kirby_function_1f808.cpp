#pragma force_active on
struct ftKirbyBase {
    virtual int vf0() = 0;
    virtual int vf1() = 0;
    virtual int vf2() = 0;
    virtual int vf3() = 0;
    virtual int vf4() = 0;
    virtual int vf5() = 0;
};

extern "C" bool fn_96_1F808(ftKirbyBase* p) {
    return !p->vf3();
}
