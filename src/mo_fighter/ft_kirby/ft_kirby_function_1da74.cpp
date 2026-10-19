#pragma force_active on
extern "C" void* fn_96_1D7E4(void* owner);

struct VBase {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10(void* a, void* b);
};

extern "C" void fn_96_1DA74(void* owner, void* a, void* b) {
    VBase* obj = (VBase*)fn_96_1D7E4(owner);
    if (obj != 0) {
        obj->vfunc10(a, b);
    }
}
