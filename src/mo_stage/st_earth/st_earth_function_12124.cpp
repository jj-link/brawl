#pragma force_active on
struct Ground_base {
    unsigned char pad[0x3C];
};

class Ground : public Ground_base {
public:
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113)
    virtual void fn_66_12418(int, int, float*);
#undef V

    unsigned char pad40[8];
    void** anim48;
    unsigned char pad50[0x104];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    float target;
    unsigned char flag;
};

extern "C" {
extern const float lbl_66_rodata_270;
void update__9grGimmickFf(Ground* self, float delta);
void setLoop__16gfModelAnimationFd(void* anim, int loop);
float getFrame__16gfModelAnimationFd(void* anim);
}

extern "C" void fn_66_12124(Ground* self, float delta) {
    update__9grGimmickFf(self, delta);
    self->timer -= delta;
    if (self->timer < lbl_66_rodata_270)
        self->timer = lbl_66_rodata_270;

    switch (self->state) {
    case 0:
        self->state = 1;
        break;
    case 10:
        self->fn_66_12418(0, 0, &self->timer);
        self->flag = 0;
        self->target = lbl_66_rodata_270;
        self->state = 11;
        break;
    case 11:
        if (lbl_66_rodata_270 == self->timer) {
            if (self->flag == 1) {
                self->target = lbl_66_rodata_270;
                self->state = 13;
            } else {
                self->fn_66_12418(1, 1, &self->timer);
                self->state = 12;
                self->target = self->timer;
            }
        }
        break;
    case 12:
        if (self->flag == 1) {
            void* anim = *self->anim48;
            if (anim != 0) {
                setLoop__16gfModelAnimationFd(anim, 0);
                if (self->target == getFrame__16gfModelAnimationFd(anim)) {
                    self->state = 13;
                }
            }
        }
        break;
    case 13:
        self->fn_66_12418(2, 0, &self->timer);
        self->flag = 0;
        self->target = lbl_66_rodata_270;
        self->state = 14;
        break;
    case 14:
        if (lbl_66_rodata_270 == self->timer) {
            if (self->flag == 1) {
                self->target = lbl_66_rodata_270;
                self->state = 10;
            } else {
                self->fn_66_12418(3, 1, &self->timer);
                self->state = 15;
                self->target = self->timer;
            }
        }
        break;
    case 15:
        if (self->flag == 1) {
            void* anim = *self->anim48;
            if (anim != 0) {
                setLoop__16gfModelAnimationFd(anim, 0);
                if (self->target == getFrame__16gfModelAnimationFd(anim)) {
                    self->state = 10;
                }
            }
        }
        break;
    }
}
