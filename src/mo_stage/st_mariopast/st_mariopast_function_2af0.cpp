#pragma force_active on

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_48_2AF0_v();
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
    virtual void fn_48_2A98();
    virtual void fn_48_2E30();
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
    virtual void fn_48_203C();
    virtual void startup();
    virtual void fn_48_2F68();
    virtual void fn_48_7BC();
    virtual void fn_48_2034();
    virtual void fn_48_2030();
    virtual void fn_48_1F20();
    virtual void fn_48_2028();
    virtual void fn_48_201C();
    virtual void fn_48_200C();
    virtual void fn_48_1FFC();
    virtual void getNodeIndex();
    virtual void getNodePosition(float* pos, unsigned long sceneModelIndex, unsigned long nodeIndex);

    char pad1[0x158 - 0x40];
    float* p158;
    float* p15c;
    unsigned char flag160;
    char pad161[3];
    int v164;
    int v168;
    int v16c;
    int v170;
    int v174;
    int v178;
};

extern "C" const float lbl_48_rodata_18[];
extern "C" void processAnim__6GroundFv(Ground* self);

extern "C" void fn_48_2AF0(Ground* self) {
    const float* c = lbl_48_rodata_18;
    processAnim__6GroundFv(self);
    if (self->p15c != 0) {
        switch (self->flag160) {
        case 1:
            break;
        case 0:
            self->getNodePosition(self->p15c + 6, 0, self->v164);
            break;
        }
        self->getNodePosition(self->p15c + 9, 0, self->v168);
        self->getNodePosition(self->p15c + 12, 0, self->v16c);
        self->getNodePosition(self->p15c + 15, 0, self->v170);
        self->getNodePosition(self->p15c + 18, 0, self->v174);
        self->getNodePosition(self->p15c + 33, 0, self->v178);

        float f = *self->p158;
        switch (self->flag160) {
        case 0:
            if (f >= c[0] && f < c[2]) {
                float* p = self->p15c;
                p[0] = p[9];
                p[1] = p[10];
                p[2] = p[11];
            } else if (f >= c[2] && f <= c[3]) {
                float* p = self->p15c;
                p[0] = p[12];
                p[1] = p[13];
                p[2] = p[14];
            }
            if (f >= c[0] && f < c[4]) {
                float* p = self->p15c;
                p[3] = p[15];
                p[4] = p[16];
                p[5] = p[17];
                break;
            }
            if (f >= c[4] && f <= c[3]) {
                float* p = self->p15c;
                p[3] = p[18];
                p[4] = p[19];
                p[5] = p[20];
            }
            break;
        case 1:
            if (f >= c[0] && f < c[5]) {
                float* p = self->p15c;
                p[0] = p[9];
                p[1] = p[10];
                p[2] = p[11];
            } else if (f >= c[5] && f <= c[6]) {
                float* p = self->p15c;
                p[0] = p[12];
                p[1] = p[13];
                p[2] = p[14];
            }
            if (f >= c[0] && f < c[7]) {
                float* p = self->p15c;
                p[3] = p[15];
                p[4] = p[16];
                p[5] = p[17];
                break;
            }
            if (f >= c[7] && f <= c[6]) {
                float* p = self->p15c;
                p[3] = p[18];
                p[4] = p[19];
                p[5] = p[20];
            }
            break;
        }
    }
}
