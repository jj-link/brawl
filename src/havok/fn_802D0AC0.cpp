#pragma force_active on
class Base {
public:
    virtual void vf0(int a);
};

extern "C" void fn_802D0AC0(Base* obj) {
    obj->vf0(-1);
}
