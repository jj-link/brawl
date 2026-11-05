#include <gf/gf_task_scheduler.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct SamusReactionObserver {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

struct SamusReactionCollision {
    unsigned char prefix[0x0c];
    unsigned int taskId;
    unsigned char positionAndLife[0x11];
    unsigned char useReactionFrame;
    unsigned char category;
    unsigned char reserved[2];
    unsigned char attackIndex;
    unsigned char unused;
    bool absolute;
};

class SamusReactionHitView {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6C() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7C() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8C() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9C() = 0;
    virtual void slot_A0() = 0;
    virtual void slot_A4() = 0;
    virtual void slot_A8() = 0;
    virtual void slot_AC() = 0;
    virtual void slot_B0() = 0;
    virtual void slot_B4() = 0;
    virtual void slot_B8() = 0;
    virtual void slot_BC() = 0;
public:
    virtual bool isReactionFrame() = 0;
    virtual int getReactionFrame() = 0;
};

extern "C" {
extern const float lbl_94_rodata_88;
extern const char lbl_94_data_5010[], lbl_94_data_5110[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_63738(soModuleAccesser*, soCollisionAttackData*, float, float, float, int);
SamusReactionHitView* fn_27_8CD54(void*);
}

extern "C" void fn_94_1D4C0(SamusReactionObserver* observer, float power,
                            const SamusReactionCollision* collision, soModuleAccesser* attacker) {
    soWorkManageModule* work = observer->accesser->m_enumerationStart->m_workManageModule;
    float value = work->getFloat(0x11000001);
    if (value < power) {
        value = power;
    }
    work->setFloat(value, 0x11000001);

    gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
        static_cast<gfTask::Category>(collision->category), collision->taskId);
    soCollisionAttackData* attack = attacker->m_enumerationStart->m_collisionAttackModule->getData(
        collision->attackIndex, collision->absolute);
    int reaction = fn_27_63738(attacker, attack, power, lbl_94_rodata_88, lbl_94_rodata_88, 0);
    if (collision->useReactionFrame == 1 && task != 0) {
        SamusReactionHitView* hit = fn_27_8CD54(__dynamic_cast(task, 0x3c,
            lbl_94_data_5010, lbl_94_data_5110, static_cast<short>(1)));
        if (hit->isReactionFrame()) {
            reaction = hit->getReactionFrame();
        }
    }
    int previous = work->getInt(0x10000008);
    if (previous < reaction) {
        previous = reaction;
    }
    work->setInt(previous, 0x10000008);
}
