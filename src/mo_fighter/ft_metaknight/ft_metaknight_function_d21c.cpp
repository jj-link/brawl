#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" const float lbl_111_rodata_40;
extern "C" const char lbl_111_data_14C8[];
extern "C" const char lbl_111_data_1D44[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_111_D460(void*, void*, s32, void*);
extern "C" void fn_111_D9D0(void*);
extern "C" void fn_111_DA68(void*);

struct AttackData {
    int m_power;
    float position[3];
    float size;
    int m_vector, m_reactionEffect, m_reactionFix, m_reactionAdd;
    float slipChance, hitStopFrame, hitStopDelay;
    unsigned int : 27;
    unsigned int m_attribute : 5;
    unsigned int m_soundLevel : 2;
    unsigned int m_soundAttribute : 5;
    unsigned int : 25;
    unsigned int : 19;
    unsigned int m_lrCheck : 3;
    unsigned int : 2;
    unsigned int m_noHitStop : 1;
    unsigned int m_noEffect : 1;
    unsigned int : 6;
};

struct AbsoluteData {
    int power, vector, reactionEffect, reactionFix, reactionAdd;
    float slipChance, hitStopFrame, hitStopDelay;
    unsigned int attribute : 5;
    unsigned int soundLevel : 2;
    unsigned int soundAttribute : 5;
    unsigned int lrCheck : 3;
    unsigned int noHitStop : 1;
    unsigned int noEffect : 1;
    unsigned int flag0 : 1;
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
    unsigned int flag5 : 1;
    unsigned int : 9;

    AbsoluteData() {
        slipChance = lbl_111_rodata_40;
        hitStopFrame = lbl_111_rodata_40;
        hitStopDelay = lbl_111_rodata_40;
        flag0 = false;
        flag1 = false;
        flag2 = false;
        flag3 = false;
        flag4 = false;
        flag5 = false;
    }
};

class ChildObject {
public:
    char data[0x3C];
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34() = 0;
    virtual void slot35() = 0;
    virtual void slot36() = 0;
    virtual void slot37() = 0;
    virtual void slot38() = 0;
    virtual void slot39() = 0;
    virtual void slot40() = 0;
    virtual bool isActive() = 0;
};

extern "C" void fn_111_D21C(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000011)) {
        accesser->getWorkManageModule().offFlag(0x22000011);
        AttackData* source = reinterpret_cast<AttackData*>(
            accesser->getCollisionAttackModule().getData(0, true));
        AbsoluteData data;
        data.power = source->m_power;
        data.vector = source->m_vector;
        data.reactionEffect = source->m_reactionEffect;
        data.reactionFix = source->m_reactionFix;
        data.reactionAdd = source->m_reactionAdd;
        data.attribute = source->m_attribute;
        data.soundLevel = source->m_soundLevel;
        data.soundAttribute = source->m_soundAttribute;
        data.lrCheck = source->m_lrCheck;
        data.noHitStop = source->m_noHitStop;
        data.noEffect = source->m_noEffect;

        for (int i = 6; i < 12; ++i) {
            if (accesser->getLinkModule().isLink(i) == true) {
                int index = i - 6;
                ChildObject* object = static_cast<ChildObject*>(__dynamic_cast(
                    accesser->getLinkModule().getParent(i), 0x3C,
                    lbl_111_data_14C8, lbl_111_data_1D44, 0));
                if (object && object->isActive() == true) {
                    accesser->getCollisionAttackModule().setAbsolute(
                        index, 0,
                        reinterpret_cast<soCollisionAttackAbsoluteData*>(&data));
                    fn_111_D460(self, object, index, accesser);
                }
            }
        }

        fn_111_D9D0(accesser);
        fn_111_DA68(accesser);
    }
}
