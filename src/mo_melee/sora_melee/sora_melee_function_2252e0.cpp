struct Vec3f { float x, y, z; };
#include <st/se_util.h>
#include <snd/snd_id.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" {
extern void* g_sndSystem;
extern const float lbl_27_rodata_33D8;
s32 fn_800754E8(void*, SndID, s32, s32);
void fn_8007798C(void*, s32, float);
void fn_80075C8C(void*, s32, s32, s32);
void fn_80075F1C(void*, s32, s32);
}

static inline bool crossed(float p, float x, float frame) {
    if (p <= frame) {
        int r = (p < x && x <= frame);
        return r != 0;
    } else {
        int r = (p < x || x <= frame);
        return r != 0;
    }
}

static inline void playLoop(SndID id, s32& handle, float pan) {
    if (handle == -1) {
        s32 h = fn_800754E8(g_sndSystem, id, -1, -1);
        handle = h;
        if (h != -1) {
            fn_8007798C(g_sndSystem, h, pan);
            fn_80075C8C(g_sndSystem, handle, 0, 0);
        }
    } else {
        fn_8007798C(g_sndSystem, handle, pan);
    }
}

static inline u32 eventFlag(float p, float x, float y, float frame) {
    u32 flag;
    if (lbl_27_rodata_33D8 == y) {
        flag = crossed(p, x, frame);
    } else if (p <= frame) {
        int r = (p < x && x <= frame) || (p < y && y <= frame) ||
            (x < p && p < y) || (x <= frame && frame <= y);
        flag = 0;
        if (r != 0) flag = 2;
    } else {
        int r = (x < p && p < y) || (x <= frame && frame <= y);
        flag = 0;
        if (r != 0) flag = 2;
    }
    return flag;
}

namespace StSeUtil {
void SeSeq::playFrame(s32 arg0, float arg1) {
    s32 h;
    UnkStruct3* e;
    size_t soundIndex;
    UnkStruct2* s;
    UnkStruct* ev;
    size_t count;
    size_t j;
    u32 idx;

    for (size_t i = 0; i < unk10; i++) {
        unkC[i].unk8 = 0;
    }

    if (unk1C != arg1 && arg0 >= 0 && (size_t)arg0 < unk8) {
        s = &unk4[arg0];
        if (s->unk8 != NULL) {
            count = s->unk4;
            ev = s->unk0;
            for (j = 0; j < count; j++) {
                idx = (u32)s->unk8[j];
                if (idx != 0xFFFFFFFFU) {
                    u32 flag = eventFlag(unk1C, ev->unk8, ev->unkC, arg1);
                    if (flag != 0) {
                        unkC[idx].unk8 |= flag;
                        unkC[idx].unkC = ev;
                    }
                }
                ev++;
            }
        }
    }

    e = unkC;
    for (soundIndex = 0; soundIndex < unk10; e++, soundIndex++) {
        if (e->unk4 != -1) {
            if (e->unk8 == 0) {
                if (m_sndGenerator != NULL) {
                    m_sndGenerator->stopSE(e->unk4, 0x14);
                    e->unk4 = -1;
                } else if (e->unk4 != -1) {
                    fn_80075F1C(g_sndSystem, e->unk4, 0x14);
                    e->unk4 = -1;
                }
            }
        } else if (e->unk8 & 2) {
            if (m_sndGenerator != NULL) {
                e->unk4 = m_sndGenerator->playSE(e->id, -1, 0, -1);
            } else {
                playLoop(e->id, e->unk4, e->unkC->unk4);
            }
        } else if (e->unk8 & 1) {
            if (m_sndGenerator != NULL) {
                m_sndGenerator->playSE(e->id, -1, 0, -1);
            } else {
                float pan = e->unkC->unk4;
                h = fn_800754E8(g_sndSystem, e->id, -1, -1);
                if (h != -1) {
                    fn_8007798C(g_sndSystem, h, pan);
                    fn_80075C8C(g_sndSystem, h, 0, 0);
                }
            }
        }
    }

    unk1C = arg1;
}
}
