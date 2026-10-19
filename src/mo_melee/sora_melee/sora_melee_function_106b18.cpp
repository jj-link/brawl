#pragma force_active on
class soObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
    bool fn_27_106B18(soObj* p) {
        return !p->v3();
    }
}
