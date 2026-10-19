#pragma force_active on
typedef unsigned long u32;

struct Resource {
    void* file;
};

struct State {
    unsigned char pad[0x37];
    unsigned char active;
};

struct Base {
    unsigned char pad0[0x3C];
};

#define SLOT(n) virtual void v##n();

struct Dispatch : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69)
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113)
    virtual void activate();
};

#undef SLOT

struct Stage : Dispatch {
    unsigned char pad40[8];
    Resource* resource;
    unsigned char pad4C[0x114];
    State* state;
};

extern "C" u32 GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(void*);
extern "C" void changeNodeAnim__9grGimmickFUlUl(Stage*, u32, u32);

extern "C" void fn_40_25600(Stage* self) {
    if (bool(GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(self->resource->file)) == true) {
        changeNodeAnim__9grGimmickFUlUl(self, 0, 0);
    }

    if (self->state->active) {
        self->activate();
    }
}
