#pragma force_active on
struct gfModelAnimation;

struct Inner {
    char pad[0x3C];
    int off;
};

struct MuObject {
    char pad0[8];
    Inner* unk8;
    char pad0C[8];
    gfModelAnimation* unk14;
};

#define SLOT(n) virtual float slot##n();

struct Obj {
    char pad[0x3C];
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7)
    SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28)
    char pad2[0x9C - 0x40];
    MuObject* mu;
};

#undef SLOT

extern char lbl_8059E3E8[8];
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void changeAnimN__8MuObjectFPCc(void* obj, const char* name);
extern "C" void setLoop__16gfModelAnimationFd(void* anim, bool loop);
extern "C" void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);

extern "C" void fn_800F5E30(Obj* self) {
    char buf[0x40];
    MuObject* mu = self->mu;
    Inner* inner = mu->unk8;
    char* p;
    if (inner->off != 0) {
        p = (char*)inner + inner->off;
    } else {
        p = 0;
    }
    sprintf(buf, lbl_8059E3E8, p, 2);
    changeAnimN__8MuObjectFPCc(self->mu, buf);
    setLoop__16gfModelAnimationFd(self->mu->unk14, true);
    float rate = self->slot28();
    setUpdateRate__16gfModelAnimationFf(self->mu->unk14, rate);
}
