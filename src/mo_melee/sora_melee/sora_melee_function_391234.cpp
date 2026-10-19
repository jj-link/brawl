#pragma force_active on
class fooBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_27_391234(fooBase* p) {
    return !p->v3();
}
