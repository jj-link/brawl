#pragma force_active on
class soObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_50_85D8(soObj* obj) {
    return !obj->v3();
}
