#pragma force_active on
class soFoo {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool isTarget();
};

extern "C" {
    bool fn_27_868FC(soFoo* p) {
        return !p->isTarget();
    }
}
