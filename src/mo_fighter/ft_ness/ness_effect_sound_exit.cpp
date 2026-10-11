#include <so/so_module_accesser.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

// The shared sound declaration places the two-argument stop one slot early.
// Keep this original caller ABI local until that interface is fully described.
class NessSoundStopView {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void stopSound(int, int);
};

extern "C" void fn_101_1304C(void*, soModuleAccesser* accesser, int eventKind) {
    if (eventKind != 0x11E && eventKind != 0x11F) {
        int effect = accesser->getWorkManageModule().getInt(0x20000003);
        if (effect >= 0) {
            accesser->getEffectModule().kill(effect, true, true);
        }
        accesser->getWorkManageModule().setInt(-1, 0x20000003);
        int sound = accesser->getWorkManageModule().getInt(0x20000002);
        if (sound >= 0) {
            reinterpret_cast<NessSoundStopView*>(&accesser->getSoundModule())->stopSound(sound, 0);
        }
        accesser->getWorkManageModule().setInt(-1, 0x20000002);
    }
}

void operator delete(void*);
extern "C" void* fn_101_13164(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
