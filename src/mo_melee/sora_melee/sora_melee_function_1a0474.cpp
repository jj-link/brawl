#pragma force_active on
class fnBaseVirt {
public:
    virtual bool v0();
    virtual bool v1();
    virtual bool v2();
    virtual bool v3();
    virtual bool v4();
    virtual bool v5();
};

extern "C" bool fn_27_1A0474(fnBaseVirt* p) {
    return !p->v3();
}
