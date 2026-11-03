#include <gf/gf_archive.h>
#include <st/st_positions.h>
#include <ec/ec_mgr.h>
#include <snd/snd_system.h>
#pragma force_active on
extern "C" const float lbl_71_rodata_0;
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
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
    virtual void fn_71_1D08();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_71_1EC();
    virtual void fn_71_284();
    virtual void createObjPokeTrainer();
    virtual void fn_71_24E4();
    virtual void fn_71_24E0();
    virtual void fn_71_24D4();
    virtual void fn_71_24CC();
    virtual void fn_71_24C4();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_71_27C();
    virtual void process();
    virtual void updateStagePositions();
};
struct Params { char pad[0x30]; float a, b; };
struct MetalGear : Stage {
    char pad40[0x50];
    stPositions* positions;
    char pad94[8];
    Params* params;
    char padA0[0x100];
    gfArchive* archive;
    char pad1A4[0x102];
    unsigned char state;
    unsigned char variant;
    float timer;
    char pad2AC[4];
    unsigned char left, right;
};
extern "C" void fn_71_1670(MetalGear* self, float delta) {
    Params* p = self->params;
    if (p) {
        float t = self->timer - delta;
        self->timer = t;
        if (t < lbl_71_rodata_0)
            self->timer = lbl_71_rodata_0;
        switch (self->state) {
        case 0:
            self->state = 1;
        case 1:
            if (self->right == 0) {
                if (self->left != 0) {
                    self->left = 1;
                    self->right = 1;
                }
                self->timer = p->a - p->b;
                int index;
                switch (self->variant) { case 1: index = 0x6e; break; default: index = 0x6f; break; }
                void* data = self->archive->getData(Data_Type_Model, index, 0xfffe);
                if (data) {
                    nw4r::g3d::ResFile file(data);
                    self->positions->loadPositionData(&file);
                }
                self->updateStagePositions();
                self->state = 2;
            }
            break;
        case 2:
            if (lbl_71_rodata_0 == self->timer) {
                self->left = 2;
                self->right = 2;
                self->timer = p->b;
                self->state = 3;
            }
            break;
        case 3:
            if (lbl_71_rodata_0 == self->timer) {
                self->left = 3;
                self->right = 3;
                g_ecMgr->setEffect((EfID)0x53000b);
                int index;
                switch (self->variant) { case 1: index = 0x64; break; default: index = 0x70; break; }
                void* data = self->archive->getData(Data_Type_Model, index, 0xfffe);
                if (data) {
                    nw4r::g3d::ResFile file(data);
                    self->positions->loadPositionData(&file);
                }
                self->updateStagePositions();
                self->state = 4;
            }
            break;
        case 4:
            if (self->left == 6 && self->right == 6) {
                g_sndSystem->playSE((SndID)0x1d01, 0, 0, 0, -1);
                self->state = 0;
            }
            break;
        }
    }
}