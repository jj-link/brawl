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
};

struct FzeroStage : public Stage {
    gfArchive* archive;
    char pad1A4[0x34];
    char value1D8[8];
    char value1E0[2];
    char value1E2[2];
    char value1E4;
};

extern "C" {
FzeroGround* fn_61_2E50(int, const char*, const char*);
extern char lbl_61_data_208[];
extern char lbl_61_data_218[];
}

extern "C" void fn_61_F40(FzeroStage* self, int kind) {
    FzeroGround* ground;
    switch (kind) {
    case 14:
        ground = fn_61_2E50(0x5F, lbl_61_data_208, lbl_61_data_218);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(self->archive, 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(self->m_stageData);
        ground->slot116(&self->value1E0);
        ground->slot117(&self->value1D8);
        ground->slot115(&self->value1E2);
        ground->slot118(&self->value1E4);
    }
}
