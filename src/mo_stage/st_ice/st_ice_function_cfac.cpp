#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>

struct GroundBase {
    char pad0[0x3c];
};

struct Ret {
    char pad0[0x7c];
    float f7c;
};

struct Data158 {
    char pad0[0xc];
    float ax;
    char pad1[0xc];
    float ay;
    char pad2[0xc];
    float az;
    char pad3[0xc];
    float bx;
    char pad4[0xc];
    float by;
    char pad5[0xc];
    float bz;
};

struct Bounds {
    float v0;
    char pad[8];
    float v3;
};

struct Ground : GroundBase {
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
    virtual void fn_62_CEE0();
    virtual void fn_62_CF38();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping(unsigned long);
    virtual void setVisibilityAttachedEffect(unsigned long);
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup();
    virtual void setNode();
    virtual void fn_62_A44();
    virtual Ret* fn_62_310C();

    char pad40[0x2c];
    unsigned char flag6C;
    char pad6D[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    Data158* data158;
    float f15C;
    float f160;
    float f164;
    void setPosition(float z, float x, float y) {
        f160 = y;
        f15C = x;
        f164 = z;
    }
    void setPosition2(float x, float y) {
        f160 = y;
        f15C = x;
    }
    Bounds* bounds168;
    unsigned char* p16C;
};

extern "C" void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern "C" const float lbl_62_rodata_158[];

extern "C" void fn_62_CFAC(Ground* self, float delta) {
    const float* k = lbl_62_rodata_158;
    if (self->data158 != 0) {
        Ret* r = self->fn_62_310C();
        if (r != 0) {
            self->timer -= delta;
            if (self->timer < k[0]) {
                self->timer = k[0];
            }
            switch (self->state) {
            case 0:
                self->setVisibility(0);
                setEnableCollisionStatus__6GroundFb(self, false);
                self->state = 1;
                break;
            case 1:
                if (*self->p16C == 5) {
                    Data158* d = self->data158;
                    float az = d->az, ay = d->ay, ax = d->ax;
                    float bz = d->bz, by = d->by, bx = d->bx;
                    Vec3f a(ax, ay, az);
                    Vec3f b(bx, by, bz);
                    if (a.m_x < b.m_x) {
                        float sum = a.m_y + b.m_y;
                        float z = k[0];
                        float x = self->bounds168->v0 - k[2];
                        float y = k[1] * sum;
                        self->setPosition(z, x, y);
                    } else {
                        float sum = a.m_y + b.m_y;
                        float z = k[0];
                        float x = k[2] + self->bounds168->v3;
                        float y = k[1] * sum;
                        self->setPosition(z, x, y);
                    }
                    self->state = 11;
                    return;
                }
                break;
            case 11:
                if (!((self->flag6C >> 7) & 1)) {
                    self->setVisibility(1);
                    setEnableCollisionStatus__6GroundFb(self, true);
                }
                {
                    Data158* d = self->data158;
                    float az = d->az, ay = d->ay, ax = d->ax;
                    float bz = d->bz, by = d->by, bx = d->bx;
                    Vec3f a(ax, ay, az);
                    Vec3f b(bx, by, bz);
                    if (a.m_x < b.m_x) {
                        float x = self->f15C + r->f7c * delta;
                        float y = k[1] * (a.m_y + b.m_y);
                        self->setPosition2(x, y);
                        if (self->f15C > k[2] + self->bounds168->v3) {
                            *self->p16C = 14;
                            self->state = 0;
                        }
                    } else {
                        float x = self->f15C - r->f7c * delta;
                        float y = k[1] * (a.m_y + b.m_y);
                        self->setPosition2(x, y);
                        if (self->f15C < self->bounds168->v0 - k[2]) {
                            *self->p16C = 14;
                            self->state = 0;
                        }
                    }
                }
                break;
            }
        }
    }
}
