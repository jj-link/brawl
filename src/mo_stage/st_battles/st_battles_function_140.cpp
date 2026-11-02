#include <gf/gf_archive.h>
#include <gr/ground.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <st/st_common_gimmick.h>
#include <st/stage.h>
#include <types.h>
#pragma force_active on

extern "C" const char lbl_42_data_0[];
extern "C" Ground* fn_42_618(int mdlIndex, const char* tgtNodeName, const char* taskName);

extern "C" void fn_42_140(stCommonGimmick* self) {
    const char* data = lbl_42_data_0;
    self->testStageParamInit(self->m_fileData, 0xA);
    self->testStageDataInit(self->m_fileData, 0x14, 1);
    Ground* ground = fn_42_618(1, data + 0x10, data + 0x14);
    if (ground != NULL) {
        self->addGround(ground);
        ground->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
        self->createCollision(self->m_fileData, 2, NULL);
        self->initCameraParam();
        void* posRes = self->m_fileData->getData(Data_Type_Model, 0x64, 0xFFFE);
        if (posRes != NULL) {
            nw4r::g3d::ResFile posData(posRes);
            self->createStagePositions(&posData);
        } else {
            self->createStagePositions();
        }
        self->createWind2ndOnly();
        self->loadStageAttrParam(self->m_fileData, 0x1E);
        self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_fileData->getData(Data_Type_Scene, 0, 0xFFFE)), 0);
        self->initPosPokeTrainer(1, 0);
        self->createObjPokeTrainer(self->m_fileData, 0x65, data + 0x28, self->m_pokeTrainerPos, NULL);
    }
}
