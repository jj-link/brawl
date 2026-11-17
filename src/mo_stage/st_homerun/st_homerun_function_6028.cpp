#pragma force_active on

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_88_4DBC();
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
    virtual void fn_88_5F44();
    virtual void fn_88_5F9C();
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
    virtual void fn_88_447C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_88_B1C();
    virtual void fn_88_4474();
    virtual void fn_88_4470();
    virtual void fn_88_4360();
    virtual void fn_88_4468();
    virtual void fn_88_445C();
    virtual void fn_88_444C();
    virtual void fn_88_443C();
    virtual void getNodeIndex();
    virtual void getNodePosition(float*, int, void*);
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
    virtual void fn_88_4438();
    virtual void fn_88_4434();
    virtual void fn_88_442C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();

    unsigned char pad40[0x2c];
    unsigned char x6C;
    unsigned char pad6D[0x57];
    void* xC4;
    unsigned char padC8[0x88];
    unsigned char x150;
    unsigned char pad151[3];
    float x154;
    unsigned char pad158[8];
    float* x160;
    unsigned char pad164[0x14];
    unsigned char x178;
    unsigned char pad179[7];
    float x180, x184, x188;
};

extern "C" void fn_88_6028(Ground* self, float f) {
    f = self->x154 - f;
    self->x154 = f;
    if (f < 0.0f)
        self->x154 = 0.0f;

    switch (self->x150) {
    case 0:
        self->updateG3dProcCalcWorld();
        self->x6C &= ~2;
        self->getNodePosition(&self->x180, 0, self->xC4);

        switch (self->x178) {
        case 2:
            self->x180 -= 3000.0f;
            break;
        case 4:
            self->x180 += 3000.0f;
            break;
        case 5:
            self->x180 += 6000.0f;
            break;
        }

        switch (self->x178) {
        case 2: {
            float* p = self->x160;
            p[0] = self->x180;
            p[1] = self->x184;
            p[2] = self->x188;
            break;
        }
        case 3: {
            float* p = self->x160;
            p[3] = self->x180;
            p[4] = self->x184;
            p[5] = self->x188;
            break;
        }
        case 4: {
            float* p = self->x160;
            p[6] = self->x180;
            p[7] = self->x184;
            p[8] = self->x188;
            break;
        }
        case 5: {
            float* p = self->x160;
            p[9] = self->x180;
            p[10] = self->x184;
            p[11] = self->x188;
            break;
        }
        }

        self->x150 = 1;
    case 1:
        self->x150 = 2;
        break;
    case 2:
        break;
    }
}
