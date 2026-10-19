#include <types.h>
#pragma force_active on

#define VF(n) virtual s32 v##n(s32) = 0;
#define R0 VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
#define R1 VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
#define R2 VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29)
#define R3 VF(30) VF(31) VF(32) VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39)
#define R4 VF(40) VF(41) VF(42) VF(43) VF(44) VF(45) VF(46) VF(47) VF(48) VF(49)
#define R5 VF(50) VF(51) VF(52) VF(53) VF(54) VF(55) VF(56) VF(57) VF(58) VF(59)
#define R6 VF(60) VF(61) VF(62) VF(63) VF(64) VF(65) VF(66) VF(67) VF(68) VF(69)
#define R7 VF(70) VF(71) VF(72) VF(73) VF(74) VF(75) VF(76) VF(77) VF(78) VF(79)
#define R8 VF(80) VF(81) VF(82) VF(83) VF(84) VF(85) VF(86) VF(87) VF(88) VF(89)

class Base {
public:
    R0 R1 R2 R3 R4 R5 R6 R7 R8
};

extern "C" s32 fn_27_18A00C(s32 p1, void* p2, s32 p3) {
    if (p3 != 0x42) {
        Base* obj = *(Base**)((u8*)p2 + 0xd8);
        Base* sub = *(Base**)((u8*)obj + 0x40);
        return sub->v17(0);
    }
    Base* obj = *(Base**)((u8*)p2 + 0xd8);
    Base* sub = *(Base**)((u8*)obj + 0x54);
    return sub->v87(1);
}
