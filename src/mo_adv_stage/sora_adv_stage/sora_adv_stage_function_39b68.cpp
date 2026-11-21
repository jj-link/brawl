#pragma force_active on
#include <types.h>
#include <gr/gr_gimmick.h>

extern "C" {
void disableAttack__10grYakumonoFUl(void*, u32);
void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    void*, int, int, u32, grGimmick::AttackData*, grGimmick::AttackDetails*);
extern const f32 lbl_40_rodata_7D0;
extern char lbl_40_data_126C8[];
}
struct grYakumonoBase { char pad[0x3c]; };
struct grYakumonoSub {
    char pad[0x1ec];
    char attack[0x50];
    s32 node;
};
class grYakumono : public grYakumonoBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual s32 slot47(u32, const char*);
    char pad40[0x140];
    grYakumonoSub* data;
};
inline void initDetails(grGimmick::AttackDetails* det, f32 hitStop) {
    det->m_targetCategory = (soCollision::CategoryMask)0x3ff;
    det->m_unk1 = 0;
    det->m_targetSituationODD = false;
    det->m_lrCheck = (soCollisionAttackData::LrCheck)0;
    det->m_hitStopFrame = hitStop;
}
extern "C" void fn_40_39B68(grYakumono* self) {
    grGimmick::AttackDetails det;
    initDetails(&det, lbl_40_rodata_7D0);
    disableAttack__10grYakumonoFUl(self, 0);
    self->data->node = self->slot47(0, lbl_40_data_126C8);
    det.m_lrCheck = (soCollisionAttackData::LrCheck)3;
    det.m_targetSituationODD = true;
    setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        self, 0, 0, self->data->node, (grGimmick::AttackData*)self->data->attack, &det);
}