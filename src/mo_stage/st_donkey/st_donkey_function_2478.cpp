#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct GroundBase {
    char padding[0x3C];
};

struct Ground : GroundBase {
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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void slot36();
    virtual void startup();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f* p, unsigned long a, unsigned long b);

    void processAnim();

    char pad[0x128];
    Vec3f* data;
    int vals[43];
};

extern "C" void processAnim__6GroundFv(Ground* self);

extern "C" void fn_50_2478(Ground* self) {
    processAnim__6GroundFv(self);
    if (self->data != 0) {
        self->getNodePosition(self->data, 0, self->vals[0]);
        self->getNodePosition(self->data + 1, 0, self->vals[1]);
        self->getNodePosition(self->data + 2, 0, self->vals[2]);
        self->getNodePosition(self->data + 3, 0, self->vals[3]);
        self->getNodePosition(self->data + 4, 0, self->vals[4]);
        self->getNodePosition(self->data + 5, 0, self->vals[5]);
        self->getNodePosition(self->data + 6, 0, self->vals[6]);
        self->getNodePosition(self->data + 7, 0, self->vals[7]);
        self->getNodePosition(self->data + 8, 0, self->vals[8]);
        self->getNodePosition(self->data + 9, 0, self->vals[9]);
        self->getNodePosition(self->data + 10, 0, self->vals[10]);
        self->getNodePosition(self->data + 11, 0, self->vals[11]);
        self->getNodePosition(self->data + 12, 0, self->vals[12]);
        self->getNodePosition(self->data + 13, 0, self->vals[13]);
        self->getNodePosition(self->data + 14, 0, self->vals[14]);
        self->getNodePosition(self->data + 15, 0, self->vals[15]);
        self->getNodePosition(self->data + 16, 0, self->vals[16]);
        self->getNodePosition(self->data + 17, 0, self->vals[17]);
        self->getNodePosition(self->data + 18, 0, self->vals[18]);
        self->getNodePosition(self->data + 19, 0, self->vals[19]);
        self->getNodePosition(self->data + 20, 0, self->vals[20]);
        self->getNodePosition(self->data + 21, 0, self->vals[21]);
        self->getNodePosition(self->data + 22, 0, self->vals[22]);
        self->getNodePosition(self->data + 23, 0, self->vals[23]);
        self->getNodePosition(self->data + 24, 0, self->vals[24]);
        self->getNodePosition(self->data + 25, 0, self->vals[25]);
        self->getNodePosition(self->data + 26, 0, self->vals[26]);
        self->getNodePosition(self->data + 27, 0, self->vals[27]);
        self->getNodePosition(self->data + 28, 0, self->vals[28]);
        self->getNodePosition(self->data + 29, 0, self->vals[29]);
        self->getNodePosition(self->data + 30, 0, self->vals[30]);
        self->getNodePosition(self->data + 31, 0, self->vals[31]);
        self->getNodePosition(self->data + 32, 0, self->vals[32]);
        self->getNodePosition(self->data + 33, 0, self->vals[33]);
        self->getNodePosition(self->data + 34, 0, self->vals[34]);
        self->getNodePosition(self->data + 35, 0, self->vals[35]);
        self->getNodePosition(self->data + 36, 0, self->vals[36]);
        self->getNodePosition(self->data + 37, 0, self->vals[37]);
        self->getNodePosition(self->data + 38, 0, self->vals[38]);
        self->getNodePosition(self->data + 39, 0, self->vals[39]);
        self->getNodePosition(self->data + 40, 0, self->vals[40]);
        self->getNodePosition(self->data + 41, 0, self->vals[41]);
        self->getNodePosition(self->data + 42, 0, self->vals[42]);
    }
}
