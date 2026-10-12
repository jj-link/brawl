#include <so/so_module_accesser.h>

// This copy view preserves the packed position words, rather than invoking
// Vec3f's component-wise assignment. The REL stores the same 64-byte record.
struct CaptainFinalPositionWords {
    unsigned int x, y, z;
    CaptainFinalPositionWords& operator=(const CaptainFinalPositionWords& value) {
        x = value.x;
        y = value.y;
        z = value.z;
        return *this;
    }
};

struct CaptainFinalAttackData {
    int power;
    CaptainFinalPositionWords offsetPosition;
    float size;
    int vector, reactionEffect, reactionFix, reactionAdd;
    float slipChance, hitStopFrame, hitStopDelay;
    unsigned int category, attribute, options, region;
    CaptainFinalAttackData(const CaptainFinalAttackData& value)
        : power(value.power), offsetPosition(value.offsetPosition), size(value.size),
          vector(value.vector), reactionEffect(value.reactionEffect),
          reactionFix(value.reactionFix), reactionAdd(value.reactionAdd),
          slipChance(value.slipChance), hitStopFrame(value.hitStopFrame),
          hitStopDelay(value.hitStopDelay), category(value.category),
          attribute(value.attribute), options(value.options), region(value.region) {}
    CaptainFinalAttackData& operator=(CaptainFinalAttackData value) {
        power = value.power;
        offsetPosition = value.offsetPosition;
        size = value.size;
        vector = value.vector;
        reactionEffect = value.reactionEffect;
        reactionFix = value.reactionFix;
        reactionAdd = value.reactionAdd;
        slipChance = value.slipChance;
        hitStopFrame = value.hitStopFrame;
        hitStopDelay = value.hitStopDelay;
        category = value.category;
        attribute = value.attribute;
        options = value.options;
        region = value.region;
        return *this;
    }
};

class CaptainFinalAttackModule {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void hitAbsolute(int, Vec3f*, unsigned int, int, int) = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void slot78() = 0;
    virtual void slot7C() = 0;
    virtual void slot80() = 0;
    virtual void slot84() = 0;
    virtual void slot88() = 0;
    virtual void slot8C() = 0;
    virtual void slot90() = 0;
    virtual void slot94() = 0;
    virtual void slot98() = 0;
    virtual void slot9C() = 0;
    virtual void slotA0() = 0;
    virtual void slotA4() = 0;
    virtual void slotA8() = 0;
    virtual void slotAC() = 0;
    virtual CaptainFinalAttackData* getData(int, bool) = 0;
};

// The final-hit records are shared with the neighboring Captain callbacks.
struct CaptainFinalHit {
    unsigned int taskId;
    int linkIndex;
    unsigned char reserved[0x1C];
    unsigned char active : 1;
    unsigned char unused : 1;
    unsigned char applied : 1;
    unsigned char remaining : 5;
    unsigned char padding[3];
};

struct CaptainFinalHitList {
    CaptainFinalHit* entries;
    unsigned int reserved[3];
};

struct CaptainFinalLinkEvent : soLinkEventArgs {
    int kind;
    // Other Captain event variants use this same 0x30-byte message.
    union {
        int attackId;
        unsigned char payload[0x24];
    };
    CaptainFinalLinkEvent() : soLinkEventArgs(0x44F), kind(8), attackId(1) {}
};

extern "C" {
extern CaptainFinalHitList lbl_100_bss_268;
extern CaptainFinalAttackData lbl_100_bss_278;
void fn_100_1084C(soModuleAccesser*);
}

static inline void captureFinalAttack(CaptainFinalAttackModule* attack) {
    lbl_100_bss_278 = *attack->getData(0, true);
}

static inline void applyFinalHit(soModuleAccesser* accesser,
        soWorkManageModule* work, CaptainFinalAttackModule* attack, CaptainFinalHit* hit,
        CaptainFinalLinkEvent& event) {
    accesser->m_enumerationStart->m_linkModule->sendEventParents(hit->linkIndex, event);
    int attackId = event.attackId;
    fn_100_1084C(accesser);
    Vec3f position;
    position.m_x = work->getFloat(0x21000004);
    position.m_y = work->getFloat(0x21000005);
    position.m_z = accesser->m_enumerationStart->m_groundModule->getZ();
    attack->hitAbsolute(0, &position, hit->taskId, 0, attackId);
    hit->applied = true;
}

extern "C" void fn_100_EFF0(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    CaptainFinalAttackModule* attack = reinterpret_cast<CaptainFinalAttackModule*>(
        accesser->m_enumerationStart->m_collisionAttackModule);
    if (!work->isFlag(0x22000012) && work->isFlag(0x22000011)) {
        captureFinalAttack(attack);
        work->onFlag(0x22000012);
    }
    int timer = work->getInt(0x20000002);
    work->incInt(0x20000002);
    if (timer >= 1 && work->isFlag(0x22000012)) {
        int count = work->getInt(0x20000000);
        CaptainFinalHit* hit = lbl_100_bss_268.entries;
        for (int i = 0; i < count; ++i, ++hit) {
            if (hit->active && !hit->applied && hit->taskId != 0xFFFFFFFF) {
                CaptainFinalLinkEvent event;
                applyFinalHit(accesser, work, attack, hit, event);
                break;
            }
        }
    }
}
