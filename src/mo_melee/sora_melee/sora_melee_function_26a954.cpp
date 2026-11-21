#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <revolution/MTX/mtx.h>
#include <snd/snd_3d_generator.h>

extern "C" {
extern unsigned char lbl_27_data_547E4;
extern const float lbl_27_rodata_4388;
int fn_800797A4(snd3DGenerator*, int);
}

// Entry stride is 0x28 bytes.
struct SoundEntry {
    u16 type;       // 0x00
    u16 pad02;      // 0x02
    f32 timer;      // 0x04
    s32 handle;     // 0x08
    s32 id;         // 0x0C
    s32 threshold;  // 0x10
    s32 unk14;      // 0x14
    u16 flag;       // 0x18
    u16 genIdx;     // 0x1A
    Vec2f offset;   // 0x1C
    s32 pad24;      // 0x24
};

struct SoundCfg {
    char pad0[4];
    u32 flags;      // 0x04
    Vec3f pos;      // 0x08
    char pad1[0x5C - 0x14];
    f32 x5C;        // 0x5C
    char pad2[0xC];
    f32 x6C;        // 0x6C
    char pad3[0xC];
    f32 x7C;        // 0x7C
};

// Classes this function calls through, from the game's vtables.
class Object_vptr_3c_base { public: char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50(Mtx out, unsigned long flag, unsigned long node);
};

class SoundObj : public Object_vptr_3c {
public:
    char pad40[0xA0 - 0x40];
    snd3DGenerator* gens;   // 0xA0
    u32 count;              // 0xA4
    SoundEntry* entries;    // 0xA8
    char padAC[0xD4 - 0xAC];
    SoundCfg* cfg;          // 0xD4
};

#define ENT(f) (((SoundEntry*)((char*)self->entries + off))->f)

inline void resetSound(SoundEntry& sound) {
    sound.type = 0;
    sound.timer = lbl_27_rodata_4388;
    sound.handle = -1;
    sound.genIdx = 0;
    sound.offset = Vec2f(lbl_27_rodata_4388, lbl_27_rodata_4388);
}

inline void updateSounds(SoundObj* self, f32 dt) {
    if (!lbl_27_data_547E4) {
        return;
    }
    {
        u32 i = 0;
        u32 off = 0;
        while (i < self->count) {
            if ((u32)ENT(id) + 0x10000u != 0xFFFFu) {
                if (ENT(type) == 1) {
                    if ((f32)ENT(threshold) <= ENT(timer)) {
                        (self->gens + ENT(genIdx))->startSE(ENT(handle), 0);
                        ENT(type) = 2;
                        ENT(timer) = lbl_27_rodata_4388;
                    }
                }
                if (ENT(handle) >= 0 && ENT(type) == 2) {
                    if ((u32)ENT(id) + 0x10000u != 0xFFFFu) {
                        u16 node = ENT(flag);
                        if (node == 0) {
                            SoundCfg* cfg = self->cfg;
                            Vec3f tmp;
                            if (cfg != NULL) {
                                if (cfg->flags & 8) {
                                    f32 x, y, z;
                                    z = cfg->x7C;
                                    y = cfg->x6C;
                                    x = cfg->x5C;
                                    cfg->pos.m_x = x;
                                    cfg->pos.m_y = y;
                                    cfg->pos.m_z = z;
                                }
                                __memcpy(&tmp, &self->cfg->pos, sizeof(tmp));
                            } else {
                                tmp.m_x = lbl_27_rodata_4388;
                                tmp.m_y = lbl_27_rodata_4388;
                                tmp.m_z = lbl_27_rodata_4388;
                            }
                            (self->gens + ENT(genIdx))->setPos(&tmp);
                        } else {
                            Mtx m;
                            self->slot50(m, 0, node);
                            Vec3f tmp;
                            f32 z = m[2][3];
                            f32 y = m[1][3];
                            f32 x = m[0][3];
                            tmp.m_y = y;
                            tmp.m_x = x;
                            tmp.m_z = z;
                            (self->gens + ENT(genIdx))->setPos(&tmp);
                        }
                    }
                    if (fn_800797A4(self->gens + ENT(genIdx), ENT(handle)) == 0) {
                        if (ENT(handle) >= 0) {
                            (self->gens + ENT(genIdx))->stopSE(ENT(handle), 0);
                            SoundEntry& sound = *((SoundEntry*)((char*)self->entries + off));
                            resetSound(sound);
                        }
                    }
                    if (ENT(unk14) != 0 && (f32)ENT(unk14) <= ENT(timer)) {
                        if (ENT(handle) >= 0) {
                            (self->gens + ENT(genIdx))->stopSE(ENT(handle), 0);
                            SoundEntry& sound = *((SoundEntry*)((char*)self->entries + off));
                            sound.type = 0;
                            sound.timer = lbl_27_rodata_4388;
                            sound.handle = -1;
                            sound.genIdx = 0;
                            sound.offset = Vec2f(lbl_27_rodata_4388, lbl_27_rodata_4388);
                        }
                    }
                }
                ENT(timer) += dt;
            }
            off += 0x28;
            ++i;
        }
    }
}

extern "C" void fn_27_26A954(SoundObj* self, f32 dt) {
    updateSounds(self, dt);
}
