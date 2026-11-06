#pragma force_active on
struct stTriggerMng;
struct stTriggerData;

struct C { char pad[0x1c]; unsigned short v; };

class B {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(float);
    char pad[0x28];
    C* c;
};

struct Q { char pad[0xc]; B* b; };

struct YBase { char pad[0x3c]; };

class Yakumono : public YBase {
public:
#define S(n) virtual void s##n();
    S(0)S(1)S(2)S(3)S(4)S(5)S(6)S(7)S(8)S(9)
    S(10)S(11)S(12)S(13)S(14)S(15)S(16)S(17)S(18)S(19)
    S(20)S(21)S(22)S(23)S(24)S(25)S(26)S(27)S(28)S(29)
    S(30)S(31)S(32)S(33)S(34)S(35)S(36)S(37)S(38)S(39)
    S(40)S(41)S(42)S(43)S(44)S(45)S(46)S(47)S(48)S(49)
    S(50)S(51)S(52)S(53)S(54)S(55)S(56)S(57)S(58)S(59)
    virtual void setValid(unsigned long);
    S(61)S(62)S(63)S(64)S(65)S(66)S(67)S(68)S(69)S(70)
    S(71)S(72)S(73)S(74)S(75)S(76)S(77)S(78)S(79)S(80)
    S(81)
    virtual void changeNodeAnim(unsigned long, unsigned long);
    char pad40[8];
    Q** unk48;
    char pad4c[0x108];
    unsigned char* data;
};

extern "C" {
extern stTriggerMng* g_stTriggerMng;
bool getTriggerFlag__12stTriggerMngFP13stTriggerDatab(stTriggerMng*, stTriggerData*, bool);

void fn_40_336C0(Yakumono* self) {
    if (!getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, (stTriggerData*)(self->data + 0x1d8), true)) {
        if (self->data[0x1da] & 1) self->setValid(0);
    } else {
        if (!(self->data[0x1da] & 1)) self->setValid(0);
    }
    if (getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, (stTriggerData*)(self->data + 0x1dc), false) == 1U) {
        self->changeNodeAnim(0, 0);
        Q* q = *self->unk48;
        B* b = q->b;
        b->s5((float)b->c->v);
    }
}
}
