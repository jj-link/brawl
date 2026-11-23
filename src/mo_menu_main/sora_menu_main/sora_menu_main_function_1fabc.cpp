#include <types.h>
#include <snd/snd_system.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct MenuObjects {
    char pad[0x1a4];
    MuObject* object1a4;
    MuObject* object1a8;
    MuObject* object1ac;
    char pad1b0[0x0c];
    MuObject* object1bc;
};

struct SoundEntry {
    u32 message;
    u32 type;
    u32 groupCount;
    s32 groups[61];
    s32 sound;
    char pad[0x1fc];
};

struct Menu {
    char pad0[0x42];
    u16 selection;
    char pad44[0x634 - 0x44];
    s32 result;
    s32 previous;
    char pad63c[0x10];
    MenuObjects* objects;
    char pad650[0x14];
    s32 mode;
    char pad668[4];
    MuMsg* msg;
    u8 bgmPlaying;
    char pad671[3];
    s32 bgmState;
    s32 soundHandle;
    s32 soundId;
    char pad680[0x0c];
    s32 category;
    u32 index;
    char pad694[0x14];
    void* messageData;
    SoundEntry* entries;
    char pad6b0[4];
    u32 counts[101];
};

extern "C" {
    extern s32 lbl_16_data_28;
    extern char lbl_2_data_2898[];
    extern char lbl_2_data_28C0[];
    extern void* lbl_805A01D8;

    s32 fn_80077DA0(sndSystem*, s32);
    void fn_80075F1C(sndSystem*, s32, s32);
    void fn_80073F84(sndSystem*, s32);
    void fn_80078DAC(void*, s32, s32, s32);
    void fn_800B330C(MuObject*, void*, s32);
    void fn_800B5854(MuObject*, s32, s32, s32, s32);
    void fn_800B7AA4(MuObject*, s32, float);
    void fn_800B7F38(MuObject*, s32, float);
    void fn_8006BAB0(void*, s32, u32, s32);
    void fn_18_17B0(Menu*, s32, s32, float);
    void fn_2_20FEC(Menu*);
    s32 fn_2_21678(Menu*, s32);
    void fn_2_21578(Menu*, s32);
}

#define UPDATE_SOUND_DISPLAY() \
    do { \
        self->msg->printIndex(5, self->entries[self->category].message, self->messageData); \
        u32 type = self->entries[self->category].type; \
        float frame; \
        switch (type) { \
            case 20: frame = 21.0f; break; \
            case 21: frame = 50.0f; break; \
            case 22: frame = 22.0f; break; \
            case 23: frame = 23.0f; break; \
            default: frame = 1.0f + (float)type; break; \
        } \
        fn_18_17B0(self, 0x6a, 4, frame); \
        u32 value = self->index + 1; \
        s32 digits[4] = { 0, 0, 0, 0 }; \
        if (value >= 100) fn_8006BAB0(digits, lbl_16_data_28, value / 100, 1); \
        if (value >= 10) fn_8006BAB0(digits, lbl_16_data_28, (value % 100) / 10, 1); \
        fn_8006BAB0(digits, lbl_16_data_28, value % 10, 1); \
        self->msg->printf(6, (const char*)digits); \
    } while (0)

extern "C" s32 fn_2_1FABC(Menu* self, s32 flags) {
    float pool;
    double bias;
    pool = 0.0625f;
    pool = 0.05f;
    pool = 49.0f;
    pool = 0.125f;
    pool = 1.0f;
    pool = 2.0f;
    pool = 21.0f;
    pool = 50.0f;
    pool = 22.0f;
    pool = 23.0f;
    bias = 4503599627370496.0;
    pool = -1.0f;
    pool = 0.0f;
    pool = 3.0f;
    pool = 4.0f;
    pool = 9.0f;
    bias = 4503601774854144.0;

    u32 i;

    if (self->soundHandle != -1 && fn_80077DA0(g_sndSystem, self->soundHandle) != 0) {
        self->objects->object1a8->m_modelAnim->m_anmObjChrRes->GetUpdateRate();
    }

    if (flags & 0x21) {
        if (self->selection != 0) {
            --self->selection;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            if (self->selection == 1) {
                if (self->soundHandle != -1 && fn_80077DA0(g_sndSystem, self->soundHandle) != 0) {
                    fn_80075F1C(g_sndSystem, self->soundHandle, 0);
                }
                self->soundHandle = -1;
                g_sndSystem->freeGroup(0, 0x1b);
            }
            self->objects->object1a8->setFrameVisible((float)((self->selection + 2) % 3));
            self->objects->object1ac->setFrameVisible(2.0f);
        } else if (flags & 0x20) {
            if (!self->bgmPlaying || g_sndSystem->getBGMId() == -1) {
                fn_80078DAC(lbl_805A01D8, 0x2a, 0, 0);
            }
            fn_800B330C(self->objects->object1bc, lbl_2_data_2898 + 0x14, 0);
            fn_800B330C(self->objects->object1a4, lbl_2_data_28C0 + 0x64, 1);
            fn_800B330C(self->objects->object1a8, lbl_2_data_28C0 + 0x50, 1);
            fn_800B5854(self->objects->object1ac, 1, 1, 1, 0);
            if (self->previous == 0x0b) {
                self->result = 0x0b;
            } else {
                self->result = 6;
            }
            return 1;
        }
    } else if (flags & 0x202) {
        if (self->selection < 2) {
            ++self->selection;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            if (self->selection == 2) {
                for (i = 0; i < self->entries[self->category].groupCount; ++i) {
                    s32 id = self->entries[self->category].groups[i];
                    if (id >= 1 || id < -1) {
                        g_sndSystem->loadSoundGroup((SndGroupID)id, 0x1b, true);
                        self->soundHandle = -1;
                    }
                }
                self->mode = 2;
            }
            self->objects->object1a8->setFrameVisible((float)((self->selection + 2) % 3));
        } else if (flags & 0x10) {
            if (self->soundHandle != -1 && fn_80077DA0(g_sndSystem, self->soundHandle) != 0) {
                fn_80075F1C(g_sndSystem, self->soundHandle, 0);
                self->soundHandle = -1;
            }
            self->soundHandle = g_sndSystem->playSE((SndID)self->soundId, -1, 0, 0, -1);
            fn_800B330C(self->objects->object1a8, lbl_2_data_28C0 + 0x78, 1);
        }
    } else if (flags & 4) {
        switch ((s32)self->selection) {
            case 0:
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->mode = 0;
                fn_800B330C(self->objects->object1a4, lbl_2_data_28C0 + 0x3c, 1);
                fn_800B330C(self->objects->object1a8, lbl_2_data_28C0 + 0x14, 1);
                fn_800B7AA4(self->objects->object1a8, 0x11, 9.0f);
                if (self->bgmPlaying) {
                    fn_800B330C(self->objects->object1a4, lbl_2_data_28C0 + 0x28, 1);
                }
                fn_2_20FEC(self);
                break;
            case 1:
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->index = 0;
                do {
                    --self->category;
                    if (self->category < 0) {
                        self->category = 100;
                    }
                } while (!fn_2_21678(self, self->category));
                self->soundId = self->entries[self->category].sound;
                UPDATE_SOUND_DISPLAY();
                break;
            case 2:
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                if (self->index == 0) {
                    self->index = self->counts[self->category] - 1;
                } else {
                    --self->index;
                }
                UPDATE_SOUND_DISPLAY();
                fn_2_21578(self, 0);
                break;
        }
    } else if (flags & 8) {
        switch ((s32)self->selection) {
            case 1:
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->index = 0;
                do {
                    ++self->category;
                    if (self->category >= 101) {
                        self->category = 0;
                    }
                } while (!fn_2_21678(self, self->category));
                self->soundId = self->entries[self->category].sound;
                UPDATE_SOUND_DISPLAY();
                break;
            case 2:
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                self->index = (self->index + 1) % self->counts[self->category];
                UPDATE_SOUND_DISPLAY();
                fn_2_21578(self, 1);
                break;
        }
    } else if (flags & 0x100) {
        if (self->soundHandle != -1 && fn_80077DA0(g_sndSystem, self->soundHandle) != 0) {
            fn_80075F1C(g_sndSystem, self->soundHandle, 0x3c);
            self->soundHandle = -1;
        }
        fn_80073F84(g_sndSystem, 0x78);
        self->bgmPlaying = 0;
        self->bgmState = 0;
        fn_800B7F38(self->objects->object1a4, 0x11, 0.0f);
    }

    return 0;
}

#undef UPDATE_SOUND_DISPLAY
