#pragma force_active on
struct FighterBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct FighterOuter {
    char pad[0x19DE8];
    FighterBase member;
};

extern "C" void fn_121_CBCC(FighterOuter* self) {
    FighterBase* p = &self->member;
    p->vf2();
}
