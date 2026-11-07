#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
void fn_111_10AD4(void*, int, int, int, int);
extern const char lbl_111_data_14C8[], lbl_111_data_1D44[];
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
class Object_vptr_0 {
public:
 virtual void fn_111_5F38();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual int slot8();
 virtual void slot9();
 virtual int slot10();
};
struct Module {
 char pad[8];
 virtual void m0();
 virtual void m1();
 virtual void m2();
 virtual void m3();
 virtual Object_vptr_0* m4();
};
#undef V
extern "C" int fn_111_7D74(void* self, char* accesser) {
 int valA;
 int owner;
 int taskId;
 Module* mod;
 Fighter* fighter = (Fighter*)__dynamic_cast(*(void**)(accesser + 8), 0x3c, lbl_111_data_14C8, lbl_111_data_1D44, 1);
 char* modules = *(char**)(accesser + 0xd8);
 mod = *(Module**)modules;
 taskId = *(int*)(*(char**)(accesser + 8) + 0x28);
 owner = fn_27_111364(fighter->call185());
 valA = mod->m4()->slot8();
 int valB = mod->m4()->slot10();
 fn_111_10AD4(self, taskId, valB, valA, owner);
 return 1;
}