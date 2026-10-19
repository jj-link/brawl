#pragma force_active on
extern "C" {

typedef unsigned int u32;

extern void* setNode__9grGimmickFv(void* self);
extern void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 flag, const char* name);

struct GBase {
    char pad[0x3c];
};

#define DUMMY(n) virtual void v##n();
struct GImmick : GBase {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4) DUMMY(5) DUMMY(6) DUMMY(7)
    DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15)
    DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19) DUMMY(20) DUMMY(21) DUMMY(22) DUMMY(23)
    DUMMY(24) DUMMY(25) DUMMY(26) DUMMY(27) DUMMY(28) DUMMY(29) DUMMY(30) DUMMY(31)
    DUMMY(32) DUMMY(33) DUMMY(34) DUMMY(35) DUMMY(36) DUMMY(37) DUMMY(38) DUMMY(39)
    DUMMY(40) DUMMY(41) DUMMY(42) DUMMY(43) DUMMY(44) DUMMY(45) DUMMY(46) DUMMY(47)
    DUMMY(48) DUMMY(49) DUMMY(50) DUMMY(51) DUMMY(52) DUMMY(53) DUMMY(54) DUMMY(55)
    DUMMY(56) DUMMY(57) DUMMY(58) DUMMY(59) DUMMY(60) DUMMY(61) DUMMY(62) DUMMY(63)
    DUMMY(64) DUMMY(65) DUMMY(66) DUMMY(67) DUMMY(68) DUMMY(69) DUMMY(70) DUMMY(71)
    DUMMY(72) DUMMY(73) DUMMY(74) DUMMY(75) DUMMY(76) DUMMY(77) DUMMY(78) DUMMY(79)
    DUMMY(80) DUMMY(81) DUMMY(82) DUMMY(83) DUMMY(84) DUMMY(85) DUMMY(86) DUMMY(87)
    DUMMY(88) DUMMY(89) DUMMY(90) DUMMY(91) DUMMY(92) DUMMY(93) DUMMY(94) DUMMY(95)
    DUMMY(96) DUMMY(97) DUMMY(98) DUMMY(99) DUMMY(100) DUMMY(101) DUMMY(102) DUMMY(103)
    DUMMY(104) DUMMY(105) DUMMY(106) DUMMY(107) DUMMY(108) DUMMY(109) DUMMY(110) DUMMY(111)
    DUMMY(112) DUMMY(113) DUMMY(114)
    virtual const char* getName();
    char pad2[0x1f8 - 0x40];
    u32 nodeIndex;
};

void* fn_74_B1D4(GImmick* self) {
    void* ret = setNode__9grGimmickFv(self);
    const char* name = self->getName();
    getNodeIndex__6GroundFPUlUlPCc(self, &self->nodeIndex, 0, name);
    return ret;
}

} // extern "C"
