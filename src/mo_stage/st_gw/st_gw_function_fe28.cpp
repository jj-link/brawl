#pragma force_active on

struct Vec3f {
    float x, y, z;
};

extern "C" char lbl_63_data_43A0[];
extern "C" char lbl_63_data_43B4[];
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);

struct Base {
    unsigned char pad000[0x3C];
};

#define D(n) virtual void m##n();

struct Obj : Base {
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)
    D(48)
    virtual void getNode(Vec3f*, int, const char*);
    D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57)
    D(58) D(59) D(60) D(61) D(62) D(63) D(64) D(65)
    D(66) D(67) D(68) D(69) D(70) D(71) D(72) D(73)
    D(74) D(75) D(76) D(77) D(78) D(79) D(80) D(81)
    D(82) D(83) D(84) D(85) D(86) D(87) D(88) D(89)
    D(90) D(91) D(92) D(93) D(94) D(95) D(96) D(97)
    D(98) D(99) D(100) D(101) D(102) D(103) D(104) D(105)
    D(106) D(107) D(108) D(109) D(110) D(111) D(112) D(113)
    D(114) D(115) D(116) D(117) D(118)
    virtual void update();

    unsigned char pad_0x40[0x14C - 0x40];
    int field_0x14C;
    unsigned char pad_0x150[0x17E - 0x150];
    unsigned char state;
    unsigned char pad_0x17F;
    unsigned char active;
};

#undef D

extern "C" void fn_63_FE28(Obj* self) {
    Vec3f pos;
    if (self->active == 1) {
        switch (self->state) {
        case 4:
            self->getNode(&pos, 0, lbl_63_data_43A0);
            break;
        case 5:
            self->getNode(&pos, 0, lbl_63_data_43B4);
            break;
        }
        setPos__9grGimmickFP5Vec3f(self, &pos);
        return;
    }
    self->update();
    if (self->field_0x14C != 0) {
        self->active = 1;
    }
}
