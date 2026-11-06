#pragma force_active on
#include <st/stage.h>
#include <string.h>

namespace Matching {
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
    virtual void slot14();
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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_73_33D0();
    virtual void slot37(gfArchive*, u32, u32);
    virtual void slot38();
    virtual void fn_73_8DC(void*);
    virtual void fn_73_33C8();
    virtual void fn_73_33C4();
    virtual void fn_73_2C5C();
    virtual void fn_73_33BC();
    virtual void fn_73_33B0();
    virtual void fn_73_33A0();
    virtual void fn_73_3390();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void slot62();
    virtual void fn_73_3388();
    virtual void fn_73_3380();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_73_3378();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_73_1848();
    virtual void fn_73_33F4();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_73_33EC();
    virtual void onDamage();
    virtual void slot91();
    virtual void onInflictEach();
    virtual void slot93();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void slot100();
    virtual void slot101();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void fn_73_3F0C();
    virtual void slot123();
    virtual void slot124();
    virtual void fn_73_3FF8();
    virtual void slot126();
    virtual void fn_73_4FFC();
    virtual void fn_73_12B0(void*);
    virtual void fn_73_12B8(void*);
    virtual void fn_73_12C0(int);
    virtual void fn_73_12C8(void*);
    virtual void fn_73_12D0(int);
    virtual void fn_73_12D8(int);
    virtual void fn_73_12E0(void*);
    virtual void fn_73_12F8(void*);
    virtual void fn_73_12E8(const char*);
    virtual void fn_73_12F0(void*);
    virtual void slot138(void*);
    virtual void slot139(void*);
    virtual void fn_73_1310(void*);
};
}

extern "C" {
extern char lbl_73_data_0[];
Matching::Ground* fn_73_33FC(int, const char*, const char*);
Matching::Ground* fn_73_5444(int, const char*, const char*);
Matching::Ground* fn_73_5CD8(int, const char*, const char*);
Matching::Ground* fn_73_615C(int, const char*, const char*);
Matching::Ground* fn_73_6530(int, const char*, const char*);
Matching::Ground* fn_73_675C(int, const char*, const char*);
Matching::Ground* fn_73_6D48(int, const char*, const char*);
Matching::Ground* fn_73_776C(int, const char*, const char*);
Matching::Ground* fn_73_79CC(int, const char*, const char*);
Matching::Ground* fn_73_7F74(int, const char*, const char*);
Matching::Ground* fn_73_8200(int, const char*, const char*);
Matching::Ground* fn_73_8840(int, const char*, const char*);

void fn_73_B48(Stage* stage, u32 kind) {
    char name[128];
    int id;
    Matching::Ground* ground;
    char* data = lbl_73_data_0;
    void* p27 = 0;
    void* p26 = 0;
    void* p25 = 0;
    int v24 = 8;
    int v23 = 1;
    void* p22 = 0;
    void* p31 = 0;
    switch (kind) {
    case 1:
        ground = fn_73_33FC(10, data + 0xdc, data + 0xf8);
        id = 1;
        strcpy(name, data + 0x108);
        break;
    case 2:
        ground = fn_73_33FC(20, data + 0x110, data + 0x128);
        id = 2;
        strcpy(name, data + 0x138);
        break;
    case 3:
        ground = fn_73_33FC(30, data + 0x140, data + 0x158);
        id = 3;
        strcpy(name, data + 0x168);
        break;
    case 4:
        ground = fn_73_33FC(40, data + 0x170, data + 0x188);
        id = 4;
        strcpy(name, data + 0x198);
        break;
    case 5:
        ground = fn_73_33FC(50, data + 0x1a0, data + 0x1b8);
        id = 5;
        strcpy(name, data + 0x1c8);
        break;
    case 6:
        ground = fn_73_33FC(60, data + 0x1d0, data + 0x1e8);
        id = 6;
        strcpy(name, data + 0x1f8);
        break;
    case 7:
        ground = fn_73_5444(70, data + 0x200, data + 0x218);
        id = 7;
        strcpy(name, data + 0x228);
        break;
    case 8:
        ground = fn_73_5CD8(80, data + 0x230, data + 0x244);
        p22 = (char*)stage + 0x40c;
        id = 8;
        v24 = 0;
        strcpy(name, data + 0x254);
        p26 = (char*)stage + 0x3f4;
        v23 = 2;
        break;
    case 9:
        ground = fn_73_5CD8(81, data + 0x25c, data + 0x244);
        p22 = (char*)stage + 0x40d;
        id = 8;
        v24 = 1;
        strcpy(name, data + 0x254);
        p26 = (char*)stage + 0x400;
        v23 = 2;
        break;
    case 10:
        ground = fn_73_615C(90, data + 0x270, data + 0x288);
        id = 9;
        strcpy(name, data + 0x298);
        break;
    case 11:
        ground = fn_73_33FC(100, data + 0x2a0, data + 0x2b8);
        id = 10;
        strcpy(name, data + 0x2c8);
        break;
    case 12:
        ground = fn_73_6530(110, data + 0x2d0, data + 0x2e8);
        id = 11;
        strcpy(name, data + 0x2f8);
        break;
    case 13:
        ground = fn_73_675C(120, data + 0x300, data + 0x31c);
        id = 12;
        strcpy(name, data + 0x32c);
        break;
    case 14:
        ground = fn_73_6D48(130, data + 0x334, data + 0x350);
        id = 13;
        v24 = 2;
        strcpy(name, data + 0x360);
        p25 = (char*)stage + 0x410;
        v23 = 2;
        break;
    case 15:
        ground = fn_73_6D48(130, data + 0x334, data + 0x368);
        id = 13;
        v24 = 3;
        strcpy(name, data + 0x360);
        p25 = (char*)stage + 0x41c;
        v23 = 2;
        break;
    case 16:
        ground = fn_73_776C(140, data + 0x378, data + 0x390);
        id = 14;
        strcpy(name, data + 0x3a0);
        p31 = *(void**)((char*)stage + 0x428);
        break;
    case 17:
        ground = fn_73_79CC(150, data + 0x3a8, data + 0x3c0);
        id = 15;
        strcpy(name, data + 0x3d0);
        break;
    case 18:
        ground = fn_73_33FC(160, data + 0x3d8, data + 0x3f4);
        id = 16;
        strcpy(name, data + 0x404);
        break;
    case 19:
        ground = fn_73_33FC(170, data + 0x40c, data + 0x424);
        id = 17;
        strcpy(name, data + 0x434);
        break;
    case 20:
        ground = fn_73_33FC(180, data + 0x43c, data + 0x454);
        id = 18;
        strcpy(name, data + 0x464);
        break;
    case 21:
        ground = fn_73_33FC(190, data + 0x46c, data + 0x484);
        id = 19;
        strcpy(name, data + 0x494);
        break;
    case 22:
        ground = fn_73_33FC(200, data + 0x49c, data + 0x4b4);
        id = 20;
        strcpy(name, data + 0x4c4);
        break;
    case 23:
        ground = fn_73_33FC(210, data + 0x4cc, data + 0x4e4);
        id = 21;
        strcpy(name, data + 0x4f4);
        break;
    case 24:
        ground = fn_73_7F74(220, data + 0x500, data + 0x518);
        id = 22;
        strcpy(name, data + 0x528);
        p27 = (char*)stage + 0x3d4;
        break;
    case 25:
        ground = fn_73_33FC(230, data + 0x530, data + 0x54c);
        id = 23;
        strcpy(name, data + 0x55c);
        break;
    case 26:
        ground = fn_73_33FC(240, data + 0x564, data + 0x57c);
        id = 24;
        strcpy(name, data + 0x58c);
        break;
    case 27:
        ground = fn_73_8200(250, data + 0x594, data + 0x5ac);
        id = 25;
        strcpy(name, data + 0x5bc);
        break;
    case 28:
        ground = fn_73_33FC(260, data + 0x5c4, data + 0x5dc);
        id = 26;
        strcpy(name, data + 0x5ec);
        break;
    case 29:
        ground = fn_73_8840(270, data + 0x5f4, data + 0x60c);
        id = 27;
        strcpy(name, data + 0x61c);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround((::Ground*)ground);
        ground->slot37(*(gfArchive**)((char*)stage + 0x1a0), 0, 0);
        ground->fn_73_8DC(stage->m_stageData);
        ground->fn_73_12B0((char*)stage + 0x274);
        ground->fn_73_12B8((char*)stage + 0x1e1);
        ground->fn_73_12C0(id);
        ground->fn_73_12C8((char*)stage + 0x1e3);
        ground->fn_73_12D0(v23);
        ground->fn_73_12D8(v24);
        ground->fn_73_12E0(p22);
        ground->fn_73_12E8(name);
        ground->fn_73_12F0(((void**)((char*)stage + 0x208))[id - 1]);
        switch (kind) {
        case 7:
            ground->fn_73_12F0(0);
            ground->fn_73_12F8((char*)stage + 0x201);
            break;
        case 8:
        case 9:
            ground->slot138(p26);
            ground->slot139((char*)stage + 0x40e);
            break;
        case 14:
        case 15:
            ground->fn_73_1310(p25);
            break;
        case 16:
            ground->slot138(p31);
            break;
        case 24:
            ground->slot138(p27);
            ground->slot139((char*)stage + 0x3ec);
            break;
        }
    }
}
}
