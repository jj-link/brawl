#pragma force_active on
class fn27Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_27_2AF4E8(fn27Base* p) {
    return !p->v3();
}
