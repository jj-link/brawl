#include <mu/mu_object.h>
#include <stdio.h>
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
    virtual void fn_801B3050();
    virtual void fn_801B3248(void*);
    char pad[0xe0];
    void* fieldE4;
};
struct Entry { MuObject* mu; bool active; };
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void fn_800F6520();
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
    virtual void fn_800F6280();
    virtual void fn_800F63B8();
    virtual void fn_800F5A58();
    virtual void fn_800F5AEC();
    virtual void fn_800F5C60();
    virtual void fn_800F7CAC();
    virtual float fn_800F5CBC();
    char pad2[0x90-0x40];
    Class_8042B6D0* handler;
    char pad3[8];
    Entry entries[9];
};
struct Inner { char pad[0x3c]; int off; };
extern char lbl_8059E3E0[3];
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
extern "C" void fn_800F6648(gfTask* self, int index) {
    char buf[0x40];
    for (int i = 0; i < 9; i++) {
        if (i != 0 && self->entries[i].active) {
            self->handler->fn_801B3248(self->entries[i].mu->m_sceneModel);
            self->entries[i].active = false;
        }
    }
    if (index >= 0) {
        int n = index + 1;
        if (!self->entries[n].active) {
            self->handler->fn_801B2EEC(self->handler->fieldE4, self->entries[n].mu->m_sceneModel);
            self->entries[n].active = true;
        }
        Inner* inner = *(Inner**)&self->entries[n].mu->m_resMdl;
        char* p;
        if (inner->off != 0) p = (char*)inner + inner->off;
        else p = 0;
        sprintf(buf, lbl_8059E3E0, p);
        self->entries[n].mu->changeAnimN(buf);
        setLoop__16gfModelAnimationFd(self->entries[n].mu->m_modelAnim, true);
        float rate = self->fn_800F5CBC();
        self->entries[n].mu->m_modelAnim->setUpdateRate(rate);
    }
}