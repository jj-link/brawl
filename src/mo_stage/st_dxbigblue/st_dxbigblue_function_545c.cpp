#pragma force_active on
extern "C" const float lbl_81_rodata_C0;

struct Data {
    char pad0[0x68];
    float bound;
    char pad6c[0x2c];
    float speed;
};
struct Bounds {
    float left;
    char pad[8];
    float right;
};
struct State {
    unsigned char status;
    char pad[3];
    float pos;
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
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
    virtual void fn_81_570();
    virtual void fn_81_620();
    virtual void createObjPokeTrainer();
    virtual void fn_81_4050();
    virtual void fn_81_404C();
    virtual void fn_81_4040();
    virtual void fn_81_4038();
    virtual void fn_81_4030();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_81_618();
    virtual void process();
    virtual void updateStagePositions();
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
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
    virtual void fn_81_5254();
    virtual void fn_81_4F98();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_81_56B4();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual Data* getStageData();

    char pad40[0x118];
    float timer1;
    Bounds* bounds;
    char pad160[4];
    State* state;
    unsigned char direction;
    char pad169[3];
    float timer2;
    float value;
};

extern "C" void fn_81_545C(Ground* self, float delta) {
    Data* data = self->getStageData();
    if (data) {
        self->timer1 -= delta;
        if (self->timer1 < lbl_81_rodata_C0)
            self->timer1 = lbl_81_rodata_C0;
        self->timer2 -= delta;
        if (self->timer2 < lbl_81_rodata_C0)
            self->timer2 = lbl_81_rodata_C0;
        if (self->direction == 1) {
            self->state->pos += data->speed * delta;
            if (self->state->pos > self->bounds->right + data->bound)
                self->state->status = 10;
        } else {
            self->state->pos -= data->speed * delta;
            if (self->state->pos < self->bounds->left - data->bound)
                self->state->status = 10;
        }
        if (lbl_81_rodata_C0 == self->timer2)
            self->value = lbl_81_rodata_C0;
    }
}
