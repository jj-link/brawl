#include <gf/gf_archive.h>
#include <gf/gf_3d_scene.h>
#include <gm/gm_global.h>
#include <gm/gm_result_info.h>
#include <gr/gr_madein.h>
#include <gr/ground.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <st/st_melee.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_4A8B0[];

class SoraMeleeStage : public stMelee {
public:
    Vec3f m_pos[12];

    SoraMeleeStage(const char* name, srStageKind kind) : stMelee(name, kind) {}
};

extern "C" void fn_27_22B680(SoraMeleeStage* self) {
    const char* data = lbl_27_data_4A8B0;

    self->testStageParamInit(self->m_fileData, 0xA);
    self->addGround(grMadein::create(0, data + 0x408, data + 0x40c, Heaps::StageInstance));

    int i = 0;
    u32 n = self->getGroundNum();
    while (i != n) {
        Ground* gr = self->getGround(i);
        if (gr) {
            gr->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
        }
        i++;
    }

    self->createCollision(self->m_fileData, 2, 0);
    static_cast<grMadein*>(self->getGround(0))->initializeEntity();
    self->initCameraParam();

    void* ptr = self->m_fileData->getData(Data_Type_Model, 0x64, 0xFFFE);
    if (ptr) {
        nw4r::g3d::ResFile posData(ptr);
        self->createStagePositions(&posData);
    } else {
        self->createStagePositions();
    }

    self->createWind2ndOnly();
    self->loadStageAttrParam(self->m_fileData, 0x1E);
    self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_fileData->getData(Data_Type_Scene, 1, 0xFFFE)), 0);

    Vec3f pos[12];
    gmResultInfo* resultInfo = g_GameGlobal->m_resultInfo;

    if (*(u8*)((char*)resultInfo + 0x1378) == gmResultInfo::Decision_NoContest) {
        self->getGround(0)->getNodePosition(&pos[0], 0, data + 0x41c);
        self->getGround(0)->getNodePosition(&pos[1], 0, data + 0x42c);
        self->getGround(0)->getNodePosition(&pos[2], 0, data + 0x43c);
        self->getGround(0)->getNodePosition(&pos[3], 0, data + 0x42c);
        self->getGround(0)->getNodePosition(&pos[4], 0, data + 0x41c);
        self->getGround(0)->getNodePosition(&pos[5], 0, data + 0x43c);
        self->getGround(0)->getNodePosition(&pos[6], 0, data + 0x44c);
        self->getGround(0)->getNodePosition(&pos[7], 0, data + 0x45c);
        self->getGround(0)->getNodePosition(&pos[8], 0, data + 0x46c);
        self->getGround(0)->getNodePosition(&pos[9], 0, data + 0x47c);
    } else if (!resultInfo->m_isTeams) {
        self->getGround(0)->getNodePosition(&pos[0], 0, data + 0x48c);
        self->getGround(0)->getNodePosition(&pos[1], 0, data + 0x498);
        self->getGround(0)->getNodePosition(&pos[2], 0, data + 0x4a4);
        self->getGround(0)->getNodePosition(&pos[3], 0, data + 0x4b0);
        self->getGround(0)->getNodePosition(&pos[4], 0, data + 0x4bc);
        self->getGround(0)->getNodePosition(&pos[5], 0, data + 0x4c8);
        self->getGround(0)->getNodePosition(&pos[6], 0, data + 0x4d4);
    } else {
        self->getGround(0)->getNodePosition(&pos[0], 0, data + 0x4e0);
        self->getGround(0)->getNodePosition(&pos[1], 0, data + 0x4ec);
        self->getGround(0)->getNodePosition(&pos[2], 0, data + 0x4f8);
        self->getGround(0)->getNodePosition(&pos[3], 0, data + 0x504);
        self->getGround(0)->getNodePosition(&pos[4], 0, data + 0x510);
        self->getGround(0)->getNodePosition(&pos[5], 0, data + 0x51c);
        self->getGround(0)->getNodePosition(&pos[6], 0, data + 0x528);
        self->getGround(0)->getNodePosition(&pos[7], 0, data + 0x534);
        self->getGround(0)->getNodePosition(&pos[8], 0, data + 0x540);
        self->getGround(0)->getNodePosition(&pos[9], 0, data + 0x54c);
        self->getGround(0)->getNodePosition(&pos[10], 0, data + 0x558);
        self->getGround(0)->getNodePosition(&pos[11], 0, data + 0x564);
    }

    for (int j = 0; j < 12; j++) {
        self->m_pos[j] = pos[j];
    }
}