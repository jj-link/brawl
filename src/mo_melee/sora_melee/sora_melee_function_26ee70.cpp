#include <gf/gf_model.h>
#pragma force_active on

extern "C" {
void* fn_8018D174(void*, int);
void fn_801B0A28();
nw4r::g3d::ScnMdl* fn_801B0B40(MEMAllocator*, u32*, nw4r::g3d::ResMdl*, u32, int, void (*)());
gfModelAnimation* __ct__16gfModelAnimationFd(gfModelAnimation*, nw4r::g3d::ResFile*, nw4r::g3d::ResMdl*, bool, u32, Heaps::HeapType);
}

struct grGimmickMotionPath_base { char pad[0x3c]; };
class grGimmickMotionPath : public grGimmickMotionPath_base {
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
    virtual ~grGimmickMotionPath();
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
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void setInitializeFlag();
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fn_27_26E95C();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
    virtual unsigned char* getGimmickData();
    nw4r::g3d::ResFile m_resFile;
    nw4r::g3d::ScnMdl** m_sceneModels;
    gfModelAnimation** m_modelAnims;
    char pad4c[0xc];
    u32 m_modelAnimNum;
};

extern "C" void loadGroundData__19grGimmickMotionPathFUlUlUl(grGimmickMotionPath* self, u32 arg0, u32 arg1, u32 arg2) {
    unsigned char* data = self->getGimmickData();
    if (data) {
        gfModelAnimation* anim;
        nw4r::g3d::ScnMdl* scene;
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
        u32 size;
        nw4r::g3d::ResFile resFile((void*)arg0);
        self->m_resFile = resFile;
        self->m_modelAnimNum = self->m_resFile.GetResMdlNumEntries();
        self->m_sceneModels = new (Heaps::StageInstance) nw4r::g3d::ScnMdl*;
        self->m_modelAnims = new (Heaps::StageInstance) gfModelAnimation*;
        arg0 = (u32)fn_8018D174(&resFile, data[4]);
        nw4r::g3d::ResMdl model((void*)arg0);
        scene = fn_801B0B40(allocator, &size, &model, arg1, 1, fn_801B0A28);
        anim = (gfModelAnimation*)operator new(0x20, Heaps::StageInstance);
        if (anim) {
            nw4r::g3d::ResMdl modelCopy((void*)arg0);
            nw4r::g3d::ResFile fileCopy = resFile;
            anim = __ct__16gfModelAnimationFd(anim, &fileCopy, &modelCopy, true, data[4], Heaps::StageInstance);
        }
        anim->_spacer[0] = 0;
        gfModelAnimation::bind(scene, anim);
        self->m_sceneModels[0] = scene;
        self->m_modelAnims[0] = anim;
    }
}
