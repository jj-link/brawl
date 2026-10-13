#include <so/so_module_accesser.h>

extern "C" void fn_117_10044(void*, soModuleAccesser*);

// This call site's sound interface uses two boolean options at slot 0x1C.
// Keep the declaration local rather than changing other users of the shared header.
struct DededeCaptureSoundModule {
    virtual ~DededeCaptureSoundModule();
    virtual void update(Vec3f*);
    virtual void deactivate();
    virtual void activate(Vec3f*);
    virtual void setPos(Vec3f*, int);
    virtual int playSE(SndID, bool, bool, int);
};

extern "C" void fn_117_FF50(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000012) == true &&
        !accesser->getWorkManageModule().isFlag(0x22000016)) {
        fn_117_10044(self, accesser);
        DededeCaptureSoundModule* sound = reinterpret_cast<DededeCaptureSoundModule*>(
            &accesser->getSoundModule());
        int soundHandle = sound->playSE(static_cast<SndID>(0x3D7), false, false, 0);
        accesser->getWorkManageModule().setInt(soundHandle, 0x20000005);
        accesser->getWorkManageModule().onFlag(0x22000016);
    }
}
