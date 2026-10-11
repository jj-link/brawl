#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// The trigger slot returns a scalar mask in the original ABI.
class LuigiControlModuleView {
public:
    virtual ~LuigiControlModuleView();
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
    virtual void update(Input*, bool);
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
};

extern "C" {
extern const char lbl_99_data_6358[], lbl_99_data_171C[];
extern const float lbl_99_rodata_28;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_99_CA84(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000011) == true) {
        float reduction = accesser->getWorkManageModule().getFloat(0x21000004);
        reduction += soValueAccesser::getConstantFloat(accesser, 0xfc0, 0);
        accesser->getWorkManageModule().setFloat(reduction, 0x21000004);
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(2), 0,
            lbl_99_data_6358, lbl_99_data_171C, 1));
        float stableSpeed;
        if (accesser->getKineticModule().getKineticType() == 0x69)
            stableSpeed = soValueAccesser::getConstantFloat(accesser, 0xfbe, 0);
        else
            stableSpeed = soValueAccesser::getConstantFloat(accesser, 0xfc3, 0);
        *reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned char*>(energy) + 0x28) =
            Vec2f(stableSpeed > reduction ? stableSpeed - reduction : lbl_99_rodata_28,
                  lbl_99_rodata_28);
    }
    float impulse;
    if (accesser->getWorkManageModule().isFlag(0x1200003d) != false)
        goto noImpulse;
    if (accesser->getWorkManageModule().isFlag(0x22000012) != true)
        goto noImpulse;
    {
        LuigiControlModuleView* controller =
            reinterpret_cast<LuigiControlModuleView*>(&accesser->getControllerModule());
        if (!(controller->getTrigger() &
              soController::getButtonMask(soController::Pad_Button_Special)))
            goto noImpulse;
    }
    impulse = soValueAccesser::getConstantFloat(accesser, 0xfc1, 0);
    if (accesser->getSituationModule().getKind() != 2) {
        accesser->getKineticModule().changeKinetic(0x6a, accesser);
        accesser->getSituationModule().setKind(Situation_Air, false);
        accesser->getGroundModule().setCorrect(static_cast<soGroundShapeImpl::CorrectKind>(5), 0);
    }
    goto setImpulse;
noImpulse:
    impulse = lbl_99_rodata_28;
setImpulse:
    accesser->getWorkManageModule().setFloat(impulse, 0x21000005);
}
