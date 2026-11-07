#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct Param { char pad[0x58]; float time; };
struct Vec { float x,y,z; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
#define V(n) virtual void n();
V(processDefault) V(processBegin) V(processAnim) V(processUpdate)
V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision)
V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera)
V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu)
V(processDebug) V(renderDebug) V(init) V(fn_50_9F4C) V(fn_50_9FD0) V(loadGroundData)
V(bindData) V(setupMelee) V(setVisibility) V(setVisibilityByClipping) V(setVisibilityAttachedEffect)
V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall)
V(receiveCollMsg_Attack) V(unloadData) V(fn_50_2324) V(startup) V(setNode) V(fn_50_690)
virtual Param* fn_50_231C();
V(fn_50_2318) V(fn_50_1F70) V(fn_50_2310) V(fn_50_2304) V(fn_50_22F4) V(fn_50_22E4)
V(getNodeIndex) V(getNodePosition) V(getNodePosition_2) V(getNodeMatrix) V(getNodeMatrix_2)
V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible)
V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2) V(setValid)
V(setValidAttachedEffect) V(fn_50_22E0) V(fn_50_22DC) V(fn_50_22D4) V(setMotionRatio)
V(setMotionFrame) V(getMotionFrame) V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha)
V(updateG3dProcCalcWorld) V(preExit) V(fn_50_22CC) V(invalidatedByCameraClipping)
V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode)
V(fn_50_182C) V(fn_50_2348) V(changeNodeAnim) V(createFadeVisibleProduction)
V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel)
V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency)
V(fn_50_2340) V(onDamage) V(onInflict) V(onInflictEach) V(onGimmickEvent)
V(enableYakumono) V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack)
V(enableArea) V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono)
V(getTeamYakumono) V(setOffsetAttack) V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet10soAreaDataP10ykAreaDatab)
V(setAttackGimmick) V(setSoCollisionAttackData) V(setAttackGimmickDetails)
V(isEnableAttackPersonAttacked) V(isEnableAttackAttribute) V(fn_50_20F4) V(fn_50_A5B0)
V(fn_50_A068) V(fn_50_A0D4)
virtual void fn_50_A32C(float);
virtual void fn_50_A490(float);
V(fn_50_A70C) V(fn_50_AAA8) V(fn_50_ABFC)
#undef V
char pad40[0x110];
unsigned char state;
char pad151[3];
float timer;
char pad158[0xc];
Vec* pos;
unsigned char* trigger;
Vec current;
Vec target;
char pad184[0xc];
unsigned char mode;
};
extern "C" const float lbl_50_rodata_15C;
inline bool isZero(const Vec& v) {
            bool zero = false;
            bool x = false;
            float ax = (float)(double)nw4r::math::FAbs(v.x);
            if (ax < lbl_50_rodata_15C) x = true;
            if (x) {
                bool y = false;
                if ((float)(double)nw4r::math::FAbs(v.y) < lbl_50_rodata_15C) y = true;
                if (y) {
                    bool z = false;
                    if ((float)(double)nw4r::math::FAbs(v.z) < lbl_50_rodata_15C) z = true;
                    if (z) zero = true;
                }
            }
            return zero;
}
extern "C" {
extern const float lbl_50_rodata_158;
extern const float lbl_50_rodata_15C;
void fn_50_A0D4(Ground* self, float delta) {
    Param* p = self->fn_50_231C();
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_50_rodata_158)
            self->timer = lbl_50_rodata_158;
        switch (self->state) {
        case 0: {
            self->current = *self->pos;
            bool zero = isZero(self->current);
            if (!zero && *self->trigger == 3)
                self->state = 1;
            break;
        }
        case 1:
            self->fn_50_ABFC();
            self->timer = p->time;
            self->state = 8;
            break;
        case 8:
            switch (self->mode) {
            case 0:
                self->fn_50_A32C(delta);
                if (lbl_50_rodata_158 == self->timer)
                    self->state = 1;
                break;
            case 1:
                self->fn_50_A32C(delta);
                if (self->current.x == self->target.x) {
                    self->fn_50_A490(delta);
                    if (self->current.y == self->target.y && lbl_50_rodata_158 == self->timer)
                        self->state = 1;
                }
                break;
            }
            break;
        }
    }
}
}