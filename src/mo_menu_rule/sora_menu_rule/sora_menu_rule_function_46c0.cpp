#include <types.h>
#pragma force_active on

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void slot22();
    virtual void fn_18_1198(s32 a, s32 b, s32 c);
};

extern "C" {
void fn_18_46C0(void* self) {
    s32 state;
    u8* p = (u8*)self;
    switch (*(u16*)(p + 0x42)) {
    case 0:
        switch (p[0x66c]) {
        case 0:
            state = 0;
            break;
        case 1:
            state = 2;
            break;
        case 2:
            state = 1;
            break;
        }
        break;
    case 1:
        if (p[0x66c] != 1) {
            if (p[0x66d] == 0) {
                state = 4;
            } else {
                state = 3;
            }
        } else {
            state = 5;
        }
        break;
    case 2:
        state = p[0x66e] + 6;
        break;
    case 3:
        state = 9;
        break;
    case 4:
        state = p[0x670] + 10;
        break;
    case 5:
        state = 15;
        break;
    case 6:
        state = 16;
        break;
    }
    gfTask* t = *(gfTask**)(p + 0x658);
    t->fn_18_1198(state, 1, 0);
}
}
