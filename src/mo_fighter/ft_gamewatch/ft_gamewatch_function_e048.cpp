#pragma force_active on
class ftGameWatchObj {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

extern "C" bool fn_107_E048(ftGameWatchObj* obj) {
    return obj->f3() == 0;
}
