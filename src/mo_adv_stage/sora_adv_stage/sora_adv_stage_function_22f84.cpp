#pragma force_active on

#include <types.h>
#include <gr/gr_gimmick.h>
#include <gf/gf_model.h>
#include <mt/mt_prng.h>

extern "C" {
void startup__9grGimmickFP9gfArchiveUlUl(void*, gfArchive*, u32, u32);
extern char lbl_40_data_6380[];
}

struct Data {
    char pad[0x24];
    u8 b24;
    char pad2[0xa];
    u8 b2f;
    int n30;
    int n34;
    int n38;
    int n3c;
};

struct grYakumono_base {
    char pad[0x3c];
};

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
    virtual void fn_40_22F2C();
    virtual void fn_40_2353C();
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
    virtual void fn_40_22F84();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual u32 getNodeIndex(u32, const char*);

    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    gfModelAnimation** anim;
    char pad4c[0x5c];
    grGimmick::Effect_Info* sound;
    char padac[4];
    grGimmick::Effect_Info* effect;
    char padb4[8];
    Data* data0;
    char padc0[0x90];
    float frame;
    Data* data;

    inline void setSound(int index, int id, Vec2f& input, Vec2f& offset) {
        input.m_x = 0.0f;
        input.m_y = 0.0f;
        Vec2f::copy(offset, input);
        sound[index].m_id = id;
        sound[index].m_repeatFrame = 0;
        sound[index].m_nodeIndex = 0;
        sound[index].m_endFrame = 0;
        sound[index].m_offsetPos = offset;
    }

    inline void setSoundIf(int index, int id, Vec2f& input, Vec2f& offset) {
        input.m_x = 0.0f;
        input.m_y = 0.0f;
        Vec2f::copy(offset, input);
        if (id > 0) {
            sound[index].m_id = id;
            sound[index].m_repeatFrame = 0;
            sound[index].m_nodeIndex = 0;
            sound[index].m_endFrame = 0;
            sound[index].m_offsetPos = offset;
        }
    }

    inline void setEffect(int index, int id, Vec2f& input, Vec2f& offset) {
        input.m_x = 0.0f;
        input.m_y = 0.0f;
        Vec2f::copy(offset, input);
        effect[index].m_id = id;
        effect[index].m_repeatFrame = 0;
        effect[index].m_nodeIndex = getNodeIndex(0, lbl_40_data_6380);
        effect[index].m_endFrame = 0;
        effect[index].m_offsetPos = offset;
        effect[index].m_scale = 1.0f;
    }

    inline void setEffectIf(int index, int id, Vec2f& input, Vec2f& offset) {
        input.m_x = 0.0f;
        input.m_y = 0.0f;
        Vec2f::copy(offset, input);
        if (id > 0) {
            effect[index].m_id = id;
            effect[index].m_repeatFrame = 0;
            effect[index].m_nodeIndex = getNodeIndex(0, lbl_40_data_6380);
            effect[index].m_endFrame = 0;
            effect[index].m_offsetPos = offset;
            effect[index].m_scale = 1.0f;
        }
    }
};

struct StartupOffsets {
    Vec2f defaultEffectOffset;
    Vec2f secondaryEffectOffset;
    Vec2f sound2263Offset;
    Vec2f sound2264Offset;
    Vec2f sound2265Offset;
    Vec2f sound2266Offset;
    Vec2f sound2267Offset;
    Vec2f sound2275Offset;
    Vec2f secondarySoundOffset;
    Vec2f secondaryEffectInput;
    Vec2f defaultEffectInput;
    Vec2f primaryEffectInput;
    Vec2f primaryEffectOffset;
    Vec2f secondarySoundInput;
    Vec2f sound2275Input;
    Vec2f sound2267Input;
    Vec2f sound2266Input;
    Vec2f sound2265Input;
    Vec2f sound2264Input;
    Vec2f sound2263Input;
    Vec2f primarySoundInput;
    Vec2f primarySoundOffset;
};

extern "C" void fn_40_22F84(
    grYakumono* self, gfArchive* archive, u32 a, u32 b
) {
    startup__9grGimmickFP9gfArchiveUlUl(self, archive, a, b);
    self->data = self->data0;

    if (self->data) {
        if (self->anim) {
            (*self->anim)->unbindNodeAnim(*self->model);
        }

        ((grGimmick*)self)->makeCalcuCallback(1, (HeapType)15);
        ((grGimmick*)self)->setCalcuCallbackRoot(1);
        ((grGimmick*)self)->createSoundWork(2, 1);
        ((grGimmick*)self)->createEffectWork(2);

        float rnd = randf();
        StartupOffsets offsets;

        if (self->data->n30 > 0) {
            self->setSoundIf(0, self->data->n30, offsets.primarySoundInput, offsets.primarySoundOffset);
        } else if (self->data->b2f == 0) {
            if (rnd < 0.5f) {
                self->setSound(0, 0x2263, offsets.sound2263Input, offsets.sound2263Offset);
            } else {
                self->setSound(0, 0x2264, offsets.sound2264Input, offsets.sound2264Offset);
            }
        } else if (self->data->b2f == 1) {
            if (rnd < 0.333f) {
                self->setSound(0, 0x2265, offsets.sound2265Input, offsets.sound2265Offset);
            } else if (randf() < 0.666f) {
                self->setSound(0, 0x2266, offsets.sound2266Input, offsets.sound2266Offset);
            } else {
                self->setSound(0, 0x2267, offsets.sound2267Input, offsets.sound2267Offset);
            }
        } else if (self->data->b2f == 2) {
            self->setSound(0, 0x2275, offsets.sound2275Input, offsets.sound2275Offset);
        }

        self->setSoundIf(1, self->data->n34, offsets.secondarySoundInput, offsets.secondarySoundOffset);

        if (self->data->n38 > 0) {
            self->setEffectIf(0, self->data->n38, offsets.primaryEffectInput, offsets.primaryEffectOffset);
        } else {
            self->setEffect(0, 0x0103001a, offsets.defaultEffectInput, offsets.defaultEffectOffset);
        }

        self->setEffectIf(1, self->data->n3c, offsets.secondaryEffectInput, offsets.secondaryEffectOffset);
        self->frame = (float)self->data->b24;
    }
}
