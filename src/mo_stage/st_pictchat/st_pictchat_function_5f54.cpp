#pragma force_active on
typedef unsigned char u8;

struct Base {
    char pad0[0x3c];
};

struct Obj : Base {
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17)
    SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39) SLOT(40) SLOT(41)
    SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53)
    SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65)

    virtual void setFrame(float, int);
    virtual float getFrame(int);

    SLOT(66) SLOT(67) SLOT(68) SLOT(69) SLOT(70) SLOT(71)
    SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77)
    SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82) SLOT(83)
    SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95)
    SLOT(96) SLOT(97) SLOT(98) SLOT(99) SLOT(100) SLOT(101)
    SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107)
    SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118) SLOT(119)
    SLOT(120) SLOT(121) SLOT(122) SLOT(123) SLOT(124)
#undef SLOT

    virtual void setMotion(int, int, int, float*);

    char pad40[0x150 - 0x40];
    u8 mode;
    char pad151[0x15c - 0x151];
    u8* stage;
    char pad160[4];
    u8* count;
    char pad168[4];
    u8* state;
    char pad170[0x290 - 0x170];
    float endFrame;
    void* pos;
    u8* flag;
    char generator[4];
};

extern "C" {
extern float lbl_73_rodata_C4;
extern void* g_sndSystem;

void setEnableCollisionStatus__6GroundFb(void*, bool);
int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);
int playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_73_5F54(Obj* self) {
    switch (*self->state) {
    case 0:
        self->setMotion(1, 0, 0, &self->endFrame);
        *self->state = 1;
        break;

    case 1:
        if (self->getFrame(0) >= self->endFrame - lbl_73_rodata_C4) {
            setEnableCollisionStatus__6GroundFb(self, false);
            playSE__14snd3DGeneratorF5SndIDiii(
                self->generator, 0x1d20, 0, 0, -1);
            setPos__14snd3DGeneratorFP5Vec3f(self->generator, self->pos);
            *self->state = 2;
        }
        break;

    case 2:
        break;

    case 3:
        if (self->getFrame(0) >= self->endFrame) {
            self->setMotion(0, 0, 1, &self->endFrame);
            self->setFrame(self->endFrame, 0);
            setEnableCollisionStatus__6GroundFb(self, true);
            *self->state = 5;
        }
        break;
    }

    if (*self->stage == 0x1d && *self->state == 5) {
        self->setMotion(2, 0, 1, &self->endFrame);
        setEnableCollisionStatus__6GroundFb(self, false);
        playSE__9sndSystemF5SndIDiiii(
            g_sndSystem, 0x1d1f, 0, 0, 0, -1);
        *self->flag = 0;
        --*self->count;
        self->mode = 4;
    }
}
}
