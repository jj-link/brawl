#pragma force_active on

extern "C" {
extern float lbl_27_data_547E0;
extern const float lbl_70_rodata_48;
extern char lbl_70_data_1464[];
extern char lbl_70_data_1474[];

void setUpdateRate__16gfModelAnimationFf(void* self, float rate);
void processAnim__6GroundFv(void* self);
}

struct GameGlobal {
    char pad[0x44];
    struct {
        float a;
        float b;
        float c;
    }* p;
};
extern GameGlobal* g_GameGlobal;

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_70_51C4();
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
    virtual void fn_70_5090();
    virtual void fn_70_2F10();
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
    virtual void fn_70_3E0C();
    virtual void fn_70_22A8();
    virtual void startup();
    virtual void setNode();
    virtual void fn_70_78C();
    virtual void fn_70_22A0();
    virtual void fn_70_229C();
    virtual void fn_70_2080();
    virtual void fn_70_2294();
    virtual void fn_70_2288();
    virtual void fn_70_2278();
    virtual void fn_70_2268();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual bool getNodePosition_2(void* nodePos, unsigned int sceneModelIndex, const char* nodeName);

    char pad40[0x24];
    float rate;
    char pad68[5];
    unsigned char f0 : 3;
    unsigned char f1 : 1;
    char pad6e[0x178 - 0x6e];
    int idx;
    char pad17c[0x1c8 - 0x17c];
    void* anim;
};

extern "C" void fn_70_51C4(Ground* self) {
    GameGlobal* g = g_GameGlobal;
    float k = lbl_27_data_547E0;
    float f = self->rate * k;
    f *= g->p->b;
    f *= g->p->c;
    if (self->f1 == 1) {
        f = lbl_70_rodata_48;
    }
    setUpdateRate__16gfModelAnimationFf(self->anim, f);
    processAnim__6GroundFv(self);
    if (self->idx) {
        self->getNodePosition_2((void*)(self->idx + 0x6c), 0, lbl_70_data_1464);
        self->getNodePosition_2((void*)(self->idx + 0x78), 0, lbl_70_data_1474);
    }
}