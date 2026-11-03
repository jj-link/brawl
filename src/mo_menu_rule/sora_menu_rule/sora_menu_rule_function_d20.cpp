#include <snd/snd_system.h>
#pragma force_active on
struct Class_FA8_base { char pad[0x634]; int next; char pad2[0x30]; };
class Class_FA8 : public Class_FA8_base {
public:
    virtual void fn_18_48E8();
    virtual void fn_18_20C8(int, int);
    virtual void fn_18_B30();
    virtual int fn_18_2BBC();
    virtual void fn_18_3338();
};
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_18_D20();
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
    virtual void fn_18_B54();
    virtual void at64();
    virtual void at68();
    virtual void at6c(int);
};
struct Self {
    char pad[0x268];
    Class_FA8* items[4];
    int current;
    int previous;
    int arg;
    int counter;
    unsigned char flag;
    char pad2[3];
    int mode;
    gfTask* task;
    int value;
};
extern "C" void fn_18_D20(Self* self) {
    int result = 0;
    self->counter++;
    if (self->current != 5) {
        result = self->items[self->current]->fn_18_2BBC();
        if (result != 0 && self->previous != 5) {
            self->items[self->previous]->fn_18_3338();
            self->previous = 5;
        }
    }
    if (self->previous != 5 && self->items[self->previous]->fn_18_2BBC() == 3) {
        self->items[self->previous]->fn_18_3338();
        self->previous = 5;
    }
    switch (result) {
    case 1: {
        int target = 0;
        switch (self->mode) {
        case 3: target = 2; break;
        case 4:
        case 5: target = 3; break;
        }
        self->previous = self->current;
        if (self->current == target) {
            self->counter = 0;
            self->flag = 1;
            self->current = 5;
            self->task->at6c(self->value);
        } else {
            int current = self->current;
            self->current = self->items[current]->next - 30;
            self->items[self->current]->fn_18_20C8(self->arg, current);
        }
        if (self->previous != target)
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        break;
    }
    case 2:
        { int current = self->current;
        self->previous = current;
        self->current = self->items[current]->next - 30;
        self->items[self->current]->fn_18_20C8(self->arg, current); }
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        break;
    }
}