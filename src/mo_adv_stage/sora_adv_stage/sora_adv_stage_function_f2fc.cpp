#include <gr/gr_gimmick_motion_path.h>
#pragma force_active on

struct Stage_base { char pad[0x3c]; };
#define V(name) virtual void name();
class Stage : public Stage_base {
public:
    V(processDefault) V(processBegin) V(fn_40_2024) V(processUpdate)
    V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition)
    V(processPreCollision) V(processCollision) V(processCatch) V(processHit)
    V(processCamera) V(fn_40_21B8) V(processEffect) V(processGameProc)
    V(fn_40_222C) V(renderPre) V(fn_40_8A84) V(renderXlu) V(processDebug)
    V(renderDebug) V(init) V(fn_40_12F8) V(fn_40_D24) V(createObjPokeTrainer)
    V(fn_40_5098) V(fn_40_50A0) V(fn_40_50BC) V(fn_40_8B18) V(fn_40_8B28)
    V(fn_40_7D94) V(fn_40_8154) V(fn_40_80AC) V(fn_40_8160) V(fn_40_8478)
    V(initializeStage) V(closeStage) V(renderDebugPositions) V(fn_40_45C)
    V(process) V(fn_40_7D44) V(debugCollision) V(fn_40_6FF4) V(fn_40_8B10)
    V(getZoneLightSetIndex) V(fn_40_8AF4) V(clearCameraParam) V(fn_40_6C6C)
    V(fn_40_464) V(fn_40_5EC) V(fn_40_990) V(fn_40_A7C) V(fn_40_B98)
    V(fn_40_5FD8) V(fn_40_6050) V(isReStartSamePoint) V(getPokeTrainerStartPos)
    V(getItemPosCount) V(getItemPos) V(getRandItemPos) V(getKirifudaPos)
    V(getKirifudaAngle) V(getKirifudaScale) V(getKirifudaModelType)
    V(getPokeTrainerPosCount) V(getPokeTrainerPos) V(fn_40_7034) V(fn_40_70B4)
    V(getEnableZ) V(fn_40_8AEC) V(fn_40_76F8) V(fn_40_76E0) V(fn_40_8AE4)
    V(fn_40_8ADC) V(fn_40_8AC8) V(fn_40_8AB8) V(fn_40_774C) V(fn_40_77DC)
    V(fn_40_783C) V(fn_40_8AB0) V(fn_40_8AA8) V(fn_40_7A94) V(isEnd)
    V(isEventEnd) V(enableDevil) V(disableDevil) V(isDevil) V(setDevilScrool)
    V(getLucarioFinalTechniquePosition) V(startAppear) V(setAppearKind)
};
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
    V(slot0) V(slot1) V(slot2) V(slot3) V(slot4) V(slot5) V(slot6) V(slot7)
    V(slot8) V(slot9) V(slot10) V(slot11) V(slot12) V(slot13) V(slot14)
    V(slot15) V(slot16) V(slot17) V(slot18) V(slot19) V(slot20) V(slot21)
    V(slot22) V(slot23) V(slot24) V(slot25) V(slot26) V(slot27) V(slot28)
    V(slot29) V(slot30) V(slot31) V(slot32) V(slot33) V(slot34) V(slot35)
    V(slot36) V(slot37) V(slot38) V(slot39) V(slot40) V(slot41) V(slot42)
    V(slot43) V(slot44) V(slot45) V(slot46) V(slot47) V(slot48) V(slot49)
    V(slot50) V(slot51) V(slot52) V(slot53)
    V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision)
    V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2)
    V(slot60) V(slot61) V(slot62) V(slot63) V(slot64)
    V(setMotionRatio) V(setMotionFrame) V(getMotionFrame) V(setMotionLoop)
    V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld)
    V(slot72) V(slot73) V(slot74)
    V(setTransparencyFlag) V(updateCallback) V(fixedPosition)
    V(setTgtNode) V(getTgtNode) V(setGimmickData) V(getGimmickData)
    V(changeNodeAnim) V(createFadeVisibleProduction)
    V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel)
    V(slot86) V(slot87) V(slot88) V(getTransparencyFlag) V(slot90)
};
struct grGimmickWarpZone_base { char pad[0x3c]; };
class grGimmickWarpZone : public grGimmickWarpZone_base {
public:
    V(processDefault) V(processBegin) V(processAnim) V(processUpdate)
    V(processPreMapCorrection) V(processMapCorrection) V(fn_40_37EA8)
    V(processPreCollision) V(processCollision) V(processCatch) V(processHit)
    V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc)
    V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug)
    V(renderDebug) V(init) V(fn_40_37E50) V(update) V(loadGroundData)
    V(bindData) V(setupMelee) V(setVisibility) V(setVisibilityByClipping)
    V(setVisibilityAttachedEffect) V(receiveCollMsg) V(receiveCollMsg_Landing)
    V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack)
    V(unloadData) V(getModelCount) V(startup) V(setNode) V(setStageData)
    V(getStageData) V(initStageData) V(setMdlIndex) V(getMdlIndex)
    V(isEnableCalcCollision) V(enableCalcCollision) V(disableCalcCollision)
    V(getNodeIndex) V(getNodePosition) V(getNodePosition_2)
    V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility)
    V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible)
    V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2)
    V(setValid) V(setValidAttachedEffect) V(setInitializeFlag)
    V(setInitializeInfo) V(getInitializeInfo) V(setMotionRatio)
    V(setMotionFrame) V(getMotionFrame) V(setMotionLoop)
    V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld)
    V(preExit) V(adventureEventGetItem) V(invalidatedByCameraClipping)
    V(setTransparencyFlag) V(updateCallback) V(fixedPosition)
    V(setTgtNode) V(getTgtNode) V(setGimmickData) V(getGimmickData)
    V(changeNodeAnim) V(createFadeVisibleProduction)
    V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel)
    V(setSimpleEffectVisibleProduction)
    V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency)
    V(getTransparencyFlag) V(onDamage)
};
#undef V

extern float lbl_27_data_547E0;
extern "C" void fn_40_54F0(void*, int);
extern "C" void fn_40_4FE0(void*, Vec3f*);
extern "C" void fn_40_55BC(void*, Vec3f*);
struct Params {
    char pad[0x10];
    float delay;
};
struct Self {
    char pad[0x0c];
    void* object;
    grGimmickMotionPath* path;
    grGimmickMotionPath* otherPath;
    Params* params;
    unsigned char state;
    float frame;
};
extern "C" void fn_40_F2FC(Self* self) {
    Vec3f pos;
    if (self->state == 1) {
        float delta = lbl_27_data_547E0;
        self->frame += delta;
        if (self->frame > self->params->delay) {
            self->state = 2;
            fn_40_54F0(self->object, 0);
            self->path->startMove();
            if (self->otherPath) {
                self->otherPath->startMove();
                pos = self->otherPath->getPos();
                fn_40_4FE0(self->object, &pos);
            }
        }
    }
    if (self->state == 2) {
        pos = self->path->getPos();
        fn_40_55BC(self->object, &pos);
        if (self->otherPath) {
            pos = self->otherPath->getPos();
            fn_40_4FE0(self->object, &pos);
        }
        if (self->path->isMoveEnd()) {
            self->state = 3;
        }
    }
}
