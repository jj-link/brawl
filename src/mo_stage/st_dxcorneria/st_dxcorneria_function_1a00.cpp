#include <types.h>
#include <gf/gf_model.h>
#include <mt/mt_matrix.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on
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
    virtual void slot22();
    virtual void update();
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
    virtual void fn_82_4424();
    virtual void startup();
    virtual void setNode();
    virtual void fn_82_1088();
    virtual void fn_82_441C();
    virtual void fn_82_4418();
    virtual void fn_82_4108();
    virtual void fn_82_4410();
    virtual void fn_82_4404();
    virtual void fn_82_43F4();
    virtual void fn_82_43E4();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix(Matrix*, unsigned long, unsigned long);
};
struct Config {
    char pad0[0x44]; float min; float max; char pad4c[0x28]; int interval; int count;
};
struct AnimEntry {
    char pad0[8]; int kind; int id; int active; char pad14[4];
    char flag18; char flag19; char flag1a; char hasPos;
    float x; float y; float z; char pad28[0xc];
    bool isActive() const { return active != 0; }
    inline void start(int newId, bool a, bool b, bool c, Vec3f* pos) {
        if (active == 0) {
            active = 1; id = newId; kind = 6;
            if (pos != 0) {
                x = pos->m_x; y = pos->m_y; z = pos->m_z; hasPos = 1;
            } else { hasPos = 0; }
            flag18 = a; flag19 = b; flag1a = c;
        }
    }
};
struct State {
    char pad0[0x1d8]; Config* config; char pad1[0x24]; AnimEntry anims[32]; int animCount;
    char pad3[0xf18 - 0x884]; float timer; int unkF1C; Ground* ground; int variant;
    char pad4[4]; Ground* madein; unsigned long node; char pad5[8];
    int unkF3C; int unkF40; int unkF44; char pad6[4]; float f4c; float f50;
    char pad7[0x1008 - 0xf54]; snd3DGenerator generator; int sound0; int sound1;
    inline void request(int id, bool a, bool b, bool c, Vec3f* pos) {
        AnimEntry* entry = anims;
        for (int i = 0; i < animCount; ++i, ++entry) {
            if (!entry->isActive()) {
                entry->start(id, a, b, c, pos); break;
            }
        }
    }
};
extern "C" {
void fn_82_1844(State*);
int isEndEntity__8grMadeinFv(void*);
void endEntity__8grMadeinFv(void*);
void startEntityAutoLoop__8grMadeinFv(void*);
void setEnableCollisionStatus__6GroundFb(void*, int);
void fn_8003E87C(Matrix*, float);
void fn_27_279FC8(void*, Matrix*, int);
int fn_82_2024(State*, Vec3f*);
unsigned long getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
}

extern "C" void fn_82_1A00(State* self, float dt) {
    float pool00 = 4.203895392974451e-44f;
    float pool04 = 7.006492321624085e-45f;
    float pool08 = 1.3089970350265503f;
    float pool0c = 6.0f;
    float pool_zeroValue = 0.0f;
    float pool_heightOffset = 10.0f;
    float pool18 = 7.0f;
    float pool1c = -1000.0f;
    float pool_one = 1.0f;
    float pool24 = 50.0f;
    float pool28 = -250.0f;
    float pool2c = 4.0f;
    float pool30 = 80.0f;
    float pool34 = -3.0f;
    float pool38 = -200.0f;
    float pool3c = -1.0f;
    float pool40 = 8.0f;
    float pool44 = 0.29411765933036804f;
    float pool48 = 2.0f;
    double pool50 = 4503601774854144.0;
    float pool_soundLead = 120.0f;
    float pool_angleStep = 0.31415927f;
    float pool_leftTurn = -6.2831855f;
    float pool_rightTurn = 6.2831855f;
    double pool68 = 4503599627370496.0;
    self->timer = self->timer - dt;
    if (self->timer <= 0.0f && self->ground == 0) { fn_82_1844(self); }
    if (self->ground != 0 && self->madein != 0) {
        if (isEndEntity__8grMadeinFv(self->madein)) {
            endEntity__8grMadeinFv(self->madein);
            self->madein = 0;
            endEntity__8grMadeinFv(self->ground);
            self->ground = 0;
            float random = randf();
            float one = 1.0f;
            float r = one * random;
            float range = self->config->max - self->config->min;
            self->timer = range * r + self->config->min;
            return;
        }
        Matrix m50(true);
        self->madein->getNodeMatrix(&m50, 0, self->node);
        Vec3f pos = m50.getPosition();
        pos.m_y += 10.0f;
        m50.m[1][3] = pos.m_y;
        m50.m[2][3] = pos.m_z;
        self->generator.setPos(&pos);
        if (self->sound0 == 0) {
            self->sound0 = self->generator.playSE((SndID)(self->variant == 0 ? 0x1dbb : 0x1dbc), -1, 0, -1);
        }
        if (self->sound1 == 0) {
            gfModelAnimation** table = *(gfModelAnimation***)((char*)self->madein + 0x48);
            gfModelAnimation* anim = table[0];
            if (anim != 0) {
                float count = getFrameCount__16gfModelAnimationFd(anim);
                float frame = getFrame__16gfModelAnimationFd(anim);
                if (120.0f + frame >= count) {
                    self->sound1 = self->generator.playSE((SndID)0x1dbd, -1, 0, -1);
                }
            }
        }
        if (((((unsigned char*)self->ground)[0x6c] >> 7) & 1) == 0) {
            if (self->f50 <= 0.0f) { startEntityAutoLoop__8grMadeinFv(self->ground); }
            else { self->f50 = self->f50 - dt; }
        }
        float angle;
        float zero = 0.0f;
        angle = self->f4c;
        if (zero != angle) {
            if (angle < zero) {
                self->f4c = angle + 0.31415927f * dt;
                self->f4c = nw4r::math::FSelect(zero - self->f4c, self->f4c, zero);
            } else {
                self->f4c = angle - 0.31415927f * dt;
                self->f4c = nw4r::math::FSelect(zero - self->f4c, zero, self->f4c);
            }
            Matrix m20(true);
            m20.setIdentity();
            fn_8003E87C(&m20, self->f4c);
            m50.mul(&m20, &m50);
            self->timer = self->config->interval;
            setEnableCollisionStatus__6GroundFb(self->ground, 0);
        } else { setEnableCollisionStatus__6GroundFb(self->ground, self->variant == 0); }
        fn_27_279FC8(self->ground, &m50, 0);
        if (0.0f == self->f4c && self->timer <= 0.0f) {
            self->timer = self->config->interval;
            unsigned long n = self->config->count - 1;
            unsigned long r = randi(n + 1);
            if (r >= n) { r = n; }
            if (r == 1) {
                int played = 0;
                Vec3f target;
                Vec3f* posPtr = 0;
                if (self->variant == 1) {
                    if (fn_82_2024(self, &target) != 0) {
                        posPtr = &target;
                        self->generator.playSE((SndID)0x1dc6, -1, 0, -1);
                        played = 1;
                    }
                } else {
                    self->generator.playSE((SndID)0x1dbe, -1, 0, -1);
                    played = 1;
                }
                if (played != 0) {
                    if (self->unkF1C == 0) {
                        self->request(self->unkF3C, self->variant == 0, true, true, posPtr);
                        self->request(self->unkF40, self->variant == 0, self->variant == 1, true, posPtr);
                    } else {
                        self->request(self->unkF44, self->variant == 0, true, true, posPtr);
                    }
                }
            } else if (self->variant == 0) {
                unsigned long r2 = randi(16);
                if (r2 >= 15) { r2 = 15; }
                if (r2 == 1) {
                    unsigned long r3 = randi(8);
                    if (r3 >= 7) { r3 = 7; }
                    float angle;
                    if (r3 & 1) { angle = -6.2831855f; }
                    else { angle = 6.2831855f; }
                    self->f4c = angle;
                }
            }
        }
    }
}
