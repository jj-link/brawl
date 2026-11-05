#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_12_588(void* self, int value);
}

struct Self {
    char _0[0x44];
    int m_result;              // 0x44
    char _48[0x34];
    int m_flags;               // 0x7C
    char _80[0xA4];
    unsigned char m_state;     // 0x124
};

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

extern "C" int fn_12_A50(Self* self) {
    int flags = self->m_flags;
    
    if ((flags & 2) && self->m_state != 0) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_12_588(self, 2);
        self->m_state = 0;
    }
    if ((flags & 1) && self->m_state == 0) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_12_588(self, 1);
        self->m_state = 1;
    }
    
    gfPadStatus status = getSysPad();
    
    if (status.m_buttonsPressedThisFrame.bits & 0x1100) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        int ret = 4;
        if (self->m_state != 0) ret = 3;
        return ret;
    }
    return self->m_result;
}