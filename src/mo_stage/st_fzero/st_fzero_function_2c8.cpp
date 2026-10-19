#include <gf/gf_archive.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <st/st_melee.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_61_data_8[];
}

class stFZero : public stMelee {
public:
    virtual void vfunc120(int);
    virtual void vfunc121(int);
    virtual void vfunc122(int);
    virtual void vfunc123(int);
    virtual void vfunc124(int);
    virtual void vfunc125(int);
    virtual void vfunc126(int);
    virtual void vfunc127(int);
    virtual void vfunc128(int);
    virtual void vfunc129();

    char _pad0[0xbe1 - sizeof(stMelee)];
    bool m_flag;     // 0xbe1
    char _pad1[2];
    stCollisionWork m_collisionWork; // 0xbe4
    grCollision* m_collision;        // 0xbf4
};

extern "C" void fn_61_2C8(stFZero* self) {
    self->testStageParamInit(self->m_fileData, 10);
    self->testStageDataInit(self->m_fileData, 20, 0x5c);
    self->initPosPokeTrainer(4, 1);
    self->vfunc120(0);
    self->createCollision(self->m_fileData, 2, 0);
    self->vfunc121(1);
    self->vfunc122(3);
    self->vfunc123(2);
    self->vfunc123(4);
    self->vfunc123(5);
    self->vfunc123(6);
    self->vfunc123(7);
    self->vfunc123(8);
    self->vfunc124(9);
    self->vfunc125(10);
    self->vfunc126(11);
    self->vfunc126(12);
    self->vfunc126(13);
    self->vfunc127(14);
    self->vfunc128(15);
    self->vfunc129();
    self->m_collision = self->createCollisionSelf(&self->m_collisionWork, 0, lbl_61_data_8, lbl_61_data_8, 0x400);
    self->initCameraParam();
    self->loadStageAttrParam(self->m_fileData, 0x1E);
    void* posRes = self->m_fileData->getData(Data_Type_Model, 0x64, 0xFFFE);
    if (posRes != 0) {
        nw4r::g3d::ResFile posData(posRes);
        self->createStagePositions(&posData);
    } else {
        self->createStagePositions();
    }
    self->createWind2ndOnly();
    self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_fileData->getData(Data_Type_Scene, 0, 0xFFFE)), 0);
    u8* mode = (u8*)g_GameGlobal->m_modeMelee;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
            if ((u32)mode[0x10] == 0x1f) {
                self->m_flag = 1;
            }
        }
    }
}
