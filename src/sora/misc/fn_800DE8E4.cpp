#include <gf/gf_model.h>
#pragma force_active on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC(void*, void*);
    char pad[0xe0];
    void* fe4;
};
struct Ctx {
    char pad[0x10];
    void* f10;
    gfModelAnimation* f14;
};
struct Self {
    char pad[8];
    Class_8042B6D0* f8;
    char pad2[0x3c];
    Ctx* f48;
};
extern "C" {
extern const float lbl_805A2368;
extern const float lbl_805A2374;
void fn_800B753C(void*, float);
void fn_800DE8E4(Self* self) {
    Ctx* ctx = self->f48;
    ctx->f14->setUpdateRate(lbl_805A2368);
    fn_800B753C(ctx, lbl_805A2374);
    self->f8->fn_801B2EEC(self->f8->fe4, ctx->f10);
}
}