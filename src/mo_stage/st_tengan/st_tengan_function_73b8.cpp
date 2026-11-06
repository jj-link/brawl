#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct Cfg {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
};

struct GroundBase {
    unsigned char pad[0x3C];
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
    virtual void fn_60_72EC();
    virtual void fn_60_7344();
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
    virtual void fn_60_6588();
    virtual void startup();
    virtual void setNode();
    virtual void fn_60_1A80();
    virtual Cfg* fn_60_6580();

    unsigned char pad40[0x190];
    unsigned char state;
    unsigned char pad1D1[3];
    float timer;
    Cfg* cfg;
    float f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    bool flag1f0;
    unsigned char flag1f1;
};

extern "C" {
float randf__Fv();
extern const float lbl_60_rodata_108[];
}

extern "C" void fn_60_73B8(Ground* self, float delta) {
    const float* c = lbl_60_rodata_108;
    if (self->cfg == 0) return;
    Cfg* v = self->fn_60_6580();
    if (v == 0) return;
    if (self->cfg->f4 == self->cfg->f10) return;

    self->timer -= delta;
    if (self->timer < c[0]) self->timer = c[0];

    switch (self->state) {
    case 0: {
        Cfg* p = self->cfg;
        self->f1dc = p->fc;
        self->f1e0 = p->f10;
        self->f1e4 = p->f14;
        self->f1e0 = self->f1e0 + (p->f4 - p->f10) * randf__Fv();
        if (randf__Fv() < c[1]) {
            self->flag1f0 = 1;
        } else {
            self->flag1f0 = 0;
        }
        self->state = 1;
    }
        /* fallthrough */
    case 1:
        if (c[0] == self->timer) {
            self->f1ec = c[0];
            self->flag1f1 = 0;
            self->state = 2;
        }
        break;
    case 2: {
        unsigned int r29 = 0;
        unsigned int r28 = 0;
        self->f1ec = self->f1ec + v->f0;
        if (self->f1ec > v->f4) self->f1ec = v->f4;
        if (self->flag1f1 == 0) {
            if (self->f1ec == v->f4) {
                if (randf__Fv() < v->f14) r29 = 1;
                self->flag1f1 = 1;
            }
        }
        if (r29 == 1) {
            r28 = 1;
        } else if (self->flag1f0 == 1) {
            self->f1e0 = self->f1e0 + self->f1ec * delta;
            if (self->f1e0 >= self->cfg->f4) r28 = 1;
        } else {
            self->f1e0 = self->f1e0 - self->f1ec * delta;
            if (self->f1e0 <= self->cfg->f10) r28 = 1;
        }
        if (r28 == 1) {
            self->state = 3;
            self->f1e8 = self->f1e0;
        }
        break;
    }
    case 3: {
        self->f1ec = self->f1ec - v->f0;
        if (nw4r::math::FAbs(self->f1ec) > v->f4) {
            self->f1ec = c[2] * v->f4;
        }
        if (self->flag1f0 == 1) {
            self->f1e0 = self->f1e0 + self->f1ec * delta;
        } else {
            self->f1e0 = self->f1e0 - self->f1ec * delta;
        }
        if ((self->flag1f0 == 1 && self->f1e8 > self->f1e0) ||
            (self->flag1f0 == 0 && self->f1e8 < self->f1e0)) {
            if (randf__Fv() < v->f8) {
                self->timer = v->fc + (v->f10 - v->fc) * randf__Fv();
                self->state = 1;
            } else {
                self->state = 2;
            }
            self->flag1f0 = (self->flag1f0 == 0);
        }
        self->f1e8 = self->f1e0;
        break;
    }
    }
}
