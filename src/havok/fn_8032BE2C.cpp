#pragma force_active on
class Obj {
public:
    virtual void vf0(int p);
};

extern "C" void fn_8032BE2C(Obj* p) {
    p->vf0(-1);
}
