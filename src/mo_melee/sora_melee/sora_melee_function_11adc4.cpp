#pragma force_active on
class fnSubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fnOuterObj {
public:
    char pad[0xc];
    fnSubObj sub;
};

extern "C" {
void fn_27_11ADC4(fnOuterObj* self) {
    self->sub.vf4();
}
}
