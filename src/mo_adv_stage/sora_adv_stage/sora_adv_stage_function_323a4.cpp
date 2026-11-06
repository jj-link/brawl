#pragma force_active on
#include <gr/gr_gimmick.h>

extern "C" void fn_40_23EC0(void*);
extern "C" char lbl_40_data_6380[];
extern const float lbl_40_rodata_628;
extern const float lbl_40_rodata_62C;

struct GimmickData { char pad[0x18]; int effectId; };
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
virtual void processDefault();
virtual void processBegin();
virtual void processAnim();
virtual void processUpdate();
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
virtual void fn_40_32740();
virtual void fn_40_3254C();
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
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void getModelCount();
virtual void fn_40_323A4();
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
char pad40[0xa8-0x40];
grGimmick::Effect_Info* sound;
char padAC[4];
grGimmick::Effect_Info* effect;
char padB4[0x15c-0xb4];
GimmickData* data;

inline void setSound(int id, Vec2f offset) {
    sound->m_id = id;
    sound->m_repeatFrame = 0;
    sound->m_nodeIndex = 0;
    sound->m_endFrame = 0;
    sound->m_offsetPos = offset;
}
inline void setEffect(int id, Vec2f offset) {
    if (id > 0) {
        effect->m_id = id;
        effect->m_repeatFrame = 0;
        effect->m_nodeIndex = getNodeIndex(0, lbl_40_data_6380);
        effect->m_endFrame = 0;
        effect->m_offsetPos = offset;
        effect->m_scale = lbl_40_rodata_62C;
    }
}
inline void setDefaultEffect(int id, const Vec2f& input) {
    Vec2f offset;
    Vec2f::copy(offset, input);
    if (id > 0) {
        effect->m_id = id;
        effect->m_repeatFrame = 0;
        effect->m_nodeIndex = getNodeIndex(0, lbl_40_data_6380);
        effect->m_endFrame = 0;
        effect->m_offsetPos = offset;
        effect->m_scale = lbl_40_rodata_62C;
    }
}
};

struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_40_2024();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void fn_40_21B8();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void fn_40_222C();
    virtual void renderPre();
    virtual void fn_40_8A84();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_12F8();
    virtual void fn_40_D24();
    virtual void createObjPokeTrainer();
    virtual void fn_40_5098();
    virtual void fn_40_50A0();
    virtual void fn_40_50BC();
    virtual void fn_40_8B18();
    virtual void fn_40_8B28();
    virtual void fn_40_7D94();
    virtual void fn_40_8154();
    virtual void fn_40_80AC();
    virtual void fn_40_8160();
    virtual void fn_40_8478();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();
    virtual void debugCollision();
    virtual void fn_40_6FF4();
    virtual void fn_40_8B10();
    virtual void getZoneLightSetIndex();
    virtual void fn_40_8AF4();
    virtual void clearCameraParam();
    virtual void fn_40_6C6C();
};

struct grGimmickWarpZone_base { char pad[0x3c]; };
class grGimmickWarpZone : public grGimmickWarpZone_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_40_37EA8();
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
    virtual void fn_40_37E50();
    virtual void update();
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
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
};
extern "C" void fn_40_323A4(grYakumono* self) {
fn_40_23EC0(self);
self->setSound(0x2274, Vec2f(lbl_40_rodata_628, lbl_40_rodata_628));
int id = self->data->effectId;
if (id > 0) {
 self->setEffect(id, Vec2f(lbl_40_rodata_628, lbl_40_rodata_628));
} else {
 self->setDefaultEffect(0x01030037, Vec2f(lbl_40_rodata_628, lbl_40_rodata_628));
}
}
