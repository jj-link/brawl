#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const float lbl_52_rodata_2E8[];
extern float randf__Fv();
}

struct Vec3 { float x; float y; float z; };

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
    virtual void fn_52_11068();
    virtual void fn_52_110C0();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual float* fn_52_36E4();

    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char pad158[8];
    float (*mtx)[4];
    float pos0;
    float pos1;
    float pos2;
    float* p170;
    unsigned char* p174;
};

extern "C" void fn_52_11134(Ground* self, float delta) {
    const float* c = lbl_52_rodata_2E8;
    float* p = self->fn_52_36E4();
    if (p != 0) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            if (*self->p174 == 0) {
                float d = self->mtx[2][3];
                float b = self->mtx[1][3];
                float a = self->mtx[0][3];
                self->pos0 = a;
                self->pos1 = b;
                self->pos2 = d;
                self->pos0 = self->p170[0] - c[1];
                self->pos2 = c[2] + c[3] * randf__Fv();
                self->setVisibility(1);
                self->state = 4;
            }
            break;
        case 4: {
            float speed = p[0] * delta;
            Vec3 v;
            float d = self->mtx[2][3];
            float b = self->mtx[1][3];
            float a = self->mtx[0][3];
            v.x = a;
            v.y = b;
            v.z = d;
            self->pos1 = v.y;
            self->pos0 += speed;
            if (self->pos0 > c[1] + self->p170[3]) {
                *self->p174 = 7;
                self->state = 0;
            }
            break;
        }
        }
    }
}