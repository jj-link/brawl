#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" {
bool fn_40_28604(Obj* obj) {
    return !obj->v3();
}
}
