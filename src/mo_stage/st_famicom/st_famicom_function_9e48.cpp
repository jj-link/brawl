#pragma force_active on
struct FnVtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_68_9E48(FnVtBase* obj) {
    return !obj->f3();
}
