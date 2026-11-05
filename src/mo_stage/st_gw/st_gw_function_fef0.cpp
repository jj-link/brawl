#pragma force_active on
#include <mt/mt_prng.h>

struct Params {
    char pad[0x54];
    float low;
    float high;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
#define V(n) virtual void n();
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
    V(fn_63_FCF4)
    V(fn_63_FD84)
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
    V(fn_63_3378)
    V(startup)
    V(setNode)
    V(fn_63_59C)
    virtual Params* fn_63_3370();
    V(fn_63_336C)
    V(fn_63_2B64)
    V(fn_63_3364)
    V(fn_63_3358)
    V(fn_63_3348)
    V(fn_63_3338)
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
    V(fn_63_3334)
    V(fn_63_3330)
    V(fn_63_3328)
    V(setMotionRatio)
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    V(setMotionLoop)
    V(setMatAlphaMul)
    V(setMatAlpha)
    V(updateG3dProcCalcWorld)
    V(preExit)
    V(fn_63_3320)
    V(invalidatedByCameraClipping)
    V(setTransparencyFlag)
    V(updateCallback)
    V(fixedPosition)
    V(setTgtNode)
    V(getTgtNode)
    V(fn_63_1884)
    V(fn_63_339C)
    V(changeNodeAnim)
    V(createFadeVisibleProduction)
    V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel)
    V(setSimpleEffectVisibleProduction)
    V(dbDispInvalidatedByCameraClippingSphere)
    V(setTransparency)
    V(fn_63_3394)
    V(onDamage)
    V(fn_63_10914)
    V(onInflictEach)
    V(onGimmickEvent)
    V(enableYakumono)
    V(disableYakumono)
    V(enableHit)
    V(disableHit)
    virtual void disableAttack(unsigned long);
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
    V(fn_63_2D00)
    V(fn_63_1027C)
    virtual void fn_63_2ED8(int, int, int, float*);
    V(fn_63_1CB4)
    V(fn_63_1CBC)
    V(fn_63_FE28)
    V(fn_63_FEF0)
    V(fn_63_10374)
    V(fn_63_10710)
#undef V

    char pad40[0x24];
    float speed;
    char pad68[4];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[8];
    float previous;
    float end;
    char pad168[0x10];
    unsigned char* trigger;
    unsigned char triggerValue;
    unsigned char selection;
    unsigned char pad17e;
    unsigned char repeat;
    unsigned char pad180;
    unsigned char attack;
};

struct Constants {
    float zero;
    float negative;
    float third;
    float twoThirds;
};

extern "C" const Constants lbl_63_rodata_108;

extern "C" void fn_63_FEF0(Ground* self, float delta) {
    const Constants* c = &lbl_63_rodata_108;
    Params* p = self->fn_63_3370();

    if (p) {
        self->timer -= delta;
        if (self->timer < c->zero)
            self->timer = c->zero;

        switch (self->state) {
        case 0:
            self->fn_63_2ED8(1, 0, 1, 0);
            self->setVisibility(0);
            if (self->attack == 1)
                self->disableAttack(0);
            self->attack = 0;
            self->state = 1;
            break;

        case 1:
            if (*self->trigger == self->triggerValue) {
                self->fn_63_2ED8(0, 1, 1, &self->end);
                self->setMotionFrame(self->end, 0);
                self->previous = self->end;
                if (self->speed > c->zero)
                    self->speed *= c->negative;
                self->repeat = 0;
                self->state = 3;
            }
            break;

        case 2:
            break;

        case 3:
            if (*self->trigger != self->triggerValue) {
                self->fn_63_2ED8(0, 0, 1, &self->end);
                if (self->speed < c->zero)
                    self->speed *= c->negative;
                self->disableAttack(0);
                self->attack = 0;
                self->state = 4;
            } else {
                if (!((self->flags >> 7) & 1))
                    self->setVisibility(1);

                if (self->repeat == 0) {
                    if (self->getMotionFrame(0) > self->previous) {
                        self->fn_63_2ED8(1, 0, 0, 0);
                        self->repeat = 1;
                        self->fn_63_10710();
                    } else {
                        self->previous = self->getMotionFrame(0);
                    }
                }

                if (c->zero == self->timer) {
                    float r = randf();
                    if (r < c->third)
                        self->selection = 0;
                    else if (r < c->twoThirds)
                        self->selection = 1;
                    else
                        self->selection = 2;

                    self->timer = p->low + (p->high - p->low) * randf();
                }
            }
            break;

        case 4:
            if (self->getMotionFrame(0) >= self->end)
                self->state = 0;
            break;
        }
    }
}
