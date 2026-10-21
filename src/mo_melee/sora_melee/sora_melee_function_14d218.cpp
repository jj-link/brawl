#pragma force_active on
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
struct Vec2 { float x, y; };
struct Fighter;
struct Access;

#define S(n) virtual void s##n();
struct Posture {
    S(0) S(1) S(2) S(3)
    virtual Vec3 getPos();
    S(5) S(6)
    virtual Vec3 getPos2();
    S(8) S(9) S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19) S(20) S(21)
    virtual float getScale();
};
struct Ground {
    char pad[8];
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
    S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28) S(29)
    S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    S(40) S(41) S(42) S(43) S(44) S(45) S(46) S(47) S(48) S(49)
    S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59)
    S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69)
    S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81)
    virtual Vec2 getDownPos(int);
    S(83) S(84) S(85) S(86) S(87) S(88) S(89) S(90) S(91) S(92) S(93) S(94)
    S(95) S(96) S(97) S(98) S(99) S(100) S(101)
    virtual void getRange(float*, float*, float*, float*, int);
};
struct Kinetic {
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11) S(12) S(13) S(14) S(15) S(16) S(17) S(18) S(19)
    S(20) S(21) S(22) S(23) S(24) S(25) S(26) S(27) S(28) S(29)
    S(30) S(31) S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    S(40) S(41) S(42) S(43) S(44) S(45) S(46) S(47) S(48) S(49)
    S(50) S(51) S(52) S(53) S(54) S(55) S(56) S(57) S(58) S(59)
    S(60) S(61) S(62) S(63) S(64) S(65) S(66) S(67) S(68) S(69)
    S(70) S(71) S(72) S(73) S(74) S(75) S(76) S(77) S(78) S(79)
    S(80) S(81) S(82) S(83) S(84) S(85) S(86) S(87)
    virtual unsigned int getSituation();
};
struct Work {
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
    S(10) S(11)
    virtual float getFloat(unsigned int);
    S(13) S(14) S(15) S(16)
    virtual unsigned int isFlag(unsigned int);
};
struct Modules {
    char p0[0xc];
    Posture* posture;
    Ground* ground;
    char p1[0x54 - 0x14];
    Kinetic* kinetic;
    char p2[0x64 - 0x58];
    Work* work;
};
struct Access {
    char padding[0xd8];
    Modules* modules;
};

extern "C" Access* getModuleAccesser__23soExternalValueAccesserFP11StageObject(Fighter*);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*, unsigned long, unsigned long);
extern const float lbl_27_rodata_18E8;

static inline Vec2 down(Ground* g) {
    Vec2 r = g->getDownPos(0);
    return r;
}

extern "C" Vec3 fn_27_14D218(Fighter* fighter) {
    Access* acc = getModuleAccesser__23soExternalValueAccesserFP11StageObject(fighter);
    Vec3 pos(acc->modules->posture->getPos());
    if (!acc->modules->work->isFlag(0x1200003c)) {
        float s = acc->modules->posture->getScale();
        float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xc08, 0);
        s = k * s;
        if (acc->modules->kinetic->getSituation() == 1) {
            pos = acc->modules->posture->getPos2();
            pos.y += lbl_27_rodata_18E8 * s;
        } else if (acc->modules->work->isFlag(0x12000038) == 1) {
            float a, b, c, d;
            acc->modules->ground->getRange(&a, &b, &c, &d, 0);
            pos.y += a + s;
        } else {
            Vec2 p = down(acc->modules->ground);
            pos.y = p.y + s;
        }
    }
    pos.y += acc->modules->work->getFloat(0x11000012);
    return pos;
}
