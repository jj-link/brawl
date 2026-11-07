#pragma force_active on

struct Vec3f;

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
    virtual void fn_50_B464();
    virtual void fn_50_B4D4();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(int);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_50_2324();
    virtual void startup();
    virtual void setNode();
    virtual void fn_50_690();
    virtual int fn_50_231C();

    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0xc];
    Vec3f* pos;
    unsigned char* trigger;
    char pad16c[4];
    char gen[0x10];
};

extern "C" {
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);
extern const float lbl_50_rodata_1A4;
extern const float lbl_50_rodata_1AC;

void fn_50_B554(Ground* self, float delta) {
    if (self->fn_50_231C()) {
        self->timer -= delta;
        if (self->timer < lbl_50_rodata_1A4)
            self->timer = lbl_50_rodata_1A4;
        switch (self->state) {
        case 0:
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            if ((unsigned char)(*self->trigger + 252) <= 1) {
                self->setVisibility(1);
                playSE__14snd3DGeneratorF5SndIDiii(self->gen, 0x1b89, 0, 0, -1);
                setPos__14snd3DGeneratorFP5Vec3f(self->gen, self->pos);
                self->state = 8;
                self->timer = lbl_50_rodata_1AC;
            }
            break;
        case 8:
            if (lbl_50_rodata_1A4 == self->timer) {
                *self->trigger = 6;
                self->state = 0;
            }
            break;
        }
    }
}
}
