#include <st/st_melee.h>
#include <gr/gr_madein.h>
#include <gm/gm_global.h>
#include <cm/cm_controller_ai.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_87_data_0[];
Ground* fn_27_27BDB8(int, const char*);
void fn_27_27BF44(Ground*, int, int, int, int);
}

class HealMadein : public grMadein {
public:
    virtual void setStageData(void*);
};
class HealGimmick : public grGimmick {
public:
    virtual void setStageData(void*);
    virtual void setGimmickData(void*);
};

class HealStage : public stMelee {
public:
    HealMadein* mainGround;
    HealMadein* ground2;
    HealMadein* ground3;
    HealGimmick* warpGround;
    u32 heart[6];
    char pad200[0x14];
    u32 itemFigure;
    u32 figures[36];
    char pad2a8[4];
    u32 state;
    u32 state2;
};

extern "C" void fn_87_158(HealStage* self) {
    const char* data = lbl_87_data_0;
    HealStage* figure;
    gmGlobalCorps* corps = g_GameGlobal->m_corps;
    self->testStageParamInit(self->m_fileData, 10);
    self->mainGround = (HealMadein*)grMadein::create(1, data + 12, data + 12, Heaps::StageInstance);
    self->addGround(self->mainGround);
    self->mainGround->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
    self->mainGround->setStageData(self->m_stageData);
    self->mainGround->initializeEntity();
    self->mainGround->startEntityAutoLoop();
    self->heart[0] = self->mainGround->getNodeIndex(0, data + 0x10);
    self->heart[1] = self->mainGround->getNodeIndex(0, data + 0x20);
    self->heart[2] = self->mainGround->getNodeIndex(0, data + 0x30);
    self->heart[3] = self->mainGround->getNodeIndex(0, data + 0x40);
    self->heart[4] = self->mainGround->getNodeIndex(0, data + 0x50);
    self->heart[5] = self->mainGround->getNodeIndex(0, data + 0x60);
    self->itemFigure = self->mainGround->getNodeIndex(0, data + 0x70);
    figure = self;
    for (int i = 0; i < 36; i++, figure = (HealStage*)((char*)figure + 4)) {
        char name[64];
        sprintf(name, data + 0x84, i + 1);
        figure->figures[0] = self->mainGround->getNodeIndex(0, name);
    }
    for (int i = 0; i < 19; i++) {
        char name[64];
        sprintf(name, data + 0x98, i + 1);
        self->mainGround->setNodeVisibility(i == ((u8*)corps)[0x1f], 0, name, false, false);
    }
    self->ground2 = (HealMadein*)grMadein::create(3, data + 12, data + 12, Heaps::StageInstance);
    self->addGround(self->ground2);
    self->ground2->startup(self->m_fileData, 0, (gfSceneRoot::LayerType)4);
    self->ground2->setStageData(self->m_stageData);
    self->ground2->initializeEntity();
    self->ground2->startEntityAutoLoop();
    self->ground3 = (HealMadein*)grMadein::create(4, data + 12, data + 12, Heaps::StageInstance);
    self->addGround(self->ground3);
    self->ground3->startup(self->m_fileData, 0, (gfSceneRoot::LayerType)4);
    self->ground3->setStageData(self->m_stageData);
    self->ground3->initializeEntity();
    self->ground3->startEntityAutoLoop();
    self->warpGround = (HealGimmick*)fn_27_27BDB8(2, data + 0xa8);
    if (self->warpGround) {
        self->addGround(self->warpGround);
        fn_27_27BF44(self->warpGround, 0, 0, 8, 3);
        self->warpGround->setGimmickData((char*)self->warpGround + 0x188);
        self->warpGround->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
        self->warpGround->setStageData(self->m_stageData);
    }
    self->createCollision(self->m_fileData, 2, 0);
    self->initCameraParam();
    void* ptr = self->m_fileData->getData(Data_Type_Model, 100, 0xfffe);
    if (ptr) {
        nw4r::g3d::ResFile res(ptr);
        self->createStagePositions(&res);
    } else {
        self->createStagePositions();
    }
    self->createWind2ndOnly();
    self->registScnAnim((nw4r::g3d::ResFileData*)self->m_fileData->getData(Data_Type_Scene, 0, 0xfffe), 0);
    ((grMadein*)self->getGround(0))->initializeEntity();
    ((grMadein*)self->getGround(0))->startEntityAutoLoop();
    self->loadStageAttrParam(self->m_fileData, 30);
    self->initPosPokeTrainer(1, 0);
    self->createObjPokeTrainer(self->m_fileData, 101, data + 0xb8, self->m_pokeTrainerPos, 0);
    self->state = *(u32*)data;
    self->state2 = 0;
    ((u8*)g_cmAIController)[0x94] &= ~8;
}
