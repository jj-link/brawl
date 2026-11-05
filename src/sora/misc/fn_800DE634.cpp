#include <gf/gf_model.h>
#include <mu/mu_msg.h>
#include <types.h>

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
    char pad[0xE0];
    void* fe4;
};

struct Ctx {
    char pad0[0x10];
    void* f10;
    gfModelAnimation* f14;
};

struct Entry {
    char pad0[0x10];
    u32 f10;
};

struct Self {
    char pad0[0x8];
    Class_8042B6D0* f8;
    char pad1[0x34];
    Ctx* f40;
    Ctx* f44;
    char pad2[0x11C];
    MuMsg* f164;
    int f168;
    char pad3[4];
    float f170;
};

extern "C" {
void fn_800B753C(void*, float);
Entry* fn_800791FC(void*, unsigned int);
extern void* lbl_805A01D8;
extern const float lbl_805A2374;

void fn_800DE634(Self* self) {
    Ctx* ctx = self->f44;
    ctx->f14->setUpdateRate(self->f170);
    fn_800B753C(ctx, lbl_805A2374);
    self->f8->fn_801B2EEC(self->f8->fe4, ctx->f10);
    int id = self->f168;
    if (id != 0xFFFFFFFF) {
        self->f8->fn_801B2EEC(self->f8->fe4, self->f40->f10);
        Entry* e = fn_800791FC(lbl_805A01D8, id);
        if (e != NULL) {
            self->f164->printIndex(0, e->f10, NULL);
        }
    }
}
}