#include <mt/mt_vector.h>

#pragma force_active on

typedef unsigned char u8;

struct Block {
    Vec3f a;
    Vec3f pos;
    u8 id;
    u8 state;
    u8 kind;
    u8 pad;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void slot_008() = 0;
    virtual void slot_00C() = 0;
    virtual void slot_010() = 0;
    virtual void slot_014() = 0;
    virtual void slot_018() = 0;
    virtual void slot_01C() = 0;
    virtual void slot_020() = 0;
    virtual void slot_024() = 0;
    virtual void slot_028() = 0;
    virtual void slot_02C() = 0;
    virtual void slot_030() = 0;
    virtual void slot_034() = 0;
    virtual void slot_038() = 0;
    virtual void slot_03C() = 0;
    virtual void slot_040() = 0;
    virtual void slot_044() = 0;
    virtual void slot_048() = 0;
    virtual void slot_04C() = 0;
    virtual void slot_050() = 0;
    virtual void slot_054() = 0;
    virtual void slot_058() = 0;
    virtual void slot_05C() = 0;
    virtual void slot_060() = 0;
    virtual void slot_064() = 0;
    virtual void slot_068() = 0;
    virtual void slot_06C() = 0;
    virtual void slot_070() = 0;
    virtual void slot_074() = 0;
    virtual void slot_078() = 0;
    virtual void slot_07C() = 0;
    virtual void slot_080() = 0;
    virtual void slot_084() = 0;
    virtual void slot_088() = 0;
    virtual void slot_08C() = 0;
    virtual void slot_090() = 0;
    virtual void slot_094() = 0;
    virtual void slot_098() = 0;
    virtual void slot_09C() = 0;
    virtual void slot_0A0() = 0;
    virtual void slot_0A4() = 0;
    virtual void slot_0A8() = 0;
    virtual void slot_0AC() = 0;
    virtual void slot_0B0() = 0;
    virtual void slot_0B4() = 0;
    virtual void slot_0B8() = 0;
    virtual void slot_0BC() = 0;
    virtual void slot_0C0() = 0;
    virtual void slot_0C4() = 0;
    virtual void slot_0C8() = 0;
    virtual void slot_0CC() = 0;
    virtual void slot_0D0() = 0;
    virtual void slot_0D4() = 0;
    virtual void slot_0D8() = 0;
    virtual void slot_0DC() = 0;
    virtual void slot_0E0() = 0;
    virtual void slot_0E4() = 0;
    virtual void slot_0E8() = 0;
    virtual void slot_0EC() = 0;
    virtual void slot_0F0() = 0;
    virtual void slot_0F4() = 0;
    virtual void slot_0F8() = 0;
    virtual void slot_0FC() = 0;
    virtual void slot_100() = 0;
    virtual void slot_104() = 0;
    virtual void slot_108() = 0;
    virtual void slot_10C() = 0;
    virtual void slot_110() = 0;
    virtual void slot_114() = 0;
    virtual void slot_118() = 0;
    virtual void slot_11C() = 0;
    virtual void slot_120() = 0;
    virtual void slot_124() = 0;
    virtual void slot_128() = 0;
    virtual void slot_12C() = 0;
    virtual void slot_130() = 0;
    virtual void slot_134() = 0;
    virtual void slot_138() = 0;
    virtual void slot_13C() = 0;
    virtual void slot_140() = 0;
    virtual void slot_144() = 0;
    virtual void slot_148() = 0;
    virtual void slot_14C() = 0;
    virtual void slot_150() = 0;
    virtual void slot_154() = 0;
    virtual void slot_158() = 0;
    virtual void slot_15C() = 0;
    virtual void slot_160() = 0;
    virtual void slot_164() = 0;
    virtual void slot_168() = 0;
    virtual void slot_16C() = 0;
    virtual void slot_170() = 0;
    virtual void slot_174() = 0;
    virtual void slot_178() = 0;
    virtual void slot_17C() = 0;
    virtual void slot_180() = 0;
    virtual void slot_184() = 0;
    virtual void enableHit(unsigned long, unsigned long) = 0;
    virtual void disableHit(unsigned long, unsigned long) = 0;
    virtual void slot_190() = 0;
    virtual void slot_194() = 0;
    virtual void slot_198() = 0;
    virtual void slot_19C() = 0;
    virtual void slot_1A0() = 0;
    virtual void slot_1A4() = 0;
    virtual void slot_1A8() = 0;
    virtual void slot_1AC() = 0;
    virtual void slot_1B0() = 0;
    virtual void slot_1B4() = 0;
    virtual void slot_1B8() = 0;
    virtual void slot_1BC() = 0;
    virtual void slot_1C0() = 0;
    virtual void slot_1C4() = 0;
    virtual void fn_79_1EE4() = 0;
    virtual void slot_1CC() = 0;
    virtual void slot_1D0() = 0;
    virtual void fn_79_329C(u8, u8) = 0;

    char pad1[0x10c];
    int cond;
    Block* blocks;
    char pad2[5];
    u8 done[30];
    char pad3[0x79];
    u8 active;
    char pad4[0x1b];
    void* module;
};

extern "C" {
extern const float lbl_79_rodata_10;
extern void* g_sndSystem;

void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_27_263750(void*, unsigned long);

void fn_79_1EE4(Ground& self) {
    u8 active = self.active;

    if (active == 1) {
        u8 group;
        u8 i;
        Block* block;

        for (group = 0; group < 6; ++group) {
            for (i = 0; i < 5; ++i) {
                block = &self.blocks[group * 5 + i];

                switch (block->state) {
                case 2:
                    self.enableHit(block->id + group * 5, 0);
                    break;

                case 3:
                    block->state = 4;
                    if (block->kind == 1) {
                        self.fn_79_329C(group, i);
                        self.done[group * 5 + i] = 1;

                        Vec3f quake(
                            lbl_79_rodata_10,
                            lbl_79_rodata_10,
                            lbl_79_rodata_10);
                        cmReqQuake__FiP5Vec3f(4, &quake);
                    } else {
                        Vec3f quake(
                            lbl_79_rodata_10,
                            lbl_79_rodata_10,
                            lbl_79_rodata_10);
                        cmReqQuake__FiP5Vec3f(3, &quake);
                        playSE__9sndSystemF5SndIDiiii(
                            g_sndSystem, 0x1dba, 0, 0, 0, -1);
                    }
                    break;

                case 7:
                    if (self.done[group * 5 + i] == 1) {
                        fn_27_263750(self.module, group * 5 + i);
                        self.done[group * 5 + i] = 0;
                    }
                    break;
                }
            }
        }
    } else {
        self.slot_1D0();
        if (self.cond != 0) {
            self.active = 1;

            for (u8 group = 0; group < 6; ++group) {
                for (u8 i = 0; i < 5; ++i) {
                    self.disableHit(group * 5 + i, 0);
                }
            }
        }
    }
}
}