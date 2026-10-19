#pragma force_active on
class ftLucarioVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_118_B5CC(ftLucarioVirtBase* obj) {
    return !obj->vf3();
}
