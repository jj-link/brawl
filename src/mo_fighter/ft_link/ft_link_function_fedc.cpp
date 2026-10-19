#pragma force_active on
struct FnVBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct FnMid {
    char pad[0x34];
    FnVBase* inner;
};

struct FnOuter {
    char pad[0xd8];
    FnMid* mid;
};

extern "C" {
int fn_93_FEDC(FnOuter* self) {
    self->mid->inner->v4();
    return 0;
}
}
