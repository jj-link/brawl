#pragma force_active on
class grCollStatus;

extern "C" float randf__Fv();
extern "C" const float lbl_47_rodata_110[];
extern int lbl_47_data_2E20;

struct CollTarget {
    char pad0[0x48];
    float threshold;
};

struct Ground_base {
    char pad[0x3C];
};

struct Ground : Ground_base {
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
    virtual void renderDebug();
    virtual void init();
    virtual void fn_47_BA84();
    virtual void fn_47_BADC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_47_CB54_vfn();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_47_1A28();
    virtual void startup();
    virtual void setNode();
    virtual void fn_47_5A0();
    virtual CollTarget* fn_47_1A20();

    bool isCollisionStatusOwnerTask(grCollStatus* collStatus, int* data);

    char pad40[0x124];
    float unk164;
    char pad168[0x29];
    signed char unk191;
    char pad192[2];
    float unk194;
};

extern "C" void fn_47_CB54(Ground* self, grCollStatus* collStatus, int unused, unsigned int arg3) {
    const float* c = lbl_47_rodata_110;
    CollTarget* target = self->fn_47_1A20();
    if (target != 0 && self->isCollisionStatusOwnerTask(collStatus, &lbl_47_data_2E20)) {
        if (c[0] == self->unk194) {
            if (randf__Fv() < target->threshold) {
                self->unk191 = 1;
            } else {
                self->unk191 = 0;
            }
        }
        self->unk194 = c[2];
        if (arg3 == 1 && c[0] == self->unk164) {
            self->unk164 = c[3];
        }
    }
}
