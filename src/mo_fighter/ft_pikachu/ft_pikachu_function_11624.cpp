#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <gf/gf_task.h>

// Only the generation operation is needed here. The article manager is not
// represented by the shared module headers; retain its existing virtual ABI.
class PikachuArticleManagerView {
public:
    virtual ~PikachuArticleManagerView();
    virtual void activate();
    virtual void deactivate();
    virtual void operation14();
    virtual void operation18();
    virtual void operation1c();
    virtual void operation20();
    virtual void operation24();
    virtual void operation28();
    virtual void generate(int kind, bool enable, int variant);
};

// This entry returns the trigger mask as a scalar in r3. The shared header's
// ipPadButton return materializes an aggregate temporary under MWCC.
class PikachuControllerView {
public:
    virtual ~PikachuControllerView();
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

struct PikachuLinkEvent : soLinkEventArgs {
    PikachuLinkEvent() : soLinkEventArgs(0x455) {}
};

extern "C" {
extern const char lbl_98_data_2F88[], lbl_98_data_3088[];
extern const float lbl_98_rodata_90;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_11624(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soWorkManageModule& work = *modules.m_workManageModule;
    PikachuControllerView& controller = *reinterpret_cast<PikachuControllerView*>(
        modules.m_controllerModule);
    PikachuArticleManagerView* articles = static_cast<PikachuArticleManagerView*>(
        modules.m_generateArticleManageModule);
    int cooldown = work.getInt(0x20000002);
    work.decInt(0x20000002);
    if (cooldown <= 0) {
        int attack = soController::getButtonMask(soController::Pad_Button_Attack);
        int trigger = controller.getTrigger();
        trigger &= attack;
        if (trigger) {
            articles->generate(2, true, 0);
            work.setInt(soValueAccesser::getConstantInt(accesser, 0x5dc7, 0), 0x20000002);
        }
    }
    gfTask* task = gfTask::getTask(work.getInt(0x20000003));
    if (task != 0) {
        StageObject* object = static_cast<StageObject*>(__dynamic_cast(
            task, 0x3c, lbl_98_data_2F88, lbl_98_data_3088, 1));
        if (soExternalValueAccesser::getWorkFlag(object, 0x12000004)) {
            work.onFlag(0x22000012);
        } else {
            work.offFlag(0x22000012);
        }
    }
    if (!work.isFlag(0x22000011)) {
        int timer = work.getInt(0x20000001);
        if (timer <= soValueAccesser::getConstantInt(accesser, 0x5dc6, 0)) {
            PikachuLinkEvent event;
            accesser->getLinkModule().sendEventNodes(3, event, 0);
            work.setFloat(lbl_98_rodata_90, 0x21000004);
            work.onFlag(0x22000011);
        }
    }
}
