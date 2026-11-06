#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>

extern "C" {
extern char lbl_57_data_E58[];
extern const float lbl_57_rodata_198;
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
    virtual void getNodeIndex(u32*, u32, const char*);
    SLOT(50) SLOT(51) SLOT(52) SLOT(53) SLOT(54) SLOT(55) SLOT(56) SLOT(57) SLOT(58) SLOT(59)
    SLOT(60) SLOT(61) SLOT(62) SLOT(63) SLOT(64) SLOT(65) SLOT(66) SLOT(67)
    virtual void setMotionFrame(float, u32);
    virtual float getMotionFrame(u32);
    SLOT(70) SLOT(71) SLOT(72) SLOT(73) SLOT(74) SLOT(75) SLOT(76) SLOT(77) SLOT(78) SLOT(79)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84) SLOT(85) SLOT(86) SLOT(87) SLOT(88) SLOT(89)
    SLOT(90) SLOT(91) SLOT(92) SLOT(93) SLOT(94) SLOT(95) SLOT(96) SLOT(97) SLOT(98) SLOT(99)
    SLOT(100) SLOT(101) SLOT(102) SLOT(103) SLOT(104) SLOT(105) SLOT(106) SLOT(107) SLOT(108) SLOT(109)
    SLOT(110) SLOT(111) SLOT(112) SLOT(113) SLOT(114) SLOT(115) SLOT(116) SLOT(117) SLOT(118) SLOT(119)
    virtual void fn_57_6328(int, int, int, float*);

    u8 pad40[0x150 - 0x40];
    u8 unk150;
    u8 pad151[0x158 - 0x151];
    float* unk158;
    u8* unk15C;
    u8 pad160[0x170 - 0x160];
    float unk170;
    u8 pad174[0x17C - 0x174];
    u32 unk17C;
    u32 unk180;
    u32 unk184;
    u32 unk188;
    u8 pad18C[0x20];
    u8 pad1AC[0x224 - 0x1AC];
    snd3DGenerator unk224;
};

#undef SLOT

extern "C" void fn_57_6028(Ground* self, float delta) {
    const char* strs = lbl_57_data_E58;

    if (self->unk158 != 0 && self->unk15C != 0) {
        self->unk170 = self->unk170 - delta;
        if (self->unk170 < lbl_57_rodata_198) {
            self->unk170 = lbl_57_rodata_198;
        }

        switch (self->unk150) {
        case 0:
            self->fn_57_6328(1, 0, 1, 0);
            self->Ground::getNodeIndex(&self->unk17C, 0, strs + 0x30);
            self->Ground::getNodeIndex(&self->unk180, 0, strs + 0x44);
            self->Ground::getNodeIndex(&self->unk184, 0, strs + 0x58);
            self->Ground::getNodeIndex(&self->unk188, 0, strs + 0x6C);
            self->unk150 = 2;
            break;
        case 2:
            if (*self->unk15C == 2) {
                self->fn_57_6328(0, 0, 1, &self->unk170);
                self->setMotionFrame(*self->unk158, 0);
                self->unk150 = 3;
            }
            break;
        case 3: {
            Vec3f pos;
            pos.m_x = lbl_57_rodata_198;
            pos.m_y = lbl_57_rodata_198;
            pos.m_z = lbl_57_rodata_198;
            self->unk224.setPos(&pos);
            ((StSeUtil::SeSeq*)&self->pad18C)->playFrame(0, self->getMotionFrame(0));
            if (self->getMotionFrame(0) >= self->unk170) {
                self->unk150 = 4;
            }
            break;
        }
        }
    }
}
