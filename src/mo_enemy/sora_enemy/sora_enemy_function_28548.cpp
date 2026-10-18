#include <types.h>
#pragma force_active on

#define VD(n) virtual void vf##n() = 0;

struct VtBase {
    VD(0) VD(1) VD(2) VD(3) VD(4) VD(5) VD(6) VD(7) VD(8) VD(9)
    VD(10) VD(11) VD(12) VD(13) VD(14) VD(15) VD(16) VD(17) VD(18) VD(19)
    VD(20) VD(21) VD(22) VD(23) VD(24) VD(25) VD(26) VD(27) VD(28) VD(29)
    VD(30) VD(31) VD(32) VD(33) VD(34) VD(35) VD(36) VD(37) VD(38) VD(39)
    VD(40) VD(41) VD(42) VD(43) VD(44) VD(45) VD(46) VD(47) VD(48) VD(49)
    VD(50) VD(51) VD(52) VD(53) VD(54) VD(55) VD(56) VD(57) VD(58) VD(59)
    VD(60) VD(61) VD(62) VD(63) VD(64) VD(65) VD(66) VD(67) VD(68) VD(69)
    VD(70) VD(71) VD(72) VD(73) VD(74) VD(75) VD(76) VD(77) VD(78) VD(79)
    VD(80) VD(81) VD(82) VD(83) VD(84) VD(85)
    virtual void target(u32 hw, u32 a, u32 b) = 0;
};

extern "C" {
void fn_41_28548(void* self, u32 a, u32 b) {
    ((VtBase*)self)->target(*(u16*)((u8*)self + 0x3C), a, b);
}
}
