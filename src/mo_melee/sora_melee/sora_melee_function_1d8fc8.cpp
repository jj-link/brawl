#pragma force_active on

struct Accesser;

#define V(n) virtual void unused##n();

struct Query {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33)
    virtual void reset(int, Accesser*);
};

struct Work {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16)
    virtual int test(int, Accesser*);
};

struct Action {
    char pad[8];
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8)
    virtual void reset();
};

struct Modules {
    char pad0[4];
    Action* action;
    char pad8[0x64 - 8];
    Work* work;
    char pad68[8];
    Query* query;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad0[0x3C];
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
    V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40)
    virtual unsigned int kind();
    V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57)
    V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65)
    V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73)
    V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81)
    V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105)
    V(106) V(107) V(108) V(109) V(110) V(111) V(112) V(113)
    V(114) V(115) V(116) V(117) V(118) V(119) V(120) V(121)
    V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133)
    virtual void reset();
    char pad40[0x20];
    Accesser* accesser;
    char pad64[0xB8 - 0x64];
    int index;
};

#undef V

extern "C" {
void fn_27_8D1B0(void*, int, Accesser*);
unsigned int fn_27_1DCBAC(int);
void fn_27_4254(Object*, int);
extern int lbl_27_bss_5088;
}

extern "C" void fn_27_1D8FC8(Object* self, int arg) {
    fn_27_8D1B0(reinterpret_cast<char*>(self) + 0x88, -1, self->accesser);
    self->reset();
    Accesser* accesser = self->accesser;
    accesser->modules->query->reset(-1, accesser);
    accesser = self->accesser;
    if (accesser->modules->work->test(0x12000001, accesser) == 0) {
        self->accesser->modules->action->reset();
    }
    if (self->kind() == 1U && fn_27_1DCBAC(self->index) == 1U) {
        --lbl_27_bss_5088;
    }
    fn_27_4254(self, arg);
}
