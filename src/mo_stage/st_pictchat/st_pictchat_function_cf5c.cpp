#pragma force_active on
struct stVirtObj {
    virtual ~stVirtObj();
    virtual void f0();
    virtual void f1();
    virtual bool f2();
};

extern "C" bool fn_73_CF5C(stVirtObj* obj) {
    return !obj->f2();
}
