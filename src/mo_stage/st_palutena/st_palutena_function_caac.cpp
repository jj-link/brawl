#pragma force_active on
extern "C" void update__9grGimmickFf(void*, float);
extern "C" void updateCallback__9grGimmickFUl(void*, unsigned long);

struct Base {
    unsigned char padding[0x3C];
};

struct VirtualBase : Base {
#define SLOT(n) virtual void slot##n();
    SLOT(0)  SLOT(1)  SLOT(2)  SLOT(3)  SLOT(4)
    SLOT(5)  SLOT(6)  SLOT(7)  SLOT(8)  SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34)
    SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44)
    SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54)
    SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64)
    SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74)
    SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84)
    SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
#undef SLOT
    virtual void update(float);
};

struct Object : VirtualBase {
    unsigned char padding[0x88];
    unsigned char active;
};

extern "C" void fn_67_CAAC(Object* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->update(deltaFrame);
        updateCallback__9grGimmickFUl(self, 0);
    }
}
