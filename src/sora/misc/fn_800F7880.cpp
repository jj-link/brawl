#pragma force_active on

#include <types.h>
#include <mu/mu_object.h>
#include <stdio.h>

struct Inner {
    char pad[0x3C];
    int off;
};

struct ObjectHandler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void bind(void*, void*);
    virtual void slot12();
    virtual void unbind(void*);
    char pad[0xE0];
    void* fieldE4;
};

struct TaskBase {
    char pad[0x3C];
};

struct Entry {
    MuObject* mu;
    bool active;
};

class gfTask : public TaskBase {
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

    char pad2[0x90 - 0x40];
    ObjectHandler* handler;
    char pad3[0x9C - 0x94];
    Entry entries[9];
    char pad4[0x428 - 0xE4];
    bool flag428;
    char pad5[3];
    int state;
};

extern "C" {
extern char lbl_8059E3E0[3];
extern char lbl_8059E3E8[8];
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
}

inline void unbindEntry(gfTask* self, Entry* e) {
    if (e->active) {
        self->handler->unbind(e->mu->m_sceneModel);
        e->active = false;
    }
}

inline void bindEntry(gfTask* self, Entry* e) {
    if (!e->active) {
        self->handler->bind(self->handler->fieldE4, e->mu->m_sceneModel);
        e->active = true;
    }
}

inline void playAnim(gfTask* self, Entry* e, int sel) {
    char buf[0x40];
    int suffix = sel + 1;
    if (suffix == 0) {
        Inner* inner = *(Inner**)&e->mu->m_resMdl;
        char* name;
        if (inner->off != 0)
            name = (char*)inner + inner->off;
        else
            name = 0;
        sprintf(buf, lbl_8059E3E0, name);
    } else {
        Inner* inner = *(Inner**)&e->mu->m_resMdl;
        char* name;
        if (inner->off != 0)
            name = (char*)inner + inner->off;
        else
            name = 0;
        sprintf(buf, lbl_8059E3E8, name, suffix);
    }
    e->mu->changeAnimN(buf);
    setLoop__16gfModelAnimationFd(e->mu->m_modelAnim, true);
    float rate = self->fn_800F5CBC();
    e->mu->m_modelAnim->setUpdateRate(rate);
}

extern "C" void fn_800F7880(gfTask* self, int index) {
    for (int i = 0; i < 9; i++) {
        if (i != 0)
            unbindEntry(self, &self->entries[i]);
    }

    if (index >= 0) {
        if (index != 4 && index != 5)
            self->state = index;

        if (self->flag428 || index == 5) {
            bindEntry(self, &self->entries[6]);
        } else {
            bindEntry(self, &self->entries[5]);
            playAnim(self, &self->entries[5], (int)((u32)((4 - index) | (index - 4)) >> 31));
        }

        if (self->state >= 0) {
            int n = self->state + 1;
            bindEntry(self, &self->entries[n]);
            playAnim(self, &self->entries[n], (int)((u32)((index - self->state) | (self->state - index)) >> 31));
        }
    }
}
