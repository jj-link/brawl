#pragma force_active on
extern "C" const float lbl_81_rodata_C0;
extern "C" const float lbl_81_rodata_C8;

struct Data { char pad[0x98]; float speed; };
struct Bounds { float left; char pad[8]; float right; };
struct State { char pad[4]; float pos; };

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_81_58D8();
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
    virtual void fn_81_587C();
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
    virtual void fn_81_5D4C();
    virtual void setStageData();
    virtual Data* getStageData();
    char pad40[0x118];
    float timer;
    Bounds* bounds;
    char pad160[4];
    State* state;
    unsigned char direction;
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

extern "C" void fn_81_5B14(Ground* self, float delta) {
    Data* data = self->getStageData();
    if (data) {
        self->timer -= delta;
        if (self->timer < lbl_81_rodata_C0)
            self->timer = lbl_81_rodata_C0;
        if (self->direction == 1) {
            self->state->pos += data->speed * delta;
            if (self->state->pos > lbl_81_rodata_C8 * self->bounds->right)
                self->direction = 0;
        } else {
            self->state->pos -= data->speed * delta;
            if (self->state->pos < lbl_81_rodata_C8 * self->bounds->left)
                self->direction = 1;
        }
    }
}