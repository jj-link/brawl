#include <gf/gf_archive.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <st/st_melee.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_51_data_0[];

class stJungle : public stMelee {
public:
    virtual void v0(int);
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int);

    char pad1[0x1f0 - sizeof(stMelee)];
    Vec3f pos3;
    char pad2[0xc];
    Vec3f pos0;
    char pad3[0x24];
    Vec3f pos1;
    char pad4[0x24];
    Vec3f pos2;
    char pad5[0x464 - 0x274];
    u8 flag;
};

extern "C" void fn_51_304(stJungle* self) {
    char* names = lbl_51_data_0;
    self->testStageParamInit(self->m_fileData, 10);
    self->testStageDataInit(self->m_fileData, 20, 0x70);
    self->v0(0);
    self->v0(1);
    self->v1(2);
    self->v1(3);
    self->v1(4);
    self->v1(5);
    self->v1(6);
    self->v1(7);
    self->v1(8);
    self->v1(9);
    self->v1(10);
    self->v1(11);
    self->v1(12);
    self->v1(13);
    self->v1(14);
    self->v1(15);
    self->v1(16);
    self->v1(17);
    self->v1(18);
    self->v1(19);
    self->v1(20);
    self->v1(21);
    self->v1(22);
    self->v1(23);
    self->v1(24);
    self->v1(25);
    self->v2(26);
    self->v3(27);
    self->v2(28);
    self->v3(29);
    self->v4(30);
    self->v5(31);
    self->v6(32);
    self->v6(33);
    self->v7();
    self->v9();
    self->v10(39);
    self->initCameraParam();
    void* data = self->m_fileData->getData(Data_Type_Model, 100, 0xfffe);
    if (data) {
        nw4r::g3d::ResFile posData(data);
        self->createStagePositions(&posData);
    } else {
        self->createStagePositions();
    }
    self->createWind2ndOnly();
    self->initPosPokeTrainer(4, 0);
    self->createObjPokeTrainer(self->m_fileData, 101, names + 12, self->m_pokeTrainerPos, &self->pos0);
    self->createObjPokeTrainer(self->m_fileData, 102, names + 28, self->m_pokeTrainerPos + 2, &self->pos1);
    self->createObjPokeTrainer(self->m_fileData, 103, names + 44, self->m_pokeTrainerPos + 4, &self->pos2);
    self->createObjPokeTrainer(self->m_fileData, 104, names + 60, self->m_pokeTrainerPos + 6, &self->pos3);
    self->loadStageAttrParam(self->m_fileData, 100);
    self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_fileData->getData(Data_Type_Scene, 0, 0xfffe)), 0);
    u8* mode = (u8*)g_GameGlobal->m_modeMelee;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
            if ((u32)mode[0x10] == 0x15) {
                self->flag = 1;
            }
        }
    }
}
