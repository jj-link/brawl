#pragma force_active on
struct Base {
    unsigned char padding[0x3c];
};

struct Object : Base {
#define UNUSED(n) virtual void unused##n();
    UNUSED(0)   UNUSED(1)   UNUSED(2)   UNUSED(3)
    UNUSED(4)   UNUSED(5)   UNUSED(6)   UNUSED(7)
    UNUSED(8)   UNUSED(9)   UNUSED(10)  UNUSED(11)
    UNUSED(12)  UNUSED(13)  UNUSED(14)  UNUSED(15)
    UNUSED(16)  UNUSED(17)  UNUSED(18)  UNUSED(19)
    UNUSED(20)  UNUSED(21)  UNUSED(22)  UNUSED(23)
    UNUSED(24)  UNUSED(25)  UNUSED(26)  UNUSED(27)
    UNUSED(28)  UNUSED(29)  UNUSED(30)  UNUSED(31)
    UNUSED(32)  UNUSED(33)  UNUSED(34)  UNUSED(35)
    UNUSED(36)  UNUSED(37)  UNUSED(38)  UNUSED(39)
    UNUSED(40)  UNUSED(41)  UNUSED(42)  UNUSED(43)
    UNUSED(44)  UNUSED(45)  UNUSED(46)  UNUSED(47)
    UNUSED(48)  UNUSED(49)  UNUSED(50)  UNUSED(51)
    UNUSED(52)  UNUSED(53)  UNUSED(54)  UNUSED(55)
    UNUSED(56)  UNUSED(57)  UNUSED(58)  UNUSED(59)
    UNUSED(60)  UNUSED(61)  UNUSED(62)  UNUSED(63)
    UNUSED(64)  UNUSED(65)  UNUSED(66)  UNUSED(67)
    UNUSED(68)  UNUSED(69)  UNUSED(70)  UNUSED(71)
    UNUSED(72)  UNUSED(73)  UNUSED(74)  UNUSED(75)
    UNUSED(76)  UNUSED(77)  UNUSED(78)  UNUSED(79)
    UNUSED(80)  UNUSED(81)  UNUSED(82)  UNUSED(83)
    UNUSED(84)  UNUSED(85)  UNUSED(86)  UNUSED(87)
    UNUSED(88)  UNUSED(89)  UNUSED(90)  UNUSED(91)
    UNUSED(92)  UNUSED(93)  UNUSED(94)  UNUSED(95)
    UNUSED(96)  UNUSED(97)  UNUSED(98)  UNUSED(99)
    UNUSED(100) UNUSED(101) UNUSED(102) UNUSED(103)
    UNUSED(104) UNUSED(105) UNUSED(106) UNUSED(107)
    UNUSED(108) UNUSED(109) UNUSED(110) UNUSED(111)
    UNUSED(112) UNUSED(113) UNUSED(114) UNUSED(115)
    UNUSED(116) UNUSED(117) UNUSED(118) UNUSED(119)
    UNUSED(120) UNUSED(121) UNUSED(122) UNUSED(123)
    UNUSED(124) UNUSED(125)
#undef UNUSED

    virtual void call(int, int, int, void*);

    unsigned char padding1[0x110];
    unsigned char state;
    unsigned char padding2[0x47];
    unsigned char data[8];
    unsigned char flag;
};

extern "C" void fn_51_E204(Object* self) {
    switch (self->state) {
    case 1:
        if (self->flag == 0) {
            self->call(0, 0, 0, self->data);
        } else {
            self->call(1, 0, 0, self->data);
        }
        self->state = 4;
        break;
    }
}
