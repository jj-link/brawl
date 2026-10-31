#pragma force_active on
class soChildBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

struct soOwner {
    unsigned char pad[0x54];
    soChildBase* m_child;
};

extern "C" {
void fn_27_247EBC(soOwner* self) {
    soChildBase* child = self->m_child;
    if (child != 0) {
        child->vf3();
    }
}
}
