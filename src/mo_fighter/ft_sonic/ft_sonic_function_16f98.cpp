#include <stddef.h>
#pragma force_active on
#include <types.h>

extern "C" int fn_27_1DAF80(void*);
extern "C" void fn_27_1DB174(void*, int, float, float);
extern const float lbl_123_rodata_80;
extern const float lbl_123_rodata_88;

namespace {
class WorkObj {
public:
    virtual ~WorkObj();
    virtual void activate();
    virtual void setWork(u32, void*);
    virtual int getInt(u32);
    virtual void setInt(int, u32);
    virtual void rndInt(int, int, u32);
    virtual void incInt(u32);
    virtual void decInt(u32);
    virtual void addInt(int, u32);
    virtual void subInt(int, u32);
    virtual void unknown();
    virtual u32 countDownInt(u32, int);
    virtual float getFloat(u32);
};

class ControllerObj {
public:
    virtual ~ControllerObj();
    virtual void activate();
    virtual void deactivate();
    virtual void resetButton();
    virtual void resetTrigger();
    virtual void resetMainStickX();
    virtual void setMainStickX(float);
    virtual void resetMainStickY();
    virtual void setMainStickY(float);
    virtual void resetMainStick();
    virtual void resetSubStickX();
    virtual void resetSubStickY();
    virtual void resetSubStick();
    virtual void update(void*, bool);
    virtual void resetFlickX();
    virtual void resetFlickY();
    virtual float getStickX();
    virtual float getStickPrevX();
    virtual float getStickY();
    virtual float getStickPrevY();
    virtual float getStickAngle();
    virtual float getStickDir();
    virtual bool isStickSide();
    virtual u8 getFlickX();
    virtual s8 getFlickXDir();
    virtual u8 getFlickY();
    virtual s8 getFlickYDir();
    virtual u8 getFlickNoResetX();
    virtual u8 getFlickNoResetY();
    virtual u8 getFlickAfterX();
    virtual s8 getFlickAfterXDir();
    virtual u8 getFlickAfterY();
    virtual float getSubStickX();
    virtual float getSubStickPrevX();
    virtual float getSubStickY();
    virtual float getSubStickPrevY();
    virtual float getSubStickDir();
    virtual bool isSubStickSide();
    virtual int getTrigger();
    virtual u8 getTriggerCount(u8);
    virtual u8 getTriggerCountPrev(u8);
    virtual int getButton();
    virtual int getRelease();
    virtual void setOff(bool);
    virtual void setPrev(s32);
    virtual void clearLog();
    virtual s32 getLogNum();
    virtual void setLogActive(bool);
    virtual void startClatter(float, float, float, u8, u8, u32, bool);
    virtual void setClatterTime(float, u32);
    virtual void addClatterTime(float, u32);
    virtual float getClatterTime(u32);
    virtual void endClatter(u32);
    virtual float getClatterThreshold();
    virtual void* getController();
    virtual void setRumble(s32, s32, bool, s32);
};

struct Enumeration {
    char pad0[0x5C];
    ControllerObj* controller;
    char pad1[4];
    WorkObj* workManage;
};

struct Accesser {
    char pad0[0xD8];
    Enumeration* enumeration;
};

struct Fighter {
    char pad0[0x60];
    Accesser* accesser;
};
} // namespace

extern "C" int fn_123_16F98(Fighter* self, int arg1) {
    if ((arg1 & 7) != 0) {
        WorkObj* work = self->accesser->enumeration->workManage;
        if (work->getFloat(0x11000001) > lbl_123_rodata_88) {
            float value = self->accesser->enumeration->workManage->getFloat(0x11000001);
            fn_27_1DB174(self, 0, value, lbl_123_rodata_80);
            self->accesser->enumeration->controller->setRumble(0xD, 0, false, -1);
        }
        return 0;
    }
    fn_27_1DAF80(self);
}
