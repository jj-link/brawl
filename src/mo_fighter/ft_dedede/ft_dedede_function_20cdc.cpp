#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>

namespace {
// The primary dispatch pointer follows the follower's non-polymorphic prefix.
struct FollowerPrefix {
    unsigned char storage[0x3C];
};
class FollowerView : public FollowerPrefix {
    virtual void slot008() = 0;
    virtual void slot00C() = 0;
    virtual void slot010() = 0;
    virtual void slot014() = 0;
    virtual void slot018() = 0;
    virtual void slot01C() = 0;
    virtual void slot020() = 0;
    virtual void slot024() = 0;
    virtual void slot028() = 0;
    virtual void slot02C() = 0;
    virtual void slot030() = 0;
    virtual void slot034() = 0;
    virtual void slot038() = 0;
    virtual void slot03C() = 0;
    virtual void slot040() = 0;
    virtual void slot044() = 0;
    virtual void slot048() = 0;
    virtual void slot04C() = 0;
    virtual void slot050() = 0;
    virtual void slot054() = 0;
    virtual void slot058() = 0;
    virtual void slot05C() = 0;
    virtual void slot060() = 0;
    virtual void slot064() = 0;
    virtual void slot068() = 0;
    virtual void slot06C() = 0;
    virtual void slot070() = 0;
    virtual void slot074() = 0;
    virtual void slot078() = 0;
    virtual void slot07C() = 0;
    virtual void slot080() = 0;
    virtual void slot084() = 0;
    virtual void slot088() = 0;
    virtual void slot08C() = 0;
    virtual void slot090() = 0;
    virtual void slot094() = 0;
    virtual void slot098() = 0;
    virtual void slot09C() = 0;
    virtual void slot0A0() = 0;
    virtual void slot0A4() = 0;
    virtual void slot0A8() = 0;
    virtual void slot0AC() = 0;
    virtual void slot0B0() = 0;
    virtual void slot0B4() = 0;
    virtual void slot0B8() = 0;
    virtual void slot0BC() = 0;
    virtual void slot0C0() = 0;
    virtual void slot0C4() = 0;
    virtual void slot0C8() = 0;
    virtual void slot0CC() = 0;
    virtual void slot0D0() = 0;
    virtual void slot0D4() = 0;
    virtual void slot0D8() = 0;
    virtual void slot0DC() = 0;
    virtual void slot0E0() = 0;
    virtual void slot0E4() = 0;
    virtual void slot0E8() = 0;
    virtual void slot0EC() = 0;
    virtual void slot0F0() = 0;
    virtual void slot0F4() = 0;
    virtual void slot0F8() = 0;
    virtual void slot0FC() = 0;
    virtual void slot100() = 0;
    virtual void slot104() = 0;
    virtual void slot108() = 0;
    virtual void slot10C() = 0;
    virtual void slot110() = 0;
    virtual void slot114() = 0;
    virtual void slot118() = 0;
    virtual void slot11C() = 0;
    virtual void slot120() = 0;
    virtual void slot124() = 0;
    virtual void slot128() = 0;
    virtual void slot12C() = 0;
    virtual void slot130() = 0;
    virtual void slot134() = 0;
    virtual void slot138() = 0;
    virtual void slot13C() = 0;
    virtual void slot140() = 0;
    virtual void slot144() = 0;
    virtual void slot148() = 0;
    virtual void slot14C() = 0;
    virtual void slot150() = 0;
    virtual void slot154() = 0;
    virtual void slot158() = 0;
    virtual void slot15C() = 0;
    virtual void slot160() = 0;
    virtual void slot164() = 0;
    virtual void slot168() = 0;
    virtual void slot16C() = 0;
    virtual void slot170() = 0;
    virtual void slot174() = 0;
    virtual void slot178() = 0;
    virtual void slot17C() = 0;
    virtual void slot180() = 0;
    virtual void slot184() = 0;
    virtual void slot188() = 0;
    virtual void slot18C() = 0;
    virtual void slot190() = 0;
    virtual void slot194() = 0;
    virtual void slot198() = 0;
    virtual void slot19C() = 0;
    virtual void slot1A0() = 0;
    virtual void slot1A4() = 0;
    virtual void slot1A8() = 0;
    virtual void slot1AC() = 0;
    virtual void slot1B0() = 0;
    virtual void slot1B4() = 0;
    virtual void slot1B8() = 0;
    virtual void slot1BC() = 0;
    virtual void slot1C0() = 0;
    virtual void slot1C4() = 0;
    virtual void slot1C8() = 0;
    virtual void slot1CC() = 0;
    virtual void slot1D0() = 0;
    virtual void slot1D4() = 0;
    virtual void slot1D8() = 0;
    virtual void slot1DC() = 0;
    virtual void slot1E0() = 0;
    virtual void slot1E4() = 0;
    virtual void slot1E8() = 0;
    virtual void slot1EC() = 0;
    virtual void slot1F0() = 0;
    virtual void slot1F4() = 0;
    virtual void slot1F8() = 0;
    virtual void slot1FC() = 0;
    virtual void slot200() = 0;
    virtual void slot204() = 0;
    virtual void slot208() = 0;
    virtual void slot20C() = 0;
    virtual void slot210() = 0;
    virtual void slot214() = 0;
    virtual void slot218() = 0;
    virtual void slot21C() = 0;
    virtual void slot220() = 0;
    virtual void slot224() = 0;
    virtual void slot228() = 0;
    virtual void slot22C() = 0;
    virtual void slot230() = 0;
    virtual void slot234() = 0;
    virtual void slot238() = 0;
    virtual void slot23C() = 0;
    virtual void slot240() = 0;
    virtual void slot244() = 0;
    virtual void slot248() = 0;
public:
    virtual bool isRestricted() = 0;
    unsigned char intermediate[0x20];
    soModuleAccesser* modules;
};
}

extern "C" bool fn_117_20CDC(FollowerView* follower) {
    if (follower->modules->getWorkManageModule().getInt(0x20000004) == 2) {
        return false;
    }
    switch (follower->modules->getStatusModule().getStatusKind()) {
    case 0:
    case 1:
    case 7:
    case 8:
    case 9:
    case 23:
    case 24:
    case 25:
        return false;
    default:
        return !follower->isRestricted();
    }
}
