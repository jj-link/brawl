#pragma force_active on
struct grCrayonBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v5();
};

extern "C" bool fn_56_6154(grCrayonBase* obj) {
    return !obj->v5();
}
