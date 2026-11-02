#pragma force_active on

#include <gf/gf_model.h>
#include <mu/mu_msg.h>
#include <types.h>

class Vt {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11(void*, void*);
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
    Vt* f8;
    char pad1[0x40 - 0xC];
    Ctx* f40;
    char pad2[0x6C - 0x44];
    Ctx* f6c;
    char pad3[0x164 - 0x70];
    MuMsg* f164;
    int f168;
    char pad4[0x170 - 0x16C];
    float f170;
};

extern "C" {
void fn_800B753C(void*, float);
Entry* fn_800791FC(void*, unsigned int);
extern void* lbl_805A01D8;
extern const float lbl_805A2374;

void fn_800DE78C(Self* self) {
    Ctx* ctx = self->f6c;
    ctx->f14->setUpdateRate(self->f170);
    fn_800B753C(ctx, lbl_805A2374);
    self->f8->s11(self->f8->fe4, ctx->f10);
    u32 id = self->f168;
    if (id != 0xFFFFFFFF) {
        self->f8->s11(self->f8->fe4, self->f40->f10);
        Entry* e = fn_800791FC(lbl_805A01D8, id);
        if (e != NULL) {
            self->f164->printIndex(0, e->f10, NULL);
        }
    }
}
}
