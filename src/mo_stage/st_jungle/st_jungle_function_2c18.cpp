#pragma force_active on
namespace StSeUtil {
class SeSeq {
public:
    void playFrame(long, float, float);
    void playFrame(long, float);
};
}

extern "C" const float lbl_51_rodata_48;

#define SLOT(n) virtual void unused##n();

struct Base {
    unsigned char padding[0x3C];
};

struct Self : Base {
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28)
    virtual void setEnabled(int);
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68)
    virtual float getFrame(int);
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115)
    virtual void action(int, int, int, int);

    unsigned char pad_fields40[0x6C - 0x40];
    unsigned char flags;
    unsigned char pad_fields6D[0x150 - 0x6D];
    unsigned char state;
    unsigned char pad_fields151[7];
    unsigned char* data;
    unsigned char pad_fields15C[4];
    float value;
    StSeUtil::SeSeq sequence;
};

extern "C" void fn_51_2C18(Self* self) {
    switch (self->state) {
    case 0:
        self->action(1, 0, 1, 0);
        self->setEnabled(0);
        self->state = 1;
    case 1:
        if (*self->data == 0) {
            self->action(0, 1, 1, 0);
            self->value = lbl_51_rodata_48;
            self->sequence.playFrame(0, self->getFrame(0), lbl_51_rodata_48);
            self->state = 4;
        }
        break;
    case 4:
        if (!((self->flags >> 7) & 1)) {
            self->setEnabled(1);
        }
        self->sequence.playFrame(0, self->getFrame(0));
        if (*self->data == 1) {
            if (self->getFrame(0) < self->value) {
                self->state = 0;
            }
        }
        self->value = self->getFrame(0);
        break;
    }
}
