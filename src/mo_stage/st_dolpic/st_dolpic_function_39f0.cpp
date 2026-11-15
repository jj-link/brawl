#include <types.h>
#include <gf/gf_archive.h>
#include <st/st_positions.h>
#pragma force_active on

extern "C" const float lbl_46_rodata_4;
extern "C" const float lbl_46_rodata_14;

struct StageBase { char pad_00[0x3C]; };
struct Bounds { float minX, minY, minZ; float maxX, maxY, maxZ; };
class Stage : public StageBase {
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
    virtual void fn_46_3FEC();
    virtual void init();
    virtual void fn_46_280();
    virtual void fn_46_354();
    virtual void createObjPokeTrainer();
    virtual void fn_46_4384();
    virtual void fn_46_4380();
    virtual void fn_46_4374();
    virtual void fn_46_436C();
    virtual void fn_46_4364();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_46_34C();
    virtual void process();
    virtual void updateStagePositions();
    char pad_40[0x90 - 0x40];
    stPositions* m_90;
    char pad_94[0x9C - 0x94];
    Bounds* m_9C;
    char pad_A0[0x1A0 - 0xA0];
    gfArchive* m_1A0;
    char pad_1A4[0x1D8 - 0x1A4];
    u8 m_1D8;
    char pad_1D9[0x1DC - 0x1D9];
    float m_1DC;
    char pad_1E0[0x1E4 - 0x1E0];
    float m_1E4;
    float m_1E8;
    u32 m_1EC;
    char pad_1F0[0x1F4 - 0x1F0];
    u8 m_1F4;
};

extern "C" void fn_46_39F0(Stage* self) {
    u32 var;
    void* spC;
    void* sp8;
    float cur;
    Bounds* b;
    u32 st;

    if (self->m_90 == 0) goto end;
    if (self->m_9C == 0) goto end;
    if (lbl_46_rodata_4 == self->m_1E4) {
        cur = self->m_1E4;
        if (lbl_46_rodata_4 != self->m_1E8) {
            self->m_1E8 = cur;
            st = self->m_1D8;
            switch (st) {
            case 14: case 22: case 24: case 26: case 28: case 32:
                switch (self->m_1F4) {
                case 1: var = 0x64; break;
                case 2: var = 0x79; break;
                case 3: var = 0x7A; break;
                case 4: var = 0x7B; break;
                default: return;
                }
                if (self->m_1EC != var) {
                    void* data = self->m_1A0->getData(Data_Type_Model, var, 0xFFFE);
                    if (data != 0) {
                        spC = data;
                        self->m_90->loadPositionData((nw4r::g3d::ResFile*)&spC);
                    }
                    self->updateStagePositions();
                    self->m_1EC = var;
                }
                break;
            case 15: case 16: case 17: case 18: case 19: case 20: case 21:
            case 23: case 25: case 27: case 29: case 30: case 31:
            default:
                break;
            }
        } else {
            self->m_1E8 = cur;
        }
        return;
    }
    cur = self->m_1E4;
    self->m_1E8 = cur;
    b = self->m_9C;
    if ((self->m_1DC - b->minX) > lbl_46_rodata_14 * b->maxX) {
        st = self->m_1D8;
        switch (st) {
        case 14: case 22: case 24: case 26: case 28: case 32:
            return;
        case 15: case 16: case 17: case 18: case 19: case 20: case 21:
        case 23: case 25: case 27: case 29: case 30: case 31:
        default:
            break;
        }
        switch (self->m_1F4) {
        case 1: var = 0x64; break;
        case 2: var = 0x79; break;
        case 3: var = 0x7A; break;
        case 4: var = 0x7B; break;
        default: return;
        }
    } else {
        st = self->m_1D8;
        switch (st) {
        case 2: var = 0x70; break;
        case 4: var = 0x71; break;
        case 6: var = 0x72; break;
        case 8: var = 0x73; break;
        case 10: var = 0x73; break;
        case 12: var = 0x74; break;
        case 14: var = 0x75; break;
        case 16: var = 0x75; break;
        case 18: var = 0x76; break;
        case 20: var = 0x76; break;
        case 22: var = 0x77; break;
        case 24: var = 0x78; break;
        case 26: var = 0x77; break;
        case 28: var = 0x78; break;
        case 30: return;
        case 32: return;
        case 0: case 1: case 3: case 5: case 7: case 9:
        case 11: case 13: case 15: case 17: case 19: case 21:
        case 23: case 25: case 27: case 29: case 31: return;
        default: goto end;
        }
    }
    if (self->m_1EC != var) {
        void* data = self->m_1A0->getData(Data_Type_Model, var, 0xFFFE);
        if (data != 0) {
            sp8 = data;
            self->m_90->loadPositionData((nw4r::g3d::ResFile*)&sp8);
        }
        self->updateStagePositions();
        self->m_1EC = var;
    }
end:
    ;
}