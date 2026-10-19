#pragma force_active on
class Base {
public:
    virtual int vf0();
    virtual int vf1();
    virtual int vf2();
    virtual int vf3();
    virtual int vf4();
    virtual int vf5();
};

extern "C" bool fn_72_9BA8(Base* p) {
    return !p->vf3();
}
