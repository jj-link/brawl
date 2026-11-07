#include <gr/gr_gimmick.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on
extern "C" const float lbl_40_rodata_4F0[];
struct Base { char pad[0x3c]; };
class grYakumono : public Base {
public:
#define V(x) virtual void x();
V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection) V(processMapCorrection) V(fn_40_2D3A8) V(processPreCollision) V(processCollision) V(processCatch)
V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug)
V(renderDebug) V(init) V(fn_40_2C708) V(fn_40_2D248) V(loadGroundData) V(bindData) V(setupMelee) V(setVisibility) V(fn_40_2DA58) V(fn_40_2DAAC)
V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack) V(unloadData) V(getModelCount) V(fn_40_2C760) V(setNode) V(setStageData)
V(getStageData) V(initStageData) V(setMdlIndex) V(getMdlIndex) V(isEnableCalcCollision) V(enableCalcCollision) V(disableCalcCollision) V(getNodeIndex) V(getNodePosition) V(getNodePosition_2)
V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2)
V(setValid) V(setValidAttachedEffect) V(fn_40_2D1AC) V(setInitializeInfo) V(getInitializeInfo) V(setMotionRatio) V(setMotionFrame) V(getMotionFrame) V(setMotionLoop) V(setMatAlphaMul)
V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(adventureEventGetItem) V(invalidatedByCameraClipping) V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode)
V(setGimmickData) V(getGimmickData) V(changeNodeAnim) V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(getTransparencyFlag)
V(onDamage) V(onInflict) V(onInflictEach) V(fn_40_2D8F4) V(enableYakumono) V(disableYakumono) V(enableHit) V(disableHit)
virtual void disableAttack(unsigned long);
#undef V
};
extern "C" void fn_40_2D248(grYakumono* obj, float delta) {
    unsigned char* s = (unsigned char*)obj;
    const float* k = lbl_40_rodata_4F0;
    ((grGimmick*)obj)->grGimmick::update(delta);
    if (s[0x170]) *(float*)(s+0x160) -= k[13];
    else *(float*)(s+0x160) += k[13];
    if (*(float*)(s+0x160) < k[11]) {
        if (s[0x1c0]) {
            ((grGimmick*)obj)->startGimmickSE(0);
            s[0x170] = 0;
        }
        *(float*)(s+0x160) = k[11];
    }
    if (*(float*)(s+0x160) > k[0]) *(float*)(s+0x160) = k[0];
    unsigned char* p = *(unsigned char**)(s+0xd4);
    *(float*)(p+0x94) = *(float*)(s+0x160);
    *(float*)(p+0x98) = *(float*)(s+0x164);
    *(float*)(p+0x9c) = *(float*)(s+0x168);
    if (s[0x158] == 3) {
        obj->disableAttack(0);
        *(unsigned long*)(s+0x154) = 1;
        g_gfSceneRoot->remove(*(nw4r::g3d::ScnMdl**)(*(char**)(s+0x44)));
        *(unsigned long*)(*(char**)(s+0xd4)+0x84) = 0;
        g_gfSceneRoot->add(gfSceneRoot::Layer_Ground, *(nw4r::g3d::ScnMdl**)(*(char**)(s+0x44)+4));
        ((grGimmick*)obj)->startGimmickSE(8);
        ((grGimmick*)obj)->startGimmickEffect(5);
        s[0x158] = 4;
    }
    ((grGimmick*)obj)->grGimmick::updateCallback(*(unsigned long*)(s+0x154));
}