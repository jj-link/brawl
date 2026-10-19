#pragma force_active on
class fn27Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
};

extern "C" bool fn_27_54258(fn27Base* p) {
    return !p->v4();
}
