#include <gf/gf_task_scheduler.h>
#include <so/so_module_accesser.h>
#pragma force_active on

#define P(i) virtual void pad##i();

struct ReactionAccumulator {
    unsigned char prefix[0xC0];
    float maxPower;
    int maxReaction;
};

// Same field layout as the Ness collision record (offsets 0x21, 0x22, 0x25, 0x27 are used here).
struct ReactionCollision {
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

class ReactionHitView {
public:
    P(0) P(1) P(2) P(3) P(4) P(5) P(6) P(7) P(8) P(9) P(10) P(11)
    P(12) P(13) P(14) P(15) P(16) P(17) P(18) P(19) P(20) P(21) P(22) P(23)
    P(24) P(25) P(26) P(27) P(28) P(29) P(30) P(31) P(32) P(33) P(34) P(35)
    P(36) P(37) P(38) P(39) P(40) P(41) P(42) P(43) P(44) P(45)
    virtual unsigned int isReactionFrame();
    virtual int getReactionFrame();
};

class SituationView {
public:
    P(0) P(1) P(2)
    virtual int check();
};

class AttackModuleView {
public:
    P(0) P(1) P(2) P(3) P(4) P(5) P(6) P(7) P(8) P(9) P(10) P(11)
    P(12) P(13) P(14) P(15) P(16) P(17) P(18) P(19) P(20) P(21) P(22) P(23)
    P(24) P(25) P(26) P(27) P(28) P(29) P(30) P(31) P(32) P(33) P(34) P(35)
    P(36) P(37) P(38) P(39) P(40) P(41)
    virtual soCollisionAttackData* getData(unsigned char index, bool absolute);
    P(45) P(46) P(47) P(48) P(49) P(50) P(51) P(52) P(53) P(54) P(55) P(56)
    P(57) P(58) P(59) P(60) P(61) P(62) P(63) P(64) P(65) P(66) P(67) P(68) P(69)
    virtual int checkRebound(soModuleAccesser* accesser, void* obj,
                             const ReactionCollision* collision,
                             float power, float* upper, float* lower);
};

extern "C" {
extern char __RTTI__11StageObject[];
extern char lbl_41_data_1630[];
extern const float lbl_41_rodata_14;
extern const float lbl_41_rodata_18;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_63738(soModuleAccesser*, soCollisionAttackData*, float, float, float, int);
void* fn_27_8CD54(void*);
}

static AttackModuleView* attackModuleOf(soModuleAccesser* accesser) {
    return *reinterpret_cast<AttackModuleView* const*>(
        reinterpret_cast<const unsigned char*>(accesser->m_enumerationStart) + 0x1C);
}

static SituationView* situationOf(soModuleAccesser* accesser) {
    return *reinterpret_cast<SituationView* const*>(
        reinterpret_cast<const unsigned char*>(accesser->m_enumerationStart) + 0x14);
}

extern "C" void fn_41_A494(ReactionAccumulator* self, float power,
                           const ReactionCollision* collision, soModuleAccesser* accesser) {
    gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
        static_cast<gfTask::Category>(collision->category), collision->taskId);
    soCollisionAttackData* attack = attackModuleOf(accesser)->getData(collision->attackIndex, collision->absolute);
    int reaction = fn_27_63738(accesser, attack, power, lbl_41_rodata_14, lbl_41_rodata_14, 0);

    switch (collision->useReactionFrame) {
    case 1:
        if (task != 0) {
            void* cast = __dynamic_cast(task, 0x3C, __RTTI__11StageObject, lbl_41_data_1630, 1);
            ReactionHitView* hit = static_cast<ReactionHitView*>(fn_27_8CD54(cast));
            if (hit->isReactionFrame() == 1U) {
                reaction = hit->getReactionFrame();
            }
        }
        break;
    case 0:
        {
            if (situationOf(accesser)->check() == 0 && task != 0) {
                float upper = lbl_41_rodata_18;
                float lower = lbl_41_rodata_18;
                AttackModuleView* attackModule = attackModuleOf(accesser);
                void* cast = __dynamic_cast(task, 0x3C, __RTTI__11StageObject, lbl_41_data_1630, 1);
                if (attackModule->checkRebound(accesser, cast, collision, power, &upper, &lower) == 0) {
                    return;
                }
            }
        }
        break;
    default:
        break;
    }

    if (self->maxPower < power) {
        self->maxPower = power;
    }
    if (self->maxReaction < reaction) {
        self->maxReaction = reaction;
    }
}
