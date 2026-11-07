#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class ControllerView {
public:
    virtual ~ControllerView();
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

extern "C" void fn_105_13420(void*, soModuleAccesser* a) {
    if (!a->getWorkManageModule().isFlag(0x22000013) &&
        a->getSituationModule().getKind() == 0) {
        soWorkManageModule& work = a->getWorkManageModule();
        int threshold = soValueAccesser::getConstantInt(a, 0x5dc0, 0);
        if (work.getInt(0x20000002) >= threshold) {
            ControllerView& controller =
                reinterpret_cast<ControllerView&>(a->getControllerModule());
            int mask = soController::getButtonMask(soController::Pad_Button_Special);
            int trigger = controller.getTrigger();
            trigger &= mask;
            if (trigger) {
                if (a->getWorkManageModule().isFlag(0x22000010) == 1)
                    a->getKineticModule().changeKinetic(0x68, a);
                else
                    a->getKineticModule().changeKinetic(0x67, a);
                a->getSituationModule().setKind((SituationKind)2, false);
                a->getGroundModule().setCorrect((soGroundShapeImpl::CorrectKind)5, 0);
            }
        }
    }
}
