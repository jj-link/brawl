#pragma force_active on
class soVirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" void fn_27_C3188(soVirtBase* p) {
    p->v4();
}
