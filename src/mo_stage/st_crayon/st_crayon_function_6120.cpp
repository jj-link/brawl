#pragma force_active on
class fn56Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" {
bool fn_56_6120(fn56Base* self) {
    return !self->vf3();
}
}
