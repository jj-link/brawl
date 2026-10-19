#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

struct FighterSub {
    virtual ~FighterSub();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

struct FighterSelf {
    char pad[0x1D094];
    FighterSub* sub;
};

extern "C" void fn_108_9FD0(FighterSelf* self, int param) {
    self->sub->vf7();
    fn_27_12BAF8(self, param);
}
