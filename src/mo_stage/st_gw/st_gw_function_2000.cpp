#include <types.h>
#include <gf/gf_archive.h>
#include <mt/mt_prng.h>
#include <st/st_positions.h>
#pragma force_active on

#define SLOT(n) virtual void vf##n();

extern "C" const float lbl_63_rodata_0;

struct Range {
    float low;
    float high;
};

struct RangePair {
    Range first;
    Range second;
};

struct StageBase {
    char pad_00[0x3C];
};

class Stage : public StageBase {
public:
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41)
    virtual void updateStagePositions();
    SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52)
    SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59) SLOT(60) SLOT(61) SLOT(62)
    SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67) SLOT(68) SLOT(69) SLOT(70) SLOT(71) SLOT(72)
    SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79) SLOT(80) SLOT(81) SLOT(82)
    SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89) SLOT(90) SLOT(91) SLOT(92)
    SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99) SLOT(100) SLOT(101) SLOT(102)
    SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109) SLOT(110) SLOT(111) SLOT(112)
    SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118) SLOT(119) SLOT(120) SLOT(121) SLOT(122)
    SLOT(123) SLOT(124) SLOT(125) SLOT(126) SLOT(127) SLOT(128) SLOT(129) SLOT(130) SLOT(131) SLOT(132)
    SLOT(133) SLOT(134) SLOT(135) SLOT(136) SLOT(137) SLOT(138) SLOT(139) SLOT(140) SLOT(141) SLOT(142)
    SLOT(143) SLOT(144) SLOT(145) SLOT(146) SLOT(147) SLOT(148) SLOT(149) SLOT(150) SLOT(151) SLOT(152)
    SLOT(153) SLOT(154) SLOT(155)
    virtual void fn_63_2224(int);
    virtual void fn_63_2240();

    char pad_40[0x90 - 0x40];
    stPositions* m_90;
    char pad_94[0x9C - 0x94];
    RangePair* m_9C;
    char pad_A0[0x1A0 - 0xA0];
    gfArchive* m_1A0;
    char pad_1A4[0x1D8 - 0x1A4];
    unsigned char state;
    char pad_1D9[0x1DC - 0x1D9];
    float timer;
    unsigned char zone;
    char pad_1E1[0x1E4 - 0x1E1];
    unsigned char flag;
    char pad_1E5[0x306 - 0x1E5];
    unsigned char m_306;
};

extern "C" void fn_63_2000(Stage* self, float delta) {
    RangePair* range = self->m_9C;
    if (range != 0) {
        float t = self->timer - delta;
        self->timer = t;
        if (t < lbl_63_rodata_0) {
            self->timer = lbl_63_rodata_0;
        }
        switch ((int)self->state) {
        case 0:
            self->fn_63_2224(0);
            self->m_306 = 0x10;
            self->state = 1;
            break;
        case 1:
            self->timer = range->first.low + (range->first.high - range->first.low) * randf();
            self->state = 2;
            break;
        case 2:
            if (lbl_63_rodata_0 == self->timer) {
                self->fn_63_2240();
                void* data = self->m_1A0->getData(Data_Type_Model, self->zone + 0x64, 0xFFFE);
                if (data != 0) {
                    void* resFile = data;
                    self->m_90->loadPositionData((nw4r::g3d::ResFile*)&resFile);
                }
                self->updateStagePositions();
                self->flag = 1;
                self->state = 3;
            }
            break;
        case 3:
            self->timer = range->second.low + (range->second.high - range->second.low) * randf();
            self->state = 4;
            break;
        case 4:
            if (lbl_63_rodata_0 == self->timer || self->zone == 4) {
                self->fn_63_2224(0);
                self->m_306 = 0x10;
                void* data = self->m_1A0->getData(Data_Type_Model, self->zone + 0x64, 0xFFFE);
                if (data != 0) {
                    void* resFile = data;
                    self->m_90->loadPositionData((nw4r::g3d::ResFile*)&resFile);
                }
                self->updateStagePositions();
                self->state = 1;
            }
            break;
        }
    }
}
