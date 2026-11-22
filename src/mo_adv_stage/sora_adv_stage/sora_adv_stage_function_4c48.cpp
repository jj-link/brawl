#include <types.h>
#pragma force_active on

extern "C" u32 getGroundNum__5StageFv(void* self);
extern "C" void* getGround__5StageFi(void* self, int index);

struct GroundBase {
    char pad[0x3c];
};

class GroundV : public GroundBase {
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
    virtual u32 closeStage();
    virtual void renderDebugPositions();
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();
    virtual void debugCollision();
    virtual void fn_40_6FF4();
    virtual s16 fn_40_8B10();
    virtual void getZoneLightSetIndex();
    virtual void fn_40_8AF4();
    virtual void clearCameraParam();
    virtual void fn_40_6C6C();
    virtual void fn_40_464();
    virtual s32 fn_40_5EC(int, int, void*);
    virtual void fn_40_990();
    virtual void fn_40_A7C();
    virtual void fn_40_B98();
    virtual void fn_40_5FD8(int, int, void*, int, int);
    virtual void fn_40_6050();
    virtual void isReStartSamePoint();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount(int, int, void*, int);
};

extern "C" s32 fn_40_4C48(void* stage, u8* data, int flag) {
    u32 i;
    u32 j;
    u32 groundCount = getGroundNum__5StageFv(stage);
    for (i = 0; i < groundCount; i++) {
        GroundV* g = (GroundV*)getGround__5StageFi(stage, i);
        if ((s32)data[0] == g->fn_40_8B10()) {
            for (j = 0; j < g->closeStage();) {
                g->fn_40_5FD8(data[1] != 0, (u16)j, data + 4, 1, 0);
                g->getItemPosCount(data[1] != 0, (u16)j, data + 4, 1);
                g->fn_40_5EC(flag, j, data + 4) ? j++ : ++j;
            }
        }
    }
    return 1;
}
