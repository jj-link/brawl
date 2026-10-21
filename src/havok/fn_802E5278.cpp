#pragma force_active on
class Base {
public:
    virtual void vf0(int p);
};

extern "C" void fn_802E5278(Base* p) {
    p->vf0(-1);
}
