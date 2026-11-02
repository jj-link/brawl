#include <types.h>
#pragma force_active on
extern "C" {
void update__9grGimmickFf(void*, float);
void updateCallback__9grGimmickFUl(void*, unsigned long);
void setEnableCollisionStatus__6GroundFb(void*, bool);
void startGimmickSE__9grGimmickFUl(void*, unsigned long);
void stopGimmickSE__9grGimmickFUl(void*, unsigned long);
void startGimmickEffect__9grGimmickFUl(void*, unsigned long);
void stopGimmickEffect__9grGimmickFUl(void*, unsigned long);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
}
struct grYakumono_base {
    char pad[0x3C];
};
struct AnimData {
    char pad0[0x1C];
    u16 frame;
};
class AnimSub {
public:
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1C();
    virtual float getEndFrame();
    char pad4[0x28];
    AnimData* m2c;
};
struct gfModelAnimation {
    char pad0[0xC];
    AnimSub* unkC;
};
struct Holder14C {
    char pad0[0x1E0];
    u32 m1E0;
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
    virtual void fn_40_27054();
    virtual void fn_40_27494();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(u32 flag);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_40_276D0();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void fn_40_270AC();
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
    virtual void fn_40_273F8();
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
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
    virtual void getGimmickData();
    virtual void changeNodeAnim(u32 a, u32 b);

    char pad40[4];
    void** m44;
    gfModelAnimation** m48;
    char pad4C[0x100];
    Holder14C* m14C;
    u8 state;
    char pad151[3];
    float timer;
    u32 target;
};
extern "C" void fn_40_27494(grYakumono* self, float delta) {
    update__9grGimmickFf(self, delta);
    switch (self->state) {
    case 1:
        if (self->timer >= (float)self->target) {
            self->state = 2;
        }
        break;
    case 2:
        self->changeNodeAnim(0, 0);
        for (u32 i = 0; i < 5; i++) {
            stopGimmickSE__9grGimmickFUl(self, i);
        }
        for (s32 j = 0; j < 5; j++) {
            startGimmickSE__9grGimmickFUl(self, j);
        }
        for (u32 k = 0; k < 5; k++) {
            stopGimmickEffect__9grGimmickFUl(self, k);
        }
        for (s32 m = 0; m < 5; m++) {
            startGimmickEffect__9grGimmickFUl(self, m);
        }
        setEnableCollisionStatus__6GroundFb(self, false);
        self->state = 3;
        break;
    case 3: {
        AnimSub* o = (*self->m48)->unkC;
        u32 frame = o->m2c->frame;
        u32 cur = (u32)o->getEndFrame();
        if (cur == frame) {
            self->setVisibility(0);
        }
        Holder14C* h = self->m14C;
        if (h->m1E0 != 0) {
            if (self->timer >= (float)h->m1E0) {
                self->state = 4;
            }
        }
        break;
    }
    case 4:
        self->setVisibility(1);
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*self->m48, *self->m44);
        setEnableCollisionStatus__6GroundFb(self, true);
        self->state = 0;
        break;
    }
    self->timer += delta;
    updateCallback__9grGimmickFUl(self, 0);
}
