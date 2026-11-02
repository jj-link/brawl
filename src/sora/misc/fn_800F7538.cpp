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

struct gfTask_base {
    char pad[0x3C];
};

class gfTask : public gfTask_base {
public:
    virtual void fn_800F7454();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_800F7168();
    virtual void fn_800F7280();
    virtual void fn_800F5A58();
    virtual void fn_800F7450();
    virtual void fn_800F5C60();
    virtual void fn_800F7CAC();
    virtual float fn_800F5CBC();
    char pad2[0x9C - 0x40];
    MuObject* mu;
    char pad3[0x42C - 0xA0];
    int state;
};

extern char lbl_8059E3E0[3];
extern char lbl_8059E3E8[8];
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void changeAnimN__8MuObjectFPCc(void* obj, const char* name);
extern "C" void setLoop__16gfModelAnimationFd(void* anim, bool loop);
extern "C" void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);

extern "C" void fn_800F7538(gfTask* self) {
    char buf[0x40];
    int idx;
    switch (self->state) {
    case 0:
    case 3:
        idx = 0;
        break;
    case 1:
        idx = 3;
        break;
    case 2:
        idx = 6;
        break;
    default:
        idx = 0;
        break;
    }
    if (idx + 1 == 0) {
        Inner* inner = self->mu->unk8;
        char* p;
        if (inner->off != 0) {
            p = (char*)inner + inner->off;
        } else {
            p = 0;
        }
        sprintf(buf, lbl_8059E3E0, p);
    } else {
        Inner* inner = self->mu->unk8;
        char* p;
        if (inner->off != 0) {
            p = (char*)inner + inner->off;
        } else {
            p = 0;
        }
        sprintf(buf, lbl_8059E3E8, p, idx + 1);
    }
    changeAnimN__8MuObjectFPCc(self->mu, buf);
    setLoop__16gfModelAnimationFd(self->mu->unk14, false);
    float rate = self->fn_800F5CBC();
    setUpdateRate__16gfModelAnimationFf(self->mu->unk14, rate);
}
