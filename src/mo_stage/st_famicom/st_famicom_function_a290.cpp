#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator {
    char pad[8];
};

struct Elem {
    char pad[0x28];
};

extern "C" void update__9grGimmickFf(void*, float);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

struct Base {
    unsigned char pad[0x3C];
};

#define VIRTUAL_SLOT(n) virtual void slot##n(float);

class Object : public Base {
public:
    VIRTUAL_SLOT(0)   VIRTUAL_SLOT(1)   VIRTUAL_SLOT(2)   VIRTUAL_SLOT(3)
    VIRTUAL_SLOT(4)   VIRTUAL_SLOT(5)   VIRTUAL_SLOT(6)   VIRTUAL_SLOT(7)
    VIRTUAL_SLOT(8)   VIRTUAL_SLOT(9)   VIRTUAL_SLOT(10)  VIRTUAL_SLOT(11)
    VIRTUAL_SLOT(12)  VIRTUAL_SLOT(13)  VIRTUAL_SLOT(14)  VIRTUAL_SLOT(15)
    VIRTUAL_SLOT(16)  VIRTUAL_SLOT(17)  VIRTUAL_SLOT(18)  VIRTUAL_SLOT(19)
    VIRTUAL_SLOT(20)  VIRTUAL_SLOT(21)  VIRTUAL_SLOT(22)  VIRTUAL_SLOT(23)
    VIRTUAL_SLOT(24)  VIRTUAL_SLOT(25)  VIRTUAL_SLOT(26)  VIRTUAL_SLOT(27)
    VIRTUAL_SLOT(28)  VIRTUAL_SLOT(29)  VIRTUAL_SLOT(30)  VIRTUAL_SLOT(31)
    VIRTUAL_SLOT(32)  VIRTUAL_SLOT(33)  VIRTUAL_SLOT(34)  VIRTUAL_SLOT(35)
    VIRTUAL_SLOT(36)  VIRTUAL_SLOT(37)  VIRTUAL_SLOT(38)  VIRTUAL_SLOT(39)
    VIRTUAL_SLOT(40)  VIRTUAL_SLOT(41)  VIRTUAL_SLOT(42)  VIRTUAL_SLOT(43)
    VIRTUAL_SLOT(44)  VIRTUAL_SLOT(45)  VIRTUAL_SLOT(46)  VIRTUAL_SLOT(47)
    VIRTUAL_SLOT(48)  VIRTUAL_SLOT(49)  VIRTUAL_SLOT(50)  VIRTUAL_SLOT(51)
    VIRTUAL_SLOT(52)  VIRTUAL_SLOT(53)  VIRTUAL_SLOT(54)  VIRTUAL_SLOT(55)
    VIRTUAL_SLOT(56)  VIRTUAL_SLOT(57)  VIRTUAL_SLOT(58)  VIRTUAL_SLOT(59)
    VIRTUAL_SLOT(60)  VIRTUAL_SLOT(61)  VIRTUAL_SLOT(62)  VIRTUAL_SLOT(63)
    VIRTUAL_SLOT(64)  VIRTUAL_SLOT(65)  VIRTUAL_SLOT(66)  VIRTUAL_SLOT(67)
    VIRTUAL_SLOT(68)  VIRTUAL_SLOT(69)  VIRTUAL_SLOT(70)  VIRTUAL_SLOT(71)
    VIRTUAL_SLOT(72)  VIRTUAL_SLOT(73)  VIRTUAL_SLOT(74)  VIRTUAL_SLOT(75)
    VIRTUAL_SLOT(76)  VIRTUAL_SLOT(77)  VIRTUAL_SLOT(78)  VIRTUAL_SLOT(79)
    VIRTUAL_SLOT(80)  VIRTUAL_SLOT(81)  VIRTUAL_SLOT(82)  VIRTUAL_SLOT(83)
    VIRTUAL_SLOT(84)  VIRTUAL_SLOT(85)  VIRTUAL_SLOT(86)  VIRTUAL_SLOT(87)
    VIRTUAL_SLOT(88)  VIRTUAL_SLOT(89)  VIRTUAL_SLOT(90)  VIRTUAL_SLOT(91)
    VIRTUAL_SLOT(92)  VIRTUAL_SLOT(93)  VIRTUAL_SLOT(94)  VIRTUAL_SLOT(95)
    VIRTUAL_SLOT(96)  VIRTUAL_SLOT(97)  VIRTUAL_SLOT(98)  VIRTUAL_SLOT(99)
    VIRTUAL_SLOT(100) VIRTUAL_SLOT(101) VIRTUAL_SLOT(102) VIRTUAL_SLOT(103)
    VIRTUAL_SLOT(104) VIRTUAL_SLOT(105) VIRTUAL_SLOT(106) VIRTUAL_SLOT(107)
    VIRTUAL_SLOT(108) VIRTUAL_SLOT(109) VIRTUAL_SLOT(110) VIRTUAL_SLOT(111)

    virtual void a(float);
    virtual void b(float);
    virtual void c(float);
    virtual void d(float);

    unsigned char pad1[0x88];
    unsigned char active;
    unsigned char pad2[0xAC];
    unsigned char index;
    unsigned char pad3[2];
    Elem* array;
    unsigned char pad4[0x24];
    snd3DGenerator sndGen;
};

#undef VIRTUAL_SLOT

extern "C" void fn_68_A290(Object* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (self->active) {
        self->a(deltaFrame);
        self->b(deltaFrame);
        self->c(deltaFrame);
        self->d(deltaFrame);
        setPos__14snd3DGeneratorFP5Vec3f(&self->sndGen, (Vec3f*)&self->array[self->index]);
    }
}
