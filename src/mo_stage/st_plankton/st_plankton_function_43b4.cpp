#pragma force_active on

extern "C" const float lbl_74_rodata_D0;

struct Ground_base { char pad[0x3c]; };

struct PlanktonState {
    float pad;
    float pos;
};

struct PlanktonData {
    float pad0;
    float pad4;
    float target;
    float pad_c;
    float pad_10;
    float pad_14;
    float max;
    float min;
    float duration;
    float speed;
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_74_3B38();
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
    virtual void fn_74_3A48();
    virtual void fn_74_3BB4();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_74_4F98();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_74_2F84();
    virtual void startup();
    virtual void fn_74_4B64();
    virtual void fn_74_EFC();
    virtual void* fn_74_2F7C();

    char pad40[0x118];
    PlanktonState* state;
    char pad15c[0x10];
    float timer;
};

extern "C" void fn_74_43B4(Ground* self, float delta) {
    PlanktonData* data = (PlanktonData*)self->fn_74_2F7C();
    if (data) {
        self->timer -= delta;
        if (self->timer < lbl_74_rodata_D0)
            self->timer = lbl_74_rodata_D0;

        float pos = self->state->pos;

        if (lbl_74_rodata_D0 == self->timer) {
            if (pos != data->target) {
                if (pos > data->target) {
                    pos -= data->speed;
                    if (pos < data->target)
                        pos = data->target;
                    else
                        self->timer = data->duration;
                } else {
                    pos += data->speed;
                    if (pos > data->target)
                        pos = data->target;
                    else
                        self->timer = data->duration;
                }
            }
        } else {
            if (pos < data->min)
                pos = data->min;
            if (pos > data->max)
                pos = data->max;
        }

        self->state->pos = pos;
    }
}