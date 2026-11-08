#include <st/stage.h>
#pragma force_active on

class FzeroGround : public grYakumono {
public:
    virtual void setStageData(void*);
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115(void*);
    virtual void slot116(void*);
    virtual void slot117(void*);
    virtual void slot118(void*);
    virtual void slot119(void*);
    virtual void slot120(void*);
};

struct FzeroStage : public Stage {
    gfArchive* archive;
    char pad1A4[0x34];
    char value1D8[8];
    char value1E0[4];
    char value1E4[0x3F0];
    char value5D4[0x3B0];
    char value984;
    char value985;
};

extern "C" {
FzeroGround* fn_61_8368(int, const char*, const char*);
extern char lbl_61_data_228[];
extern char lbl_61_data_23C[];
}

extern "C" void fn_61_106C(FzeroStage* self, int kind) {
    FzeroGround* ground;
    switch (kind) {
    case 15:
        ground = fn_61_8368(0x41, lbl_61_data_228, lbl_61_data_23C);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(self->m_stageData);
        ground->slot115(&self->value1E0);
        ground->slot116(&self->value1D8);
        ground->slot117(&self->value984);
        ground->slot118(&self->value5D4);
        ground->slot119(&self->value1E4);
        ground->slot120(&self->value985);
    }
}