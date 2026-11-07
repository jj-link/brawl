#pragma force_active on
struct Pad3C {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

class ObjB : public Pad3C {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    virtual int getKind();
};

class ObjC : public Pad3C {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21)
    virtual void f60(int);
    V(23) V(24) V(25) V(26) V(27) V(28) V(29)
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
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137)
    virtual void f230(int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(int id, int b);
    virtual void slot17();
    virtual unsigned int slot18(int id);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void* slot24(int id);
};

struct Inner {
    char pad[0x84];
    Object_vptr_0* mgr;
};

struct Arg {
    char pad[8];
    ObjB* obj;
    char pad2[0xd8 - 0xc];
    Inner* inner;
};

extern "C" {
extern unsigned char lbl_27_bss_466C[0xC];
extern char lbl_27_data_31AD8[];
extern char lbl_27_data_C938[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DF00(void*, int);

void fn_27_18C9B0(void* unused, Arg* arg) {
    Object_vptr_0* mgr;
    int id = fn_27_14DF00(lbl_27_bss_466C, arg->obj->getKind());
    if (id != -1) {
        mgr = arg->inner->mgr;
        if (mgr->slot18(id) == 1) {
            ObjC* c = (ObjC*)__dynamic_cast(mgr->slot24(id), 0, lbl_27_data_31AD8, lbl_27_data_C938, 0);
            mgr->slot16(id, 0);
            c->f230(0);
            if (c) {
                c->f60(1);
            }
        }
    }
}
}
