#pragma force_active on
struct fn_67_8B24Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_67_8B24(fn_67_8B24Base* obj) {
    return obj->f3() == 0;
}
