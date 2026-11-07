#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>
#include <ec/ec_mgr.h>

extern "C" {
extern const float lbl_57_rodata_1C8[];
extern char lbl_57_data_1240[];
}

#define SLOT(n) virtual void unused##n();

struct Ground_base {
    unsigned char pad[0x3C];
};

struct GimmickFlags {
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 rest : 4;
};

struct GimmickSub {
    u8 pad[0x52];
    u16 unk52;
    GimmickFlags unk54;
};

class Ground : public Ground_base {
public:
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48)
    SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    virtual void setMotionFrame(float, u32);
    virtual float getMotionFrame(u32);
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117)
    virtual void fn_57_7028(int, int, int, float*);

    u8 pad40[0x44 - 0x40];
    nw4r::g3d::ScnMdl** unk44;
    u8 pad48[0x150 - 0x48];
    u8 unk150;
    u8 pad151[0x158 - 0x151];
    float* unk158;
    u8* unk15C;
    u8 unk160;
    u8 unk161;
    u8 pad162[0x164 - 0x162];
    float unk164;
    GimmickSub* unk168;
    u8 pad16C[0x10];
};

#undef SLOT

extern "C" void fn_57_6C70(Ground* self, float delta) {
    const float* rodata = lbl_57_rodata_1C8;

    if (self->unk158 != 0 && self->unk15C != 0) {
        self->unk164 = self->unk164 - delta;
        if (self->unk164 < rodata[0]) {
            self->unk164 = rodata[0];
        }

        switch (self->unk150) {
        case 0:
            self->fn_57_7028(2, 0, 1, 0);
            self->unk150 = 2;
            /* fallthrough */
        case 2:
            if (*self->unk15C == 2) {
                self->fn_57_7028(1, 0, 1, &self->unk164);
                self->setMotionFrame(*self->unk158, 0);
                self->unk150 = 3;
            }
            break;
        }

        switch (self->unk161) {
        case 1:
            switch (self->unk160) {
            case 0:
                if (!(self->getMotionFrame(0) < rodata[11])) {
                    u32 effect = g_ecMgr->setEffect((EfID)0x3F0002);
                    g_ecMgr->setParent(effect, *self->unk44, lbl_57_data_1240, false);
                    self->unk160 += 1;
                }
                break;
            }
            if (self->unk168 != 0) {
                if (self->getMotionFrame(0) >= rodata[12]) {
                    GimmickFlags fl = self->unk168->unk54;
                    fl.f0 = 0;
                    fl.f3 = fl.f0;
                    fl.f1 = fl.f3;
                    self->unk168->unk54 = fl;
                }
                if (self->getMotionFrame(0) >= rodata[13]) {
                    self->unk168->unk52 = 0x6000;
                } else {
                    self->unk168->unk52 = 0;
                }
            }
            ((StSeUtil::SeSeq*)&self->pad16C)->playFrame(0, self->getMotionFrame(0));
            if (*self->unk15C == 4) {
                self->fn_57_7028(0, 0, 1, &self->unk164);
                self->setMotionFrame(*self->unk158, 0);
                if (self->unk168 != 0) {
                    GimmickFlags fl = self->unk168->unk54;
                    fl.f3 = 1;
                    fl.f1 = fl.f3;
                    self->unk168->unk54 = fl;
                    self->unk168->unk52 = 0;
                }
                ((StSeUtil::SeSeq*)&self->pad16C)->playFrame(1, self->getMotionFrame(0), rodata[0]);
                return;
            }
            break;
        case 0:
            ((StSeUtil::SeSeq*)&self->pad16C)->playFrame(1, self->getMotionFrame(0));
            if (*self->unk15C == 2) {
                self->fn_57_7028(1, 0, 1, &self->unk164);
                self->setMotionFrame(*self->unk158, 0);
                self->unk160 = 0;
                ((StSeUtil::SeSeq*)&self->pad16C)->playFrame(0, self->getMotionFrame(0), rodata[14]);
            }
            break;
        }
    }
}
