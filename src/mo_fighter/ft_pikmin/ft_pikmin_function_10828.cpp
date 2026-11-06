#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_113_243CC(void*, void*);
void fn_113_2CF34(int, unsigned int, int, int, float, int, int);
int fn_27_111364(void*);
extern const char lbl_113_data_61C[], lbl_113_data_2950[];
}

#define V(n) virtual void slot##n();

struct Fighter {
    char pad[0x3c];
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
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139)
    V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147) V(148) V(149)
    V(150) V(151) V(152) V(153) V(154) V(155) V(156) V(157) V(158) V(159)
    V(160) V(161) V(162) V(163) V(164) V(165) V(166) V(167) V(168) V(169)
    V(170) V(171) V(172) V(173) V(174) V(175) V(176) V(177) V(178) V(179)
    V(180) V(181) V(182) V(183) V(184)
    virtual void* call185();
};

#undef V

struct Module {
    char pad[8];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void* m4();
};

struct ValueObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
};

struct Obj30 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct Obj31 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float s9();
};

struct ObjectData {
    char pad[0x28];
    unsigned int taskId;
};

struct Modules {
    Module* m0;
    char pad4[8];
    Obj31* m0c;
    char pad10[4];
    Obj30* m14;
};

struct Accesser {
    char pad0[8];
    ObjectData* objectData;
    char pad0c[0xCC];
    Modules* modules;
};

extern "C" int fn_113_10828(int arg0, Accesser* accesser) {
    int owner;
    Obj31* r31;
    Obj30* r30;
    int r29;
    Module* r28;
    unsigned int taskId;
    Fighter* fighter;
    fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->objectData, 0x3C, lbl_113_data_61C, lbl_113_data_2950, 1));
    Modules* modules = accesser->modules;
    r30 = modules->m14;
    r31 = modules->m0c;
    r28 = modules->m0;
    taskId = accesser->objectData->taskId;
    r29 = fn_113_243CC((char*)fighter + 0x1FD08, accesser->objectData);
    int r30_2 = r30->s3() == 0;
    float f31 = r31->s9();
    owner = fn_27_111364(fighter->call185());
    ValueObj* vo = (ValueObj*)r28->m4();
    int v = vo->v15();
    fn_113_2CF34(arg0, taskId, v, owner, f31, r30_2, r29);
    return 1;
}
