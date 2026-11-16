#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" char lbl_40_data_6380[];
extern "C" const float lbl_40_rodata_550;
extern "C" const float lbl_40_rodata_554;

struct EffectEntry {
    char pad[12];
    int id;
    unsigned long repeatFrame;
    unsigned long endFrame;
    short node;
    short generator;
    Vec2f offset;
    float scale;
};

struct grYakumono_base {
    char pad[0x3c];
};

class grYakumono : public grYakumono_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void fn_40_2EAF8();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_2ED44();
    virtual void fn_40_2EB0C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void fn_40_23644();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void fn_40_2E9C4();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual int getNodeIndex(unsigned long, const char*);

    char pad40[0xa8 - 0x40];
    EffectEntry* sound;
    char padAC[4];
    EffectEntry* effect;

    inline void setSound(int id, Vec2f offset) {
        sound->id = id;
        sound->repeatFrame = 0;
        sound->node = 0;
        sound->endFrame = 0;
        sound->offset = offset;
    }

    inline void setEffect(int id, Vec2f offset) {
        if (id > 0) {
            effect->id = id;
            effect->repeatFrame = 0;
            effect->node = getNodeIndex(0, lbl_40_data_6380);
            effect->endFrame = 0;
            effect->offset = offset;
            effect->scale = lbl_40_rodata_554;
        }
    }
};

extern "C" void fn_40_22F84(grYakumono*, void*, unsigned long);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" void changeNodeAnim__9grGimmickFUlUl(void*, unsigned long, unsigned long);

extern "C" void fn_40_2E9C4(grYakumono* self, void* archive, unsigned long flags) {
    fn_40_22F84(self, archive, flags | 0x108);
    setCalcuCallbackRoot__9grGimmickFUl(self, 8);
    self->setSound(0x2279, Vec2f(lbl_40_rodata_550, lbl_40_rodata_550));
    self->setEffect(0x01030022, Vec2f(lbl_40_rodata_550, lbl_40_rodata_550));
    changeNodeAnim__9grGimmickFUlUl(self, 0, 0);
}