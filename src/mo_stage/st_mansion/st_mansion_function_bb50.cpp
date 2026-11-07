#pragma force_active on
struct Vec3f { float x, y, z; };

struct GroundBase { char pad[0x3C]; };

struct Param {
    char pad[0x28];
    float f28, f2c, f30, f34, f38;
};

class Ground : public GroundBase {
public:
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVisibility(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual Param* getParam();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47)
    virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
    V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65)
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    V(108) V(109) V(110) V(111) V(112)
    virtual void f1cc(float);
    virtual void f1d0(float);
    virtual void f1d4(float);
    V(116)
    virtual void setMotion(int, int, int, float*);
#undef V

    char pad40[0x24];
    float f64;
    char pad68[4];
    unsigned char b6C;
    char pad6D[0x57];
    int nodeC4;
    char padC8[0x88];
    unsigned char state;
    char pad151[3];
    float t154;
    unsigned char b158;
    unsigned char b159;
    char pad15A[2];
    float f15C;
    float f160;
    float t164;
    Vec3f* ptr168;
    Vec3f pos;
    char pad178[8];
    unsigned char b180;
    char pad181[3];
    float f184, f188, f18C;
    unsigned char b190;
    unsigned char b191;
    char pad192[2];
    float t194;
    char pad198[4];
    float f19C;
    float f1A0;
};

extern "C" {
float randf__Fv();
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern const float lbl_47_rodata_110;
extern const float lbl_47_rodata_114;

void fn_47_BB50(Ground* self, float delta) {
    Param* p = self->getParam();
    if (p == 0) return;
    self->t154 -= delta;
    if (self->t154 < lbl_47_rodata_110) self->t154 = lbl_47_rodata_110;
    self->t164 -= delta;
    if (self->t164 < lbl_47_rodata_110) self->t164 = lbl_47_rodata_110;
    self->t194 -= delta;
    if (self->t194 < lbl_47_rodata_110) self->t194 = lbl_47_rodata_110;

    switch (self->state) {
    case 0:
        self->setMotion(1, 0, 1, 0);
        self->setVisibility(0);
        setEnableCollisionStatus__6GroundFb(self, false);
        if (self->b190 == 1) {
            self->t154 = p->f28;
        } else {
            self->t154 = p->f2c + (p->f30 - p->f2c) * randf__Fv();
        }
        self->b158 = 0;
        self->b159 = 0;
        self->f15C = lbl_47_rodata_110;
        self->f160 = lbl_47_rodata_110;
        self->t164 = lbl_47_rodata_110;
        self->f184 = lbl_47_rodata_110;
        self->f188 = lbl_47_rodata_110;
        self->f18C = lbl_47_rodata_110;
        self->b191 = 0;
        self->state = 2;
        break;
    case 2:
        if (lbl_47_rodata_110 == self->t154) {
            if (self->b190 == 1) {
                self->getNodePosition(&self->pos, 0, self->nodeC4);
                Vec3f* q = self->ptr168;
                q->x = self->pos.x;
                q->y = self->pos.y;
                q->z = self->pos.z;
                self->b190 = 0;
            }
            self->setMotion(0, 1, 1, &self->f1A0);
            self->setMotionFrame(self->f1A0, 0);
            self->f19C = self->f1A0;
            if (self->f64 > lbl_47_rodata_110)
                self->f64 = self->f64 * lbl_47_rodata_114;
            float r = randf__Fv();
            float d = p->f38 - p->f34;
            float v = p->f34 + d * r;
            self->state = 7;
            self->t154 = v;
        }
        break;
    case 7:
        if (lbl_47_rodata_110 == self->t154) {
            self->setMotion(0, 0, 1, &self->f1A0);
            if (self->f64 < lbl_47_rodata_110)
                self->f64 = self->f64 * lbl_47_rodata_114;
            self->state = 8;
            break;
        }
        switch (self->b180) {
        case 4: self->f1cc(delta); break;
        case 5: self->f1d0(delta); break;
        }
        self->f1d4(delta);
        if (self->getMotionFrame(0) > self->f19C) {
            self->setMotion(1, 0, 1, 0);
        } else {
            if (!((self->b6C >> 7) & 1)) {
                self->setVisibility(1);
                setEnableCollisionStatus__6GroundFb(self, true);
            }
            self->f19C = self->getMotionFrame(0);
        }
        break;
    case 8:
        if (self->getMotionFrame(0) >= self->f1A0)
            self->state = 0;
        break;
    }
}
}
