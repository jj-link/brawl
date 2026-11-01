#pragma force_active on

struct Accesser;

#define V(n) virtual void unused##n();

class Query {
public:
    V(0) V(1) V(2)
    virtual void set(int, Accesser*);
    V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11)
    V(12) V(13) V(14) V(15)
    virtual int test();
};

class Status {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10)
    virtual void change();
    V(12) V(13) V(14) V(15) V(16) V(17) V(18)
    virtual void reset();
};

class Action {
public:
    char pad[8];
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    virtual int getFirst();
    virtual int getSecond();
    V(10) V(11) V(12)
    virtual unsigned int check();
};

class Motion {
public:
    V(0) V(1) V(2)
    virtual void set(int, int);
    V(4) V(5)
    virtual void update(int);
    virtual void finish(int);
};

class FighterBase {
public:
    char pad[0x3C];
};

class Fighter : public FighterBase {
public:
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
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134)
    virtual int finishAction();
    virtual int changeAction();

    char pad0[0x20];
    Accesser* accesser;
    char pad1[0x40];
    unsigned char flag;
};

#undef V

struct Modules {
    char pad0[0x0C];
    Status* status;
    char pad1[0x08];
    Motion* motion;
    char pad2[0x54];
    Query* query;
    char pad3[0x48];
    Action* action;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" int fn_27_3681DC(Fighter* self, int arg) {
    if (self->accesser->modules->query->test() != 0) {
        goto query_fail;
    }

    if (arg & 3) {
        Accesser* accesser = self->accesser;
        Query* query = accesser->modules->query;
        query->set(1, accesser);
        return 1;
    }

    if (arg & 0x10) {
        goto handled_fail;
    }

    if (arg & 4) {
        if ((((unsigned int)self->flag >> 7) & 1U) == 1U) {
            return self->changeAction();
        }
        Accesser* accesser = self->accesser;
        Query* query = accesser->modules->query;
        query->set(1, accesser);
        return 1;
    }

    if (arg & 8) {
        if (self->accesser->modules->action->check() == 1) {
            self->accesser->modules->status->change();
            self->accesser->modules->status->reset();

            int result = self->accesser->modules->action->getSecond();
            self->accesser->modules->motion->set(result, 1);
            self->accesser->modules->motion->update(result);

            Motion* motion = self->accesser->modules->motion;
            int value = self->accesser->modules->action->getFirst();
            motion->finish(value);

            return self->finishAction();
        }
    }

    goto handled_fail;

query_fail:
    return 0;

handled_fail:
    return 0;
}
