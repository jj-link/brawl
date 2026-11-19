#pragma force_active on

struct PData {
    float x;
    float y;
    float px;
    float py;
    float vx;
    float vy;
    float rot;
    unsigned char st;
};

struct PParam {
    char pad[0x50];
    float g1;
    float g2;
};

struct GBase { char pad[0x3c]; };

struct Obj { char pad[0x10]; float p10; };

struct Ground : GBase {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVisibility(int);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual PParam* getParam();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70)
    V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80)
    V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90)
    V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100)
    V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110)
    V(111) V(112) V(113)
    virtual void upd();
#undef V

    char pad1[0x2c];
    unsigned char vis : 1;
    unsigned char fl : 7;
    char pad2[0xe3];
    unsigned char state;
    char pad3[3];
    float timer;
    unsigned char b158;
    char pad4[3];
    Obj* o15c;
    char pad5[4];
    int i164;
    float lo;
    float hi;
    PData* d;
};

inline void savePosition(PData* d) { d->px = d->x; d->py = d->y; }

extern "C" {
float fn_80162540(float, float);
extern const float lbl_74_rodata_160[];

inline void updateImpl(Ground* self, float dt) {
    const float* c = lbl_74_rodata_160;
    Ground* s = self;
    if (s->d) {
        PParam* p = s->getParam();
        if (p) {
            s->timer -= dt;
            if (s->timer < c[0])
                s->timer = c[0];
            switch (s->state) {
            case 0:
                s->setVisibility(0);
                s->b158 = 0;
                s->i164 = 0;
                s->lo = c[0];
                s->hi = c[0];
                s->state = 1;
            case 1:
                if (s->d->st == 0) {
                    s->lo = s->d->y;
                    if (s->o15c)
                        s->hi = s->o15c->p10 - c[1];
                    else
                        s->hi = s->lo - c[2];
                    savePosition(s->d);
                    s->state = 2;
            case 2:
                    if (!s->vis)
                        s->setVisibility(1);
                    s->upd();
                    savePosition(s->d);
                    s->d->vy = s->d->vy - p->g1 * dt;
                    s->d->x = s->d->x + s->d->vx * dt;
                    s->d->y = s->d->y + s->d->vy * dt;
                    {
                        float x = s->d->x;
                        float px = s->d->px;
                        float y = s->d->y;
                        float py = s->d->py;
                        s->d->rot = c[3] * fn_80162540(y - py, x - px);
                    }
                    if (s->d->vx < c[0])
                        s->d->rot = s->d->rot + c[4];
                    if (s->d->y <= s->lo) {
                        s->d->vx = s->d->vx * c[5];
                        s->d->vy = c[6];
                        s->d->st = 1;
                        s->state = 3;
                    }
                }
                break;
            case 3:
                savePosition(s->d);
                s->d->vy = s->d->vy - p->g2;
                s->d->x = s->d->x + s->d->vx * dt;
                s->d->y = s->d->y + s->d->vy * dt;
                s->d->rot = s->d->rot + dt;
                if (s->d->y <= s->hi) {
                    s->d->st = 3;
                    s->setVisibility(0);
                    s->state = 0;
                }
                break;
            }
        }
    }
}
void fn_74_B6B4(Ground* self, float dt) { updateImpl(self, dt); }
}

