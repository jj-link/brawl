#pragma force_active on
extern "C" const float lbl_81_rodata_D0;
extern "C" const float lbl_81_rodata_D4;

struct Data {
    char pad[0xd0];
    float speed;
    char pad2[4];
    float resetTimer;
};

struct Obj15C {
    char pad[0xc];
    float offset;
};

struct State {
    unsigned char status;
    char pad[3];
    float pos;
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
    virtual void fn_81_5EE4();
    virtual void fn_81_4F98();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_81_5130();
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
    float timer;
    Obj15C* p15c;
    char pad160[4];
    State* state;
};

extern "C" void fn_81_60D8(Ground* self, float delta) {
    Data* data = self->getStageData();
    if (data != 0) {
        self->timer = self->timer - delta;
        if (self->timer < lbl_81_rodata_D0) {
            self->timer = lbl_81_rodata_D0;
        }
        switch (self->state->status) {
        case 1:
            self->state->pos = self->state->pos + data->speed * delta;
            if (self->state->pos > lbl_81_rodata_D0) {
                self->state->pos = lbl_81_rodata_D0;
                self->timer = data->resetTimer;
                self->state->status = 2;
            }
            break;
        case 2:
            if (lbl_81_rodata_D0 == self->timer) {
                self->state->status = 3;
            }
            break;
        case 3:
            self->state->pos = self->state->pos + data->speed * delta;
            if (self->state->pos > lbl_81_rodata_D4 + self->p15c->offset) {
                self->state->status = 10;
            }
            break;
        }
    }
}
