#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_81_rodata_E0;

struct Params { char pad[0x48]; float f48; float f4c; char pad50[0xc]; float f5c; float f60; };
struct Entry { unsigned char st; float f[11]; unsigned char b30; float f34; unsigned char b38; };

#define S(n) virtual void v##n();
class Ground {
public:
    char pad[0x3c];
    S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
    S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28)
    virtual void setVisibility(int);
    S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    S(40) S(41)
    virtual Params* getStageData();
    S(43) S(44) S(45) S(46) S(47) S(48) S(49)
    S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59)
    S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69)
    S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87) S(88) S(89)
    S(90) S(91) S(92) S(93) S(94) S(95) S(96) S(97) S(98) S(99)
    S(100) S(101) S(102) S(103) S(104) S(105) S(106) S(107) S(108) S(109)
    S(110) S(111) S(112) S(113) S(114)
    virtual void a1cc(float);
    virtual void a1d0(float);
    virtual void a1d4(float);
    char pad40[0x2c];
    unsigned char flag : 1;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[8];
    float f160;
    unsigned char b164;
    float f168;
    unsigned char idx;
    char pad16d[7];
    unsigned char* tbl;
    Entry* ents;
    void setEnableCollisionStatus(bool);
};

static inline void resched(Ground* self, Params* p) {
    float x = randf__Fv();
    float hi = p->f60;
    float lo = p->f5c;
    float d = hi - lo;
    self->state = 2;
    self->timer = lo + d * x;
}

extern "C" void fn_81_6A94(Ground* self, float dt) {
    if (self->ents == 0) return;
    Params* p = self->getStageData();
    if (p == 0) return;
    unsigned r = 0;
    float t = self->timer - dt;
    Entry* e = self->ents + self->tbl[self->idx];
    self->timer = t;
    if (t < lbl_81_rodata_E0) self->timer = lbl_81_rodata_E0;
    e->f34 = e->f34 - dt;
    if (e->f34 < lbl_81_rodata_E0) e->f34 = lbl_81_rodata_E0;
    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->setEnableCollisionStatus(false);
        self->f160 = lbl_81_rodata_E0;
        self->f168 = lbl_81_rodata_E0;
        self->b164 = 0;
        self->state = 1;
    case 1:
        if (e->st != 10) resched(self, p);
        break;
    case 2:
        if (!self->flag) {
            self->setVisibility(1);
            self->setEnableCollisionStatus(true);
        }
        switch (e->st) {
        case 4: self->a1cc(dt); break;
        case 5: self->a1d0(dt); if (e->st == 6) self->state = 3; break;
        case 7: self->a1d4(dt); break;
        }
        r = 1;
        break;
    case 3:
        switch (e->st) {
        case 5: case 7: resched(self, p);
        }
        r = 1;
        break;
    case 6:
        if (e->st == 9) {
            self->setVisibility(0);
            self->setEnableCollisionStatus(false);
            e->st = 10;
            e->f[0] = lbl_81_rodata_E0;
            e->f[1] = lbl_81_rodata_E0;
            e->f[2] = lbl_81_rodata_E0;
            e->f[3] = lbl_81_rodata_E0;
            e->f[4] = lbl_81_rodata_E0;
            e->f[5] = lbl_81_rodata_E0;
            e->f[6] = lbl_81_rodata_E0;
            e->f[7] = lbl_81_rodata_E0;
            e->f[8] = lbl_81_rodata_E0;
            e->f[9] = lbl_81_rodata_E0;
            e->f[10] = lbl_81_rodata_E0;
            e->b30 = 0;
            e->f34 = lbl_81_rodata_E0;
            e->b38 = 0;
            self->state = 0;
        }
        break;
    }
    if (r == 1) {
        if (self->b164 == 1) {
            self->f168 = self->f168 + p->f48 * dt;
            if (self->f168 > p->f4c) {
                self->f168 = p->f4c;
                self->b164 = 0;
            }
        } else {
            self->f168 = self->f168 - p->f48 * dt;
            if (self->f168 < lbl_81_rodata_E0) self->f168 = lbl_81_rodata_E0;
        }
    }
}
