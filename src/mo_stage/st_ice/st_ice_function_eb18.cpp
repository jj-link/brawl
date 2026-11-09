#pragma force_active on
struct Vec { float x, y, z; };
struct Constants { float x[14]; };
extern "C" const Constants lbl_62_rodata_178;

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;
    Attack(const Constants* d) {
        v.x = d->x[2];
        v.y = d->x[2];
        v.z = d->x[2];
        flags = 0;
    }
};

struct Ground_base { char pad[0x3c]; };
#define F(n) virtual void f##n();
class Ground : public Ground_base {
public:
    F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9)
    F(10) F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19)
    F(20) F(21) F(22) F(23) F(24) F(25) F(26) F(27) F(28) F(29)
    F(30) F(31) F(32) F(33) F(34) F(35) F(36) F(37) F(38) F(39)
    F(40) F(41) F(42) F(43) F(44) F(45) F(46) F(47) F(48) F(49)
    F(50) F(51) F(52) F(53) F(54) F(55) F(56) F(57) F(58) F(59)
    F(60) F(61) F(62) F(63) F(64) F(65) F(66) F(67) F(68) F(69)
    F(70) F(71) F(72) F(73) F(74) F(75) F(76) F(77) F(78) F(79)
    F(80) F(81) F(82) F(83) F(84) F(85) F(86) F(87) F(88) F(89)
    F(90) F(91) F(92) F(93) F(94) F(95) F(96) F(97) F(98) F(99)
    F(100) F(101) F(102) F(103) F(104) F(105) F(106) F(107) F(108)
    virtual void setAttackGimmickDetails(Attack*, int, Vec*, int, int, int, int, float, float, float, float,
        int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    char p[0xc4 - 0x40];
    int id;
    char q[0x14c - 0xc8];
    void* module;
    char r[0x18d - 0x150];
    unsigned char state;
};
#undef F

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_62_EB18(Ground* o) {
    const Constants* d = &lbl_62_rodata_178;
    if (o->state != 1) {
        Attack a(d);
        Vec p;
        p.x = d->x[0];
        p.y = d->x[0];
        p.z = d->x[0];
        o->setAttackGimmickDetails(&a, 20, &p, 0x10e, 0x46, 0, 0x46, d->x[12], d->x[2], d->x[2], d->x[2],
            o->id, 0x3ff, 7, 0, 0xf, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0x3c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
        fn_27_2636F0(o->module, 0, 0, &a);
        o->state = 1;
    }
}
