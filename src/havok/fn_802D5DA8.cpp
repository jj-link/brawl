#pragma force_active on
class soVirtBase {
public:
    virtual void vf2(int p);
};

extern "C" void fn_802D5DA8(soVirtBase* p) {
    p->vf2(-1);
}
