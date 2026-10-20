#pragma force_active on
struct SubObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

struct OuterObj {
    char pad[0x10];
    SubObj sub;
};

extern "C" {
void fn_41_3438C(OuterObj* self) {
    self->sub.vf3();
}
}
