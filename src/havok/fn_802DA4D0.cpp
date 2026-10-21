#pragma force_active on

class soVirtBase {
public:
    virtual void vf0(int);
};

extern "C" {
void fn_802DA4D0(soVirtBase* p) {
    p->vf0(-1);
}
}
