#pragma pool_data on

#include <ec/ec_mgr.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" const float lbl_54_rodata_180[];
extern "C" char lbl_54_data_3150[];
extern "C" void fn_80075F1C(sndSystem*, int, int);

struct Ground_base {
    char pad[0x3c];
};

#define V(n) virtual void n();

class Ground : public Ground_base {
public:
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
    V(fn_54_E764)
    V(fn_54_E7D0)
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
    V(fn_54_338C)
    V(startup)
    V(setNode)
    V(fn_54_1310)
    V(fn_54_3150)
    V(fn_54_3388)
    V(fn_54_2C40)
    V(fn_54_3380)
    V(fn_54_3374)
    V(fn_54_3364)
    V(fn_54_3354)
    V(getNodeIndex)
    V(getNodePosition)
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
    V(fn_54_3350)
    V(fn_54_334C)
    V(fn_54_3344)
    V(setMotionRatio)
    V(setMotionFrame)
    virtual float getMotionFrame(unsigned long);
    V(setMotionLoop)
    V(setMatAlphaMul)
    V(setMatAlpha)
    V(updateG3dProcCalcWorld)
    V(preExit)
    V(fn_54_333C)
    V(invalidatedByCameraClipping)
    V(setTransparencyFlag)
    V(updateCallback)
    V(fixedPosition)
    V(setTgtNode)
    V(getTgtNode)
    V(fn_54_33B8)
    V(fn_54_33B0)
    V(changeNodeAnim)
    V(createFadeVisibleProduction)
    V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel)
    V(setSimpleEffectVisibleProduction)
    V(dbDispInvalidatedByCameraClippingSphere)
    V(setTransparency)
    V(fn_54_33A8)
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
    V(fn_54_1510)
    V(fn_54_EAD8)
    V(fn_54_E844)
    virtual void fn_54_EB80(int, int, int, float*);

    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char state;
    char pad151[7];
    unsigned char* command;
    char pad15c[8];
    float timer;
    char pad168[0x74];
    unsigned char soundState;
    char pad1dd[3];
    int sound;
};

#undef V

extern "C" void fn_54_E844(Ground* self, float delta) {
    self->timer -= delta;
    if (self->timer < 0.0f)
        self->timer = 0.0f;

    switch (self->state) {
    case 0:
        self->fn_54_EB80(0, 0, 1, 0);
        self->setVisibility(0);
        self->soundState = 0;
        self->sound = -1;
        self->state = 1;
        break;

    case 1:
        if (*self->command == 4) {
            self->fn_54_EB80(0, 0, 1, &self->timer);
            g_sndSystem->playSE((SndID)0x1bc8, 0, 0, 0, -1);
            g_ecMgr->setDrawPrio(1);
            unsigned long effect = g_ecMgr->setEffect((EfID)0x3c0002);
            g_ecMgr->setParent(effect, *self->model, lbl_54_data_3150, false);
            g_ecMgr->setEffect((EfID)0x3c0003);
            g_ecMgr->setDrawPrio(-1);
            self->state = 11;
        }
        break;

    case 11:
        self->setVisibility(1);
        switch (self->soundState) {
        case 0:
            if (self->getMotionFrame(0) > 180.0f) {
                self->sound = g_sndSystem->playSE((SndID)0x1bc9, 0, 0, 0, -1);
                self->soundState++;
            }
            break;

        case 1:
            if (self->getMotionFrame(0) > 460.0f) {
                if (self->sound != -1)
                    fn_80075F1C(g_sndSystem, self->sound, 0x5a);
                self->sound = -1;
                self->soundState++;
            }
            break;
        }

        if (0.0f == self->timer) {
            *self->command = 0;
            self->state = 0;
        }
        break;
    }
}
