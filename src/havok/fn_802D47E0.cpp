#pragma force_active on
class Object {
public:
    virtual void vf0(int);
    virtual void vf1();
    virtual void vf2();
};

extern "C" void fn_802D47E0(Object* p) {
    p->vf0(-1);
}
