#pragma force_active on
#include <types.h>

struct Vec3f { f32 x, y, z; };
struct ContainerData { void* field0; u32 count; };
struct Class_3790 {
    virtual void fn_70_B644();
    virtual void fn_70_AB0C();
    virtual void fn_70_AB1C();
    virtual void* fn_70_9164(int);
    void* field4;
    ContainerData* data;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void slot6();
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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void slot35();
    virtual void fn_70_22A8();
    virtual void startup(void*, u32, u32);
    virtual void slot38();
    virtual void fn_70_78C(void*);
    virtual void fn_70_22A0();
    virtual void fn_70_229C();
    virtual void fn_70_2080();
    virtual void fn_70_2294();
    virtual void fn_70_2288();
    virtual void fn_70_2278();
    virtual void fn_70_2268();
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
    virtual void fn_70_2264();
    virtual void fn_70_2260();
    virtual void fn_70_2258();
    virtual void slot65(f32);
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_70_2250();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_70_22D4();
    virtual void fn_70_22CC();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_70_22C4();
    virtual void slot90();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_70_21B0();
    virtual void fn_70_794(char*);
    virtual void fn_70_79C();
    virtual void fn_70_7A4(char*);
    virtual void fn_70_7AC();
    virtual void fn_70_2208();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void fn_70_3B98();
    virtual void fn_70_3F00();
    virtual void fn_70_4350();
    virtual void fn_70_4818();
    virtual void fn_70_484C();
    virtual void fn_70_4898();
    virtual void fn_70_4A28();
    virtual void fn_70_13B4(void*);
    virtual void fn_70_13BC(void*);
    virtual void fn_70_13AC(char*);
    virtual void fn_70_13D4(f32);
    virtual void fn_70_13C4(int);
    virtual void fn_70_4BA4(int&);
    virtual void fn_70_13CC(void*);
};
struct Stage {
    char p0[0x9c]; void* field_9c;
    char p1[0x100]; void* field_1a0;
    char p2[0x34]; char field_1d8; char field_1d9;
    char p3[6]; Vec3f field_1e0[8]; char p4[0xc];
    char field_24c[0xc]; char field_258[0xc];
    char p6[0x19]; char field_27d[4]; char field_281; char field_282; char p7[5];
    int field_288; Class_3790* field_28c; Class_3790* field_290;
};
extern "C" {
extern char lbl_70_data_0[];
extern const f32 lbl_70_rodata_0[];
Ground* fn_70_2B80(int, char*, char*);
Ground* fn_70_5960(int, char*, char*);
Ground* fn_70_5524(int, char*, char*);
Ground* fn_70_4D50(int, char*, char*);
Ground* fn_70_4FE0(int, char*, char*);
Ground* fn_70_5298(int, char*, char*);
Ground* fn_70_5D24(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void fn_70_BE8(Stage* self, s32 arg1, s32 arg2) {
    Stage* stage = self;
    const f32* rodata = lbl_70_rodata_0;
    char* data = lbl_70_data_0;
    u8* result = (u8*)stage->field_28c->fn_70_9164(arg2);
    if (!result) return;
    u32 count;
    u32 i = 0;
    count = stage->field_290->data->count;
    void* element;
    while (i != count) {
        element = stage->field_290->fn_70_9164(i);
        if (element) {
            if ((u32)arg1 == 8) {
                if (*(u8*)element == 0x24) break;
            } else if (*(u8*)element == result[arg1]) break;
        }
        ++i;
    }
    if (i == count) return;
    u32 type;
    switch (arg1) {
    case 8:
        type = 0x24;
        break;
    default: {
        u32 j = 0;
        u32 count2 = stage->field_290->data->count;
        while (j != count2) {
            element = stage->field_290->fn_70_9164(j);
            if (element && *(u8*)element == result[arg1]) break;
            ++j;
        }
        if (j == count2) return;
        type = *(u8*)element;
        break;
    }
    }
    Ground* ground;
    switch (type) {
    case 0: ground = fn_70_2B80(0x1f, data + 0x178, data + 0x180); break;
    case 1: ground = fn_70_5960(0x20, data + 0x178, data + 0x198); break;
    case 2: ground = fn_70_2B80(0x21, data + 0x178, data + 0x1b0); break;
    case 3: ground = fn_70_2B80(0x22, data + 0x178, data + 0x1c4); break;
    case 4: ground = fn_70_2B80(0x23, data + 0x178, data + 0x1d8); break;
    case 5: ground = fn_70_2B80(0x24, data + 0x178, data + 0x1ec); break;
    case 6: ground = fn_70_5524(0x25, data + 0x178, data + 0x204); break;
    case 7: ground = fn_70_5524(0x26, data + 0x178, data + 0x218); break;
    case 8: ground = fn_70_2B80(0x27, data + 0x178, data + 0x22c); break;
    case 9: ground = fn_70_2B80(0x28, data + 0x178, data + 0x244); break;
    case 10: ground = fn_70_2B80(0x29, data + 0x178, data + 0x25c); break;
    case 11: ground = fn_70_2B80(0x8, data + 0x270, data + 0x278); break;
    case 12: ground = fn_70_2B80(0x2a, data + 0x178, data + 0x290); break;
    case 13: ground = fn_70_2B80(0x2b, data + 0x178, data + 0x2a8); break;
    case 14: ground = fn_70_2B80(0x2c, data + 0x178, data + 0x2bc); break;
    case 15: ground = fn_70_2B80(0x2d, data + 0x178, data + 0x2d4); break;
    case 16: ground = fn_70_2B80(0x2e, data + 0x178, data + 0x2ec); break;
    case 17: ground = fn_70_2B80(0x2f, data + 0x178, data + 0x304); break;
    case 18: ground = fn_70_2B80(0x30, data + 0x178, data + 0x318); break;
    case 19: ground = fn_70_4D50(0x31, data + 0x178, data + 0x330); break;
    case 20: ground = fn_70_4FE0(0x9, data + 0x348, data + 0x35c); break;
    case 21: ground = fn_70_2B80(0x32, data + 0x178, data + 0x370); break;
    case 22: ground = fn_70_5298(0x33, data + 0x178, data + 0x38c); break;
    case 23: ground = fn_70_5298(0x34, data + 0x178, data + 0x3a4); break;
    case 24: ground = fn_70_2B80(0x35, data + 0x178, data + 0x3c0); break;
    case 25: ground = fn_70_2B80(0x36, data + 0x178, data + 0x3d8); break;
    case 26: ground = fn_70_2B80(0x37, data + 0x178, data + 0x3f0); break;
    case 27: ground = fn_70_2B80(0x38, data + 0x178, data + 0x408); break;
    case 28: ground = fn_70_2B80(0x39, data + 0x178, data + 0x420); break;
    case 29: ground = fn_70_2B80(0x3a, data + 0x178, data + 0x438); break;
    case 30: ground = fn_70_2B80(0x3b, data + 0x178, data + 0x450); break;
    case 31: ground = fn_70_2B80(0x3c, data + 0x178, data + 0x468); break;
    case 32: ground = fn_70_2B80(0x3d, data + 0x178, data + 0x480); break;
    case 33: ground = fn_70_2B80(0x3e, data + 0x178, data + 0x498); break;
    case 34: ground = fn_70_2B80(0x3f, data + 0x178, data + 0x4b0); break;
    case 35: ground = fn_70_2B80(0x40, data + 0x178, data + 0x4c8); break;
    case 36: ground = fn_70_5D24(0x41, data + 0x178, data + 0x4e0); break;
    case 37: ground = fn_70_2B80(0x42, data + 0x178, data + 0x4f8); break;
    case 38: ground = fn_70_2B80(0x43, data + 0x178, data + 0x510); break;
    default: ground = 0; break;
    }
    if (!ground) return;
    addGround__5StageFP6Ground(stage, ground);
    ground->startup(stage->field_1a0, 0, 0);
    ground->fn_70_78C(stage->field_9c);
    ground->fn_70_794(&stage->field_1d8);
    ground->fn_70_7A4(&stage->field_1d9);
    ground->fn_70_13AC(&stage->field_27d[arg1]);
    ground->fn_70_13B4(&stage->field_1e0[arg1]);
    ground->fn_70_13BC(stage->field_1e0);
    ground->fn_70_13C4(type);
    int val = stage->field_288;
    ground->fn_70_4BA4(val);
    ground->slot65(*(f32*)((char*)element + 4));
    ground->fn_70_13CC(element);
    switch (arg1) {
    case 0: ground->fn_70_13D4(rodata[2]); break;
    case 1: ground->fn_70_13D4(rodata[3]); break;
    case 2: ground->fn_70_13D4(rodata[4]); break;
    case 3: ground->fn_70_13D4(rodata[5]); break;
    case 4: ground->fn_70_13D4(rodata[6]); break;
    case 5: ground->fn_70_13D4(rodata[7]); break;
    case 6: ground->fn_70_13D4(rodata[8]); break;
    case 7: ground->fn_70_13D4(rodata[9]); break;
    }
    switch (arg1) {
    case 4:
        if (result[6] == 0x14) {
            stage->field_281 = 5;
            ground->fn_70_13B4(stage->field_24c);
        }
        break;
    case 5:
        if (result[6] == 0x14) {
            stage->field_282 = 5;
            ground->fn_70_13B4(stage->field_258);
        }
        break;
    }
}
}