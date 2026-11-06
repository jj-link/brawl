#include <st/stage.h>
#pragma force_active on

struct GroundViewBase { char pad[0x3c]; };
struct GroundView : GroundViewBase {
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
    virtual void fn_74_2F84();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_74_EFC(void*);
    virtual void fn_74_2F7C();
    virtual void fn_74_2F78();
    virtual void fn_74_2644();
    virtual void fn_74_2F70();
    virtual void fn_74_2F64();
    virtual void fn_74_2F54();
    virtual void fn_74_2F44();
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
    virtual void fn_74_2F40();
    virtual void fn_74_2F3C();
    virtual void fn_74_2F34();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_74_2F2C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void slot76();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_74_2FB0();
    virtual void fn_74_2FA8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_74_2FA0();
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
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119(void*);
};
struct Params { char pad[8]; float value; };
struct Entry { float a, b; char pad[0x1b]; unsigned char flag, id; char tail[3]; };
struct StageFields { char pad[0x9c]; Params* params; char pad2[0x100]; void* archive; char pad3[0x48]; Entry entries[10]; };

extern "C" {
extern char lbl_74_data_0[];
extern const float lbl_74_rodata_0[];
Ground* fn_74_3834(int, const char*, const char*);
void fn_74_FD4(Stage* stage, int kind) {
    StageFields* self = (StageFields*)stage;
    Ground* ground;
    Params* params = self->params;
    Entry* entry = (Entry*)lbl_74_rodata_0;
    char* data = lbl_74_data_0;
    if (params) {
        switch (kind) {
        case 3: {
            Ground* temp = fn_74_3834(2, data + 0x74, data + 0x88);
            float value = ((const float*)entry)[11];
            entry = &self->entries[0];
            entry->a = value;
            ground = temp;
            self->entries[0].b = params->value;
            self->entries[0].flag = 0;
            self->entries[0].id = 0;
            break;
        }
        case 4: {
            Ground* temp = fn_74_3834(3, data + 0x9c, data + 0xb0);
            float value = ((const float*)entry)[12];
            entry = &self->entries[1];
            entry->a = value;
            ground = temp;
            self->entries[1].b = params->value;
            self->entries[1].flag = 0;
            self->entries[1].id = 1;
            break;
        }
        case 5: {
            Ground* temp = fn_74_3834(4, data + 0xc4, data + 0xd8);
            float value = ((const float*)entry)[13];
            entry = &self->entries[2];
            entry->a = value;
            ground = temp;
            self->entries[2].b = params->value;
            self->entries[2].flag = 0;
            self->entries[2].id = 2;
            break;
        }
        case 6: {
            Ground* temp = fn_74_3834(5, data + 0xec, data + 0x100);
            float value = ((const float*)entry)[14];
            entry = &self->entries[3];
            entry->a = value;
            ground = temp;
            self->entries[3].b = params->value;
            self->entries[3].flag = 1;
            self->entries[3].id = 3;
            break;
        }
        case 7: {
            Ground* temp = fn_74_3834(6, data + 0x114, data + 0x128);
            float value = ((const float*)entry)[15];
            entry = &self->entries[4];
            entry->a = value;
            ground = temp;
            self->entries[4].b = params->value;
            self->entries[4].flag = 1;
            self->entries[4].id = 4;
            break;
        }
        case 8: {
            Ground* temp = fn_74_3834(7, data + 0x13c, data + 0x150);
            float value = ((const float*)entry)[16];
            entry = &self->entries[5];
            entry->a = value;
            ground = temp;
            self->entries[5].b = params->value;
            self->entries[5].flag = 1;
            self->entries[5].id = 5;
            break;
        }
        case 9: {
            Ground* temp = fn_74_3834(12, data + 0x164, data + 0x178);
            float value = ((const float*)entry)[11];
            entry = &self->entries[6];
            entry->a = value;
            ground = temp;
            self->entries[6].b = params->value;
            self->entries[6].flag = 0;
            self->entries[6].id = 6;
            break;
        }
        case 10: {
            Ground* temp = fn_74_3834(13, data + 0x18c, data + 0x1a0);
            float value = ((const float*)entry)[16];
            entry = &self->entries[7];
            entry->a = value;
            ground = temp;
            self->entries[7].b = params->value;
            self->entries[7].flag = 0;
            self->entries[7].id = 7;
            break;
        }
        case 11: {
            Ground* temp = fn_74_3834(14, data + 0x1b4, data + 0x1c8);
            float value = ((const float*)entry)[12];
            entry = &self->entries[8];
            entry->a = value;
            ground = temp;
            self->entries[8].b = params->value;
            self->entries[8].flag = 1;
            self->entries[8].id = 8;
            break;
        }
        case 12: {
            Ground* temp = fn_74_3834(15, data + 0x1dc, data + 0x1f0);
            float value = ((const float*)entry)[15];
            entry = &self->entries[9];
            entry->a = value;
            ground = temp;
            self->entries[9].b = params->value;
            self->entries[9].flag = 1;
            self->entries[9].id = 9;
            break;
        }
        default: ground = 0; break;
        }
        if (ground) {
            stage->addGround(ground);
            GroundView* view = (GroundView*)ground;
            view->slot119(entry);
            view->startup(self->archive, 0, 0);
            view->fn_74_EFC(self->params);
        }
    }
}
}
