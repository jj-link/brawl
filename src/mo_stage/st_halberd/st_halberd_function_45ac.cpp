#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>
#include <ec/ec_mgr.h>

extern "C" {
extern char lbl_57_data_840[];
extern const float lbl_57_rodata_118[];
}

#define SLOT(n) virtual void unused##n();

struct Ground_base {
    unsigned char pad[0x3C];
};

class Ground : public Ground_base {
public:
    SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48)
    virtual void getNodeIndex(u32, const char*);
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    virtual void setMotionFrame(float, u32);
    virtual float getMotionFrame(u32);
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118)
    virtual void fn_57_4920(int, int, int, float*);

    void getNodeIndex(u32* out, u32 mdl, const char* name);

    u8 pad40[0x44 - 0x40];
    nw4r::g3d::ScnMdl** unk44;
    u8 pad48[0x150 - 0x48];
    u8 unk150;
    u8 pad151[0x158 - 0x151];
    float* unk158;
    u8* unk15C;
    u8 unk160;
    u8 pad161[0x16C - 0x161];
    u8 unk16C;
    u8 pad16D[0x170 - 0x16D];
    float unk170;
    u32 unk174;
    u32 unk178;
    u32 unk17C;
    u32 unk180;
    u8 pad184[0x19C - 0x184];
    u8 pad19C[0x20];
    u8 pad1BC[0x3E0 - 0x1BC];
    snd3DGenerator unk3E0;
};

#undef SLOT

extern "C" void fn_57_45AC(Ground* self, float delta) {
    const char* strs = lbl_57_data_840;
    const float* rodata = lbl_57_rodata_118;

    if (self->unk158 != 0 && self->unk15C != 0) {
        self->unk170 = self->unk170 - delta;
        if (self->unk170 < rodata[0]) {
            self->unk170 = rodata[0];
        }

        switch (self->unk150) {
        case 0:
            self->fn_57_4920(2, 0, 1, 0);
            self->getNodeIndex(&self->unk174, 0, strs + 0x64);
            self->getNodeIndex(&self->unk178, 0, strs + 0x74);
            self->getNodeIndex(&self->unk17C, 0, strs + 0x84);
            self->getNodeIndex(&self->unk180, 0, strs + 0x94);
            self->unk150 = 2;
            /* fallthrough */
        case 2:
            if (*self->unk15C == 2) {
                self->fn_57_4920(0, 0, 1, &self->unk170);
                self->setMotionFrame(*self->unk158, 0);
                self->unk150 = 3;
            }
            break;
        case 3:
            break;
        }

        Vec3f pos;
        pos.m_x = rodata[0];
        pos.m_y = rodata[0];
        pos.m_z = rodata[0];
        self->unk3E0.setPos(&pos);

        switch (self->unk16C) {
        case 0:
            switch (self->unk160) {
            case 0:
                if (!(self->getMotionFrame(0) < rodata[2])) {
                    g_ecMgr->setDrawPrio(1);
                    u32 effect = g_ecMgr->setEffect((EfID)0x3F0001);
                    g_ecMgr->setDrawPrio(-1);
                    g_ecMgr->setParent(effect, *self->unk44, strs + 0xA4, false);
                    self->unk160 += 1;
                }
                break;
            }
            ((StSeUtil::SeSeq*)&self->pad19C)->playFrame(0, self->getMotionFrame(0));
            if (*self->unk15C == 4) {
                self->fn_57_4920(1, 0, 1, &self->unk170);
                self->setMotionFrame(*self->unk158, 0);
                ((StSeUtil::SeSeq*)&self->pad19C)->playFrame(1, self->getMotionFrame(0), rodata[0]);
            }
            break;
        case 1:
            ((StSeUtil::SeSeq*)&self->pad19C)->playFrame(1, self->getMotionFrame(0));
            if (*self->unk15C == 2) {
                self->fn_57_4920(0, 0, 1, &self->unk170);
                self->setMotionFrame(*self->unk158, 0);
                ((StSeUtil::SeSeq*)&self->pad19C)->playFrame(0, self->getMotionFrame(0), rodata[21]);
            }
            break;
        }
    }
}
