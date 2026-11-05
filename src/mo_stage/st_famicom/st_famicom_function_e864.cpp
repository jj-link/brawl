#pragma force_active on
#pragma switch_tables on

typedef unsigned char u8;

struct Entry {
    u8 pad[0x0C];
    float x;
    float y;
    float z;
    u8 active;
    u8 pad2[0x0F];
};

struct Base {
    u8 pad[0x3C];
};

class Ground : public Base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_68_A240();
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
    virtual void fn_68_E80C();
    virtual void fn_68_A290();
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
    virtual void fn_68_249C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_68_97C();
    virtual void fn_68_2494();
    virtual void fn_68_2490();
    virtual void fn_68_2390();
    virtual void fn_68_2488();
    virtual void fn_68_247C();
    virtual void fn_68_246C();
    virtual void fn_68_B50();
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
    virtual void fn_68_2468();
    virtual void fn_68_2464();
    virtual void fn_68_245C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_68_2454();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_68_24C8();
    virtual void fn_68_24C0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_68_24B8();
    virtual void fn_68_C5BC();
    virtual void fn_68_C6C4();
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
    virtual void fn_68_A34C();
    virtual void fn_68_A410();
    virtual void fn_68_E864();
    virtual void fn_68_BBDC();
    virtual void fn_68_BDF0();
    virtual void fn_68_E9BC();
    virtual void fn_68_EB58();
    virtual void fn_68_ECC4();
    virtual void fn_68_C6FC();
    virtual void fn_68_F444();
    virtual void fn_68_F7FC();
    virtual void fn_68_FABC();
    virtual void fn_68_FC1C();
    virtual void fn_68_FE64();
    virtual void fn_68_C714();
    virtual void fn_68_C718();
    virtual void fn_68_C7E4();
    virtual void fn_68_20EC();
    virtual void fn_68_20F4();
    virtual void fn_68_20FC();
    virtual void fn_68_2104();
    virtual void fn_68_210C();
    virtual void fn_68_C8B4();
    virtual void fn_68_C980();
    virtual void fn_68_C9C4();
    virtual void fn_68_CA28();
    virtual void fn_68_CAF0();
    virtual void fn_68_CB78();
    virtual void fn_68_FF9C();
    virtual void fn_68_FFB4();
    virtual void fn_68_ED60();
    virtual void fn_68_F62C();

    u8 pad1[0x158 - 0x40];
    u8 state;
    u8 pad2[3];
    float timer;
    float wait;
    u8 pad3[0x174 - 0x164];
    u8 count;
    u8 index;
    u8 pad4[2];
    Entry* entries;
};

extern "C" void fn_68_BB4C(Ground*);
extern "C" const float lbl_68_rodata_148[];

extern "C" void fn_68_E864(Ground* self) {
    const float* c = lbl_68_rodata_148;
    fn_68_BB4C(self);
    switch (self->state) {
    case 3:
    case 7:
    case 11:
        if (c[0] == self->timer) {
            if (self->entries[self->index].active == 1) {
                self->entries[self->index].active = 0;
                Entry* e = &self->entries[self->index];
                e->x = c[0];
                e->y = c[1];
                e->z = c[0];
            } else {
                self->entries[self->index].active = 1;
                Entry* e = &self->entries[self->index];
                e->x = c[0];
                e->y = c[0];
                e->z = c[0];
            }
            self->fn_68_FABC();
            self->wait = c[2];
        }
        return;
    case 0:
    case 4:
    case 8:
        self->fn_68_F62C();
        return;
    case 1:
    case 5:
    case 9:
        if (c[0] == self->timer) {
            self->count++;
            if (self->count > 3) self->count = 3;
            self->fn_68_FABC();
        }
        return;
    }
}
