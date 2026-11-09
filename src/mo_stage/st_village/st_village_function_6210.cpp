#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on

extern "C" {
extern const float lbl_70_rodata_D0[];
}

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
#define V(name) virtual void name();
    V(processDefault)
    V(processBegin)
    V(processAnim)
    V(processUpdate)
    V(processPreMapCorrection)
    V(processMapCorrection)
    V(processFixPosition)
    V(processPreCollision)
    V(processCollision)
    V(processCatch)
    V(processHit)
    V(processCamera)
    V(processFixCamera)
    V(processEffect)
    V(processGameProc)
    V(processEnd)
    V(renderPre)
    V(renderOpa)
    V(renderXlu)
    V(processDebug)
    V(renderDebug)
    V(init)
    V(fn_70_6108)
    V(fn_70_6180)
    V(loadGroundData)
    V(bindData)
    V(setupMelee)
    virtual void setVisibility(unsigned long);
    V(setVisibilityByClipping)
    V(setVisibilityAttachedEffect)
    V(receiveCollMsg)
    V(receiveCollMsg_Landing)
    V(receiveCollMsg_Heading)
    V(receiveCollMsg_Wall)
    V(receiveCollMsg_Attack)
    V(unloadData)
    V(fn_70_22A8)
    V(startup)
    V(setNode)
    V(fn_70_78C)
    virtual int fn_70_22A0();
    V(fn_70_229C)
    V(fn_70_2080)
    V(fn_70_2294)
    V(fn_70_2288)
    V(fn_70_2278)
    V(fn_70_2268)
    V(getNodeIndex)
    virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
    V(getNodePosition_2)
    V(getNodeMatrix)
    V(getNodeMatrix_2)
    V(setNodeVisibility)
    V(setNodeVisibility_2)
    V(setNodeVisibilityAll)
    V(isNodeVisible)
    V(setNodeCollision)
    V(setNodeCollision_2)
    V(getNodeScale)
    V(getNodeScale_2)
    V(setValid)
    V(setValidAttachedEffect)
    V(fn_70_2264)
    V(fn_70_2260)
    V(fn_70_2258)
    V(fn_70_15C4)
    V(setMotionFrame)
    virtual float getMotionFrame(unsigned long);
    V(setMotionLoop)
    V(setMatAlphaMul)
    V(setMatAlpha)
    V(updateG3dProcCalcWorld)
    V(preExit)
    V(fn_70_2250)
    V(invalidatedByCameraClipping)
    V(setTransparencyFlag)
    V(updateCallback)
    V(fixedPosition)
    V(setTgtNode)
    V(getTgtNode)
    V(fn_70_22D4)
    V(fn_70_22CC)
    V(changeNodeAnim)
    V(createFadeVisibleProduction)
    V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel)
    V(setSimpleEffectVisibleProduction)
    V(dbDispInvalidatedByCameraClippingSphere)
    V(setTransparency)
    V(fn_70_22C4)
    V(onDamage)
    V(onInflict)
    V(onInflictEach)
    V(onGimmickEvent)
    V(enableYakumono)
    V(disableYakumono)
    V(enableHit)
    V(disableHit)
    V(disableAttack)
    V(enableArea)
    V(disableArea)
    V(setSleepArea)
    V(setTeamYakumonoOwnerId)
    V(setTeamYakumono)
    V(getTeamYakumono)
    V(setOffsetAttack)
    V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab)
    V(setAttackGimmick)
    V(setSoCollisionAttackData)
    V(setAttackGimmickDetails)
    V(isEnableAttackPersonAttacked)
    V(isEnableAttackAttribute)
    V(fn_70_21B0)
    V(fn_70_794)
    V(fn_70_79C)
    V(fn_70_7A4)
    V(fn_70_7AC)
    virtual unsigned int fn_70_2208();
    V(fn_70_620C)
    V(fn_70_6210)
    V(fn_70_64E8)
    virtual void fn_70_64EC(int, int, int, float*);
#undef V

    char pad40[0x2c];
    unsigned char flag;
    char pad6d[0x57];
    unsigned long node;
    char padc8[0x88];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[8];
    unsigned char* trigger;
    char pad164[4];
    char kind;
    unsigned char initializeSound;
    char pad16a[2];
    float previousFrame;
    float endFrame;
    char seqStorage[0x3c];
    SndID soundId;
    StSeUtil::UnkStruct soundEntry;
    char generatorStorage[0x20];
};

#define SEQ reinterpret_cast<StSeUtil::SeSeq*>(self->seqStorage)
#define GENERATOR reinterpret_cast<snd3DGenerator*>(self->generatorStorage)

extern "C" void fn_70_6210(Ground* self, float delta) {
    const float* constants = lbl_70_rodata_D0;
    if (self->trigger != 0 && self->fn_70_22A0() != 0) {
        self->timer -= delta;
        if (self->timer < constants[0])
            self->timer = constants[0];

        switch (self->state) {
        case 0:
            self->fn_70_64EC(4, 0, 1, 0);
            self->setVisibility(0);
            if (self->initializeSound == 1) {
                switch (self->kind) {
                case 3:
                    self->soundId = (SndID)0x1cf9;
                    self->soundEntry.id = (SndID)0x1cf9;
                    self->soundEntry.unk4 = constants[0];
                    self->soundEntry.unk8 = constants[1];
                    self->soundEntry.unkC = constants[2];
                    SEQ->registId(&self->soundId, 1);
                    SEQ->registSeq(0, &self->soundEntry, 1,
                                   (Heaps::HeapType)15);
                    SEQ->m_sndGenerator = GENERATOR;
                    break;
                }
                self->initializeSound = 0;
            }
            self->state = 1;
            break;

        case 1:
            if (self->trigger != 0 && *self->trigger == 4) {
                self->fn_70_64EC(0, 0, 1, &self->endFrame);
                self->state = 4;
                self->previousFrame = constants[0];
                switch (self->kind) {
                case 3:
                    SEQ->playFrame(0, self->getMotionFrame(0),
                                   constants[0]);
                    break;
                }
            }
            break;

        case 4:
            if (self->fn_70_2208() == 1 && ((self->flag >> 7) & 1) == 0)
                self->setVisibility(1);
            switch (self->kind) {
            case 3: {
                SEQ->playFrame(0, self->getMotionFrame(0));
                Vec3f pos;
                self->getNodePosition(&pos, 0, self->node);
                GENERATOR->setPos(&pos);
                break;
            }
            }
            if (self->getMotionFrame(0) >= self->endFrame) {
                *self->trigger = 6;
                self->state = 0;
            }
            break;
        }
    }
}

#undef SEQ
#undef GENERATOR
