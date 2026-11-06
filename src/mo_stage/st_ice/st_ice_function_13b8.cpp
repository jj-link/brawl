#include <st/st_trigger.h>
#include <sr/sr_common.h>

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_62_A44(void*);
};
struct Stage {
    char pad[0x9c];
    void* m_stageData;
    void addGround(Ground*);
};
#include <string.h>
#pragma force_active on

struct IceFields {
    char pad[0x1a0];
    void* file;
    char pad1[0x330];
    stTrigger* trigger;
    grGimmickWaterData* water;
};
extern "C" {
extern char lbl_62_data_190[];
extern char lbl_62_data_1A0[];
extern const float lbl_62_rodata_0[];
Ground* fn_62_2BA4(int, const char*, const char*);
void fn_62_13B8(Stage* stage, int kind) {
    const float* rodata = lbl_62_rodata_0;
    Ground* ground;
    switch (kind) {
    case 13:
        ground = fn_62_2BA4(20, lbl_62_data_190, lbl_62_data_1A0);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        ground->startup(((IceFields*)stage)->file, 0, 0);
        ground->fn_62_A44(stage->m_stageData);
        grGimmickWaterData* water = (grGimmickWaterData*)operator new(sizeof(grGimmickWaterData), Heaps::StageInstance);
        ((IceFields*)stage)->water = water;
        if (water) {
            memset(water, 0, sizeof(grGimmickWaterData));
            water->m_swimHeight = rodata[0];
            water->m_canDrown = true;
            water->m_speed = rodata[2];
            water->m_areaData.m_offsetPos.m_x = rodata[0];
            water->m_areaData.m_offsetPos.m_y = rodata[3];
            water->m_areaData.m_range.m_x = rodata[4];
            water->m_areaData.m_range.m_y = rodata[5];
            ((IceFields*)stage)->trigger = g_stTriggerMng->createTrigger(Gimmick::Area_Water, -1);
            ((IceFields*)stage)->trigger->setWaterTrigger(water);
        }
    }
}
}