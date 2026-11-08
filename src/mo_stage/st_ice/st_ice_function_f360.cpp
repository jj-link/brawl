#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
#define V(n) virtual void v##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
V(60) V(61) V(62) V(63) V(64) V(65) V(66)
virtual float getValue(int);
V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
virtual void clear(int);
V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108)
V(109) V(110) V(111) V(112) V(113) V(114)
virtual void action();
V(116) V(117) V(118) V(119) V(120)
virtual void inactive();
virtual void done();
    char pad1[0x14c - 0x40]; int f14c; char f150;
    char pad2[0x170 - 0x151]; unsigned char f170; unsigned char f171;
    char pad3[0x198 - 0x172]; int f198; int f19c;
};
extern "C" const float lbl_62_rodata_1B0[];
extern "C" void setAreaSleep__9stTriggerFb(void*, bool);
extern "C" void fn_62_F360(Ground* self) {
    const float* c = lbl_62_rodata_1B0;
    if (self->f170 == 1) {
        switch (self->f150) {
        case 7:
            if (self->getValue(0) <= c[1]) {
                void* trigger = (void*)self->f19c;
                if (trigger) setAreaSleep__9stTriggerFb(trigger, false);
            } else if (self->getValue(0) >= c[2] && self->getValue(0) <= c[3]) {
                self->action();
            } else {
                if (self->f171 == 1) self->clear(0);
                self->f171 = 0;
                void* trigger = (void*)self->f19c;
                if (trigger) setAreaSleep__9stTriggerFb(trigger, true);
            }
            break;
        default:
            if (self->f171 == 1) self->clear(0);
            self->f171 = 0;
            void* trigger = (void*)self->f19c;
            if (trigger) setAreaSleep__9stTriggerFb(trigger, true);
        }
        if (self->f198 == 1) self->done();
    } else {
        self->inactive();
        if (self->f14c != 0) self->f170 = 1;
    }
}