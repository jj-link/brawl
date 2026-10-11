#include <so/so_module_accesser.h>

// Declaration-only view of the sound ABI used by this callback. The shared
// provisional header omits the entry preceding the two-argument stop at 0x58.
class LuigiSoundStopModuleView {
public:
    virtual ~LuigiSoundStopModuleView();
    virtual void update(Vec3f*);
    virtual void deactivate();
    virtual void activate(Vec3f*);
    virtual void setPos(Vec3f*, int);
    virtual int playSE(SndID, bool, int, int);
    virtual int playSENo3d(SndID, bool);
    virtual int playSEPos(SndID, Vec3f*, bool, int, int);
    virtual int playStatusSE(SndID, bool, int);
    virtual void stopStatusSE();
    virtual void setPlayHitSEFlag(bool);
    virtual bool getPlayHitSEFlag();
    virtual void playHitSE(float, void*);
    virtual void playDamageSE(u32, u32);
    virtual void setSEVol(float, int, int);
    virtual float getSEVol(int);
    virtual void setSEPitch(float);
    virtual void setSEPitch(u32, double);
    virtual float getSEPitch();
    virtual void entry54();
    virtual void stopSE(int handle, int fadeFrames);
};

extern "C" void fn_99_1054C(void* object) {
    soModuleAccesser* accesser = *reinterpret_cast<soModuleAccesser**>(
        static_cast<unsigned char*>(object) + 0x60);
    soWorkManageModule* work = &accesser->getWorkManageModule();
    LuigiSoundStopModuleView* sound =
        reinterpret_cast<LuigiSoundStopModuleView*>(&accesser->getSoundModule());
    int handle = work->getInt(0x10000005);
    sound->stopSE(handle, 0);
}
