#pragma force_active on
class Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int);
};

extern "C" void fn_80184120(Object* self) {
    self->vf4(0);
}
