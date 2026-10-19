#pragma force_active on
class ftBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_123_B590(ftBase* p) {
    return !p->v3();
}
