#include <types.h>
#include <gf/gf_archive.h>
#include <mt/mt_prng.h>
#include <st/st_positions.h>

#pragma force_active on

extern "C" const float lbl_66_rodata_0;

struct RangePair {
    char pad[0x88];
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;
};

struct StageBase { char pad[0x3c]; };

#define VF(n) virtual unsigned vf##n();
struct Ground : StageBase {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
    VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
    VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29)
    VF(30) VF(31) VF(32) VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39)
    VF(40) VF(41) VF(42) VF(43) VF(44) VF(45) VF(46) VF(47) VF(48) VF(49)
    VF(50) VF(51) VF(52) VF(53) VF(54) VF(55) VF(56) VF(57) VF(58) VF(59)
    VF(60) VF(61) VF(62) VF(63) VF(64) VF(65) VF(66) VF(67) VF(68) VF(69)
    VF(70) VF(71) VF(72) VF(73) VF(74) VF(75) VF(76) VF(77) VF(78) VF(79)
    VF(80) VF(81) VF(82) VF(83) VF(84) VF(85) VF(86) VF(87) VF(88) VF(89)
    VF(90) VF(91) VF(92) VF(93) VF(94) VF(95) VF(96) VF(97) VF(98) VF(99)
    VF(100) VF(101) VF(102) VF(103) VF(104) VF(105) VF(106) VF(107) VF(108) VF(109)
    VF(110) VF(111) VF(112) VF(113) VF(114) VF(115) VF(116) VF(117) VF(118) VF(119)
    VF(120) VF(121) VF(122) VF(123) VF(124) VF(125) VF(126) VF(127) VF(128)
#undef VF
};

#define SV(n) virtual void sv##n();
struct Stage : StageBase {
    SV(0) SV(1) SV(2) SV(3) SV(4) SV(5) SV(6) SV(7) SV(8) SV(9)
    SV(10) SV(11) SV(12) SV(13) SV(14) SV(15) SV(16) SV(17) SV(18) SV(19)
    SV(20) SV(21) SV(22) SV(23) SV(24) SV(25) SV(26) SV(27) SV(28) SV(29)
    SV(30) SV(31) SV(32) SV(33) SV(34) SV(35) SV(36) SV(37) SV(38) SV(39)
    virtual void updateStagePositions();
    char pad_40[0x90 - 0x40];
    stPositions* pos_90;
    char pad_94[0x9c - 0x94];
    RangePair* range_9c;
    char pad_a0[0x1a0 - 0xa0];
    gfArchive* archive_1a0;
    char pad_1a4[0x254 - 0x1a4];
    unsigned char state;
    char pad_255[3];
    float timer;
    unsigned char flag;
};

extern "C" Ground* getGround__5StageFi(Stage*, int);

extern "C" void fn_66_1EB0(Stage* self, float delta) {
    RangePair* range;
    Ground* g1 = getGround__5StageFi(self, 0xE);
    if (g1 != 0 && getGround__5StageFi(self, 3) != 0 && (range = self->range_9c) != 0) {
        float t = self->timer - delta;
        self->timer = t;
        if (t < lbl_66_rodata_0)
            self->timer = lbl_66_rodata_0;
        switch ((int)self->state) {
        case 0:
            if (self->flag == 1) {
                float r = randf();
                float d = range->f8c - range->f88;
                self->timer = range->f88 + d * r;
                self->flag = 0;
            } else {
                float r = randf();
                float d = range->f94 - range->f90;
                self->timer = range->f90 + d * r;
            }
            self->state = 1;
            break;
        case 1:
            if (lbl_66_rodata_0 == self->timer && g1->vf120() == 1) {
                float r = randf();
                float d = range->f9c - range->f98;
                self->timer = range->f98 + d * r;
                void* data = self->archive_1a0->getData(Data_Type_Model, 0x6e, 0xFFFE);
                if (data != 0) {
                    void* resFile = data;
                    self->pos_90->loadPositionData((nw4r::g3d::ResFile*)&resFile);
                }
                self->updateStagePositions();
                self->state = 2;
            }
            break;
        case 2:
            if (g1->vf124() == 1)
                self->state = 3;
            break;
        case 3:
            if (lbl_66_rodata_0 == self->timer && g1->vf121() == 1)
                self->state = 4;
            if (g1->vf126() == 1)
                self->state = 0;
            break;
        case 4:
            if (g1->vf125() == 1) {
                void* data = self->archive_1a0->getData(Data_Type_Model, 0x64, 0xFFFE);
                if (data != 0) {
                    void* resFile = data;
                    self->pos_90->loadPositionData((nw4r::g3d::ResFile*)&resFile);
                }
                self->updateStagePositions();
                self->state = 0;
            }
            break;
        }
    }
}
