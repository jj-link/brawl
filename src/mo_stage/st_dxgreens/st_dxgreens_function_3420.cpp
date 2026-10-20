#pragma force_active on
typedef unsigned char u8;

struct Vec3f { float x, y, z; };
struct Block { Vec3f a; Vec3f pos; u8 id, state, kind, pad; };
struct StagePrefix { u8 pad0[0x3c]; };

class Stage : public StagePrefix {
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void slot_a4() = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void slot_dc() = 0;
    virtual void slot_e0() = 0;
    virtual void slot_e4() = 0;
    virtual void slot_e8() = 0;
    virtual void slot_ec() = 0;
    virtual void slot_f0() = 0;
    virtual void slot_f4() = 0;
    virtual void slot_f8() = 0;
    virtual void slot_fc() = 0;
    virtual void slot_100() = 0;
    virtual void slot_104() = 0;
    virtual void slot_108() = 0;
    virtual void slot_10c() = 0;
    virtual void slot_110() = 0;
    virtual void slot_114() = 0;
    virtual void slot_118() = 0;
    virtual void slot_11c() = 0;
    virtual void slot_120() = 0;
    virtual void slot_124() = 0;
    virtual void slot_128() = 0;
    virtual void slot_12c() = 0;
    virtual void slot_130() = 0;
    virtual void slot_134() = 0;
    virtual void slot_138() = 0;
    virtual void slot_13c() = 0;
    virtual void slot_140() = 0;
    virtual void slot_144() = 0;
    virtual void slot_148() = 0;
    virtual void slot_14c() = 0;
    virtual void slot_150() = 0;
    virtual void slot_154() = 0;
    virtual void slot_158() = 0;
    virtual void slot_15c() = 0;
    virtual void slot_160() = 0;
    virtual void slot_164() = 0;
    virtual void slot_168() = 0;
    virtual void slot_16c() = 0;
    virtual void slot_170() = 0;
    virtual void slot_174() = 0;
    virtual void slot_178() = 0;
    virtual void slot_17c() = 0;
    virtual void slot_180() = 0;
    virtual void slot_184() = 0;
    virtual void slot_188() = 0;
public:
    virtual void notify(int, int) = 0;
private:
    virtual void slot_190() = 0;
    virtual void slot_194() = 0;
    virtual void slot_198() = 0;
    virtual void slot_19c() = 0;
    virtual void slot_1a0() = 0;
    virtual void slot_1a4() = 0;
    virtual void slot_1a8() = 0;
    virtual void slot_1ac() = 0;
    virtual void slot_1b0() = 0;
    virtual void slot_1b4() = 0;
    virtual void slot_1b8() = 0;
    virtual void slot_1bc() = 0;
    virtual void slot_1c0() = 0;
    virtual void slot_1c4() = 0;
    virtual void slot_1c8() = 0;
    virtual void slot_1cc() = 0;
    virtual void slot_1d0() = 0;
public:
    virtual void destroyBlock(u8, u8) = 0;
    u8 pad1[0x14c - 0x40];
public:
    void* object;
    Block* blocks;
};

extern "C" {
void fn_27_26399C(void*);
extern const float lbl_79_rodata_10;
extern void* g_ecMgr;
extern void* g_sndSystem;
void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void setEffect__5ecMgrF4EfIDP5Vec3f(void*, int, Vec3f*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

void fn_79_3420(Stage* self, int index) {
    fn_27_26399C(self->object);
    self->notify(index, 0);

    u8 group, id;
    if (index < 5) { id = index; group = 0; }
    else if (index < 10) { id = index - 5; group = 1; }
    else if (index < 15) { id = index - 10; group = 2; }
    else if (index < 20) { id = index - 15; group = 3; }
    else if (index < 25) { id = index - 20; group = 4; }
    else { id = index - 25; group = 5; }

    Block* block;
    for (u8 i = 0; i < 5; ++i) {
        block = &self->blocks[group * 5 + i];
        if (block->id != id) continue;

        switch (block->state) {
        case 2:
            block->state = 4;
            if (block->kind == 1) {
                self->destroyBlock(group, id);
                Vec3f quake = {
                    lbl_79_rodata_10,
                    lbl_79_rodata_10,
                    lbl_79_rodata_10
                };
                cmReqQuake__FiP5Vec3f(4, &quake);
                setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5e0003, &block->pos);
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x50, 0, 0, 0, -1);
            } else {
                Vec3f quake = {
                    lbl_79_rodata_10,
                    lbl_79_rodata_10,
                    lbl_79_rodata_10
                };
                cmReqQuake__FiP5Vec3f(3, &quake);
                setEffect__5ecMgrF4EfIDP5Vec3f(g_ecMgr, 0x5e0004, &block->pos);
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1dba, 0, 0, 0, -1);
            }
            break;
        }
    }
}
}
