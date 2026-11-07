#include <st/st_melee.h>
#include <gr/gr_madein.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_43_data_0[];
Ground* fn_43_B5C(int, const char*, const char*);
}

class BattleGround : public Ground { public: virtual void setStageData(void*); };

class BattleStage : public stMelee {
public:
    Vec3f a[5];
    Vec3f b[4];
    Vec3f c[2];
};

extern "C" void fn_43_1EC(BattleStage* self) {
    const char* data = lbl_43_data_0;
    self->testStageParamInit(self->m_fileData, 10);
    self->testStageDataInit(self->m_fileData, 20, 1);
    self->initCameraParam();
    self->addGround(fn_43_B5C(2, data+0x10, data+0x14));
    self->addGround(fn_43_B5C(3, data+0x10, data+0x28));
    self->addGround(fn_43_B5C(4, data+0x10, data+0x3c));
    self->addGround(fn_43_B5C(5, data+0x10, data+0x50));
    self->addGround(fn_43_B5C(6, data+0x10, data+0x64));
    self->addGround(fn_43_B5C(1, data+0x10, data+0x78));
    self->addGround(fn_43_B5C(7, data+0x10, data+0x8c));
    self->addGround(fn_43_B5C(9, data+0x10, data+0xa4));
    self->addGround(fn_43_B5C(10, data+0xb8, data+0xd0));
    self->addGround(fn_43_B5C(11, data+0xe8, data+0x100));
    self->addGround(fn_43_B5C(12, data+0x118, data+0x130));
    self->addGround(fn_43_B5C(13, data+0x148, data+0x160));
    self->addGround(fn_43_B5C(8, data+0x10, data+0x178));
    Ground* current;
    unsigned int i = 0;
    unsigned int n = self->getGroundNum();
    while (i != n) {
        current = self->getGround(i);
        if (current) {
            current->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
            ((BattleGround*)current)->setStageData(self->m_stageData);
            current->setDontMoveGround();
        }
        ++i;
    }
    self->createCollision(self->m_fileData, 2, 0);
    grMadein* ground = grMadein::create(200, data+0x10, data+0x18c, Heaps::StageInstance);
    if (ground) {
        ground->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
        ground->initializeEntity();
        ground->startEntity();
        ground->updateG3dProcCalcWorld();
        int j;
        Vec3f* p = self->a;
        for (j = 0; j < 5; ++j, ++p) {
            char name[64];
            sprintf(name, data+0x198, j);
            ground->getNodePosition(p, 0, name);
        }
        p = self->b;
        for (int j = 0; j < 4; ++j, ++p) {
            char name[64];
            sprintf(name, data+0x1b0, j);
            ground->getNodePosition(p, 0, name);
        }
        p = self->c;
        for (int j = 0; j < 2; ++j, ++p) {
            char name[64];
            sprintf(name, data+0x1c8, j);
            ground->getNodePosition(p, 0, name);
        }
        ground->endEntity();
        delete ground;
    }
    void* ptr = self->m_fileData->getData(Data_Type_Model, 100, 0xfffe);
    if (ptr) {
        nw4r::g3d::ResFile res(ptr);
        self->createStagePositions(&res);
    } else {
        self->createStagePositions();
    }
    self->createWind2ndOnly();
    self->registScnAnim((nw4r::g3d::ResFileData*)self->m_fileData->getData(Data_Type_Scene, 0, 0xfffe), 0);
    self->loadStageAttrParam(self->m_fileData, 30);
    self->initPosPokeTrainer(1, 0);
    self->createObjPokeTrainer(self->m_fileData, 101, data+0x1e4, self->m_pokeTrainerPos, 0);
}