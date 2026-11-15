#pragma force_active on

#include <types.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_pad_system.h>

struct FnObj {
    float x, y, z, w;
    char* ptr;
};

struct SunsetEntry {
    u8 flag;
    s32 start, end, len, unk10;
    float fa, fb, alpha;
    bool inRange(s32 frame) {
        if (start <= frame && frame <= end) return true;
        return false;
    }
    bool inStart(s32 frame) {
        if (start <= frame && frame <= start + len) return true;
        return false;
    }
    bool inEnd(s32 frame) {
        if (end - unk10 <= frame && frame <= end) return true;
        return false;
    }
};

struct SunsetModel {
    u8 pad[0xc];
    nw4r::g3d::ScnMdl* scn;
};

struct SunsetAnim {
    u8 pad[0xac];
    s32 value;
};

struct SunsetTiming {
    u16 unk0, count;
};

struct Sunset {
    u8 pad0[0x40];
    SunsetAnim* anim;
    u8 pad1[0x1c];
    SunsetModel** models;
    u8 pad2[0x8];
    SunsetTiming* timing;
    s32 unk70, entryCount;
    SunsetEntry* entries;
    s32 unk7c, state, frame;
};

extern "C" {
extern const float lbl_25_rodata_0[];

void fn_25_C58(FnObj*, float, float, float, float);
void fn_25_13A8(void*, const FnObj*, const FnObj*, float);
void fn_25_B34(Sunset*, u32, float);
void* fn_25_C78(void*, int);
}

extern "C" void fn_25_11C(Sunset* arg0) {
    gfPadStatus sp30;
    FnObj sp1C;
    FnObj sp8;
    const float* rodata = lbl_25_rodata_0;

    g_gfPadSystem->getSysPadStatus(0xF0, &sp30);

    switch (arg0->state) {
    case 0:
        break;
    case 1:
        arg0->anim->value = 1;
        arg0->state = 2;
        arg0->frame = 0;
        break;
    case 2:
        if ((s32)arg0->timing->count <= arg0->frame) {
            arg0->state = 3;
            fn_25_C58(&sp1C, rodata[0], rodata[0], rodata[0], rodata[1]);
            fn_25_C58(&sp8, rodata[0], rodata[0], rodata[0], rodata[0]);
            fn_25_13A8(arg0->anim, &sp1C, &sp8, rodata[2]);
            fn_25_C78(&sp8, -1);
            fn_25_C78(&sp1C, -1);
        }
        break;
    case 3:
        break;
    }

    if ((u32)(arg0->state - 2) <= 1U) {
        float hi;
        float lo = rodata[0];
        hi = rodata[1];

        for (s32 i = 0; i < arg0->entryCount; ++i) {
            bool inRange = arg0->entries[i].inRange(arg0->frame);
            if (inRange == true) {
                if (arg0->entries[i].inStart(arg0->frame) == true) {
                    float v = arg0->entries[i].fa + arg0->entries[i].alpha;
                    if (v < lo) {
                        v = lo;
                    }
                    if (hi < v) {
                        v = hi;
                    }
                    fn_25_B34(arg0, i, v);
                }

                if (arg0->entries[i].inEnd(arg0->frame) == true) {
                    float v = arg0->entries[i].fb + arg0->entries[i].alpha;
                    if (v < lo) {
                        v = lo;
                    }
                    if (hi < v) {
                        v = hi;
                    }
                    fn_25_B34(arg0, i, v);
                }

                if (arg0->entries[i].flag == 0) {
                    g_gfSceneRoot->add(
                        gfSceneRoot::Layer_Info, arg0->models[i]->scn);
                    arg0->entries[i].flag = 1;
                }
            } else if (arg0->entries[i].flag == 1) {
                g_gfSceneRoot->remove(arg0->models[i]->scn);
                arg0->entries[i].flag = 0;
            }
        }
    }

    arg0->frame = arg0->frame + 1;
}
