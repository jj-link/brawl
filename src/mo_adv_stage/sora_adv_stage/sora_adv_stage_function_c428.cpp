#pragma force_active on

#include <types.h>
#include <gr/gr_gimmick_motion_path.h>
#include <st/stage.h>
#include <st/st_data_container.h>

struct CallBase {
    char pad[0x3C];
};

class GroundCalls : public CallBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_40_2024();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void fn_40_21B8();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void fn_40_222C();
    virtual void renderPre();
    virtual void fn_40_8A84();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_12F8();
    virtual void fn_40_D24();
    virtual void createObjPokeTrainer();
    virtual void fn_40_5098();
    virtual void fn_40_50A0();
    virtual void fn_40_50BC();
    virtual void fn_40_8B18();
    virtual void fn_40_8B28();
    virtual void fn_40_7D94();
    virtual void fn_40_8154();
    virtual void fn_40_80AC();
    virtual void fn_40_8160();
    virtual void fn_40_8478();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions(gfArchive*, int, int);
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();
    virtual void debugCollision();
    virtual void fn_40_6FF4();
    virtual void fn_40_8B10();
    virtual void getZoneLightSetIndex();
    virtual void fn_40_8AF4();
    virtual void clearCameraParam();
    virtual void fn_40_6C6C();
    virtual void fn_40_464();
    virtual void fn_40_5EC();
    virtual void fn_40_990();
    virtual void fn_40_A7C();
    virtual void fn_40_B98();
    virtual void fn_40_5FD8();
    virtual void fn_40_6050();
    virtual void isReStartSamePoint();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void fn_40_7034();
    virtual void fn_40_70B4();
    virtual void getEnableZ();
    virtual void fn_40_8AEC();
    virtual void fn_40_76F8();
    virtual void fn_40_76E0();
    virtual void fn_40_8AE4();
    virtual void fn_40_8ADC();
    virtual void fn_40_8AC8();
    virtual void fn_40_8AB8();
    virtual void fn_40_774C();
    virtual void fn_40_77DC();
    virtual void fn_40_783C();
    virtual void fn_40_8AB0();
    virtual void fn_40_8AA8(void*);
};

extern char lbl_40_data_274[];
extern char lbl_40_data_2C0[];
extern char lbl_40_data_2180[];
extern void* g_ftManager;

extern "C" grGimmickMotionPath*
create__19grGimmickMotionPathFiPCcPCc(short, const char*, const char*);
extern "C" void fn_27_10A1AC(void*, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct CallbackData {
    u32 next;
    void* table;
    u32 kind;
    Stage* stage;
    grGimmickMotionPath* first;
    grGimmickMotionPath* second;
    void* entry;
    u8 active;
    char pad[7];
};

extern "C" void fn_40_C428(
    Stage* stage,
    u32 kind,
    stDataMultiContainer* multi,
    u32 i,
    u32 idx,
    stDataContainer* c
) {
    idx = 0;
    stTrigger* trg;
    grGimmickMotionPath* g2;
    grGimmickMotionPath* g1;
    char* e;
    CallbackData* cb;

    while ((c = multi->searchContainer(kind, idx++)) != 0) {
        for (i = 0; i < c->m_filedata->m_numFiles; i++) {
            e = (char*)c->getData(i);
            trg = g_stTriggerMng->createTrigger(
                (Gimmick::AreaKind)10, (stTriggerData*)(e + 20));

            g1 = create__19grGimmickMotionPathFiPCcPCc(
                (short)*(unsigned char*)(e + 6), lbl_40_data_274, lbl_40_data_2C0);
            g2 = create__19grGimmickMotionPathFiPCcPCc(
                (short)*(unsigned char*)(e + 14), lbl_40_data_274, lbl_40_data_2C0);

            stage->addGround(g1);
            stage->addGround(g2);
            fn_27_10A1AC(g_ftManager, 0);

            ((GroundCalls*)g1)->fn_40_8AA8(e);
            ((GroundCalls*)g2)->fn_40_8AA8(e + 8);

            ((GroundCalls*)g1)->renderDebugPositions(
                *(gfArchive**)((char*)stage + 0x1A0), 0, 0);
            ((GroundCalls*)g2)->renderDebugPositions(
                *(gfArchive**)((char*)stage + 0x1A0), 0, 0);

            cb = (CallbackData*)__nw__FUlQ25Heaps8HeapType(0x24, 15);
            if (cb) {
                cb->next = 0;
                cb->kind = 21;
                cb->table = lbl_40_data_2180;
                cb->stage = stage;
                cb->first = g1;
                cb->second = g2;
                cb->entry = e;
                cb->active = 0;
            }

            trg->setValidCallback((gfCallBack*)cb);
        }
    }
}
