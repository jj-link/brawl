#pragma force_active on
#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>

extern "C" {
extern gfPadSystem* g_gfPadSystem;
extern sndSystem* g_sndSystem;
extern const float lbl_6_rodata_5D8;
extern const float lbl_6_rodata_690;

int getSysPadStatus__11gfPadSystemFiP11gfPadStatus(gfPadSystem*, int, gfPadStatus*);
void setFrameNode__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
int playSE__9sndSystemF5SndIDiiii(sndSystem*, int, int, int, int, int);

struct Menu {
    char pad0[0x64];
    void* object;                        /* 0x64 */
    char pad68[0x8c - 0x68];
    u32 buttons;                         /* 0x8c */
    char pad90[0x72c - 0x90];
    int count;                           /* 0x72c */
    char pad730[0x744 - 0x730];
    int frameBase;                       /* 0x744 */
    int row;                             /* 0x748 */
    int col;                             /* 0x74c */
};

int fn_6_93B0(Menu* self) {
    gfPadStatus status;
    int row = self->row;
    int col = self->col;
    int action = 0;
    u32 buttons = self->buttons;

    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &status);

    if (buttons & 8) {
        if (--col < 0)
            col = 0;
        int c = 0;
        char* p = (char*)self;
        for (int i = 0; i < self->count; i++) {
            if (*(unsigned char*)(p + 0x142) != 0)
                c++;
            p += 0x18;
        }
        if (c <= 0)
            col = 1;
    }
    if (buttons & 4) {
        if (++col >= 2)
            col = 1;
    }
    if (buttons & 1) {
        row = 0;
        if (self->count <= 0)
            row = 1;
    }
    u32 pressed = status.m_buttonsPressedThisFrame.bits;
    if (pressed & 0x100) {
        if (col == 0)
            action = 1;
        if (col == 1)
            action = 2;
    }
    if (pressed & 0x200) {
        action = 2;
    }
    if (row != self->row || col != self->col) {
        int base = self->frameBase;
        void* object = self->object;
        float frame;
        if (row == 0) {
            frame = lbl_6_rodata_5D8 + (float)base;
        } else {
            frame = lbl_6_rodata_690 + (float)col;
        }
        setFrameNode__8MuObjectFf(object, frame);
        setFrameVisible__8MuObjectFf(object, frame);
        self->row = row;
        self->col = col;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
    }
    switch (action) {
    case 1:
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
        break;
    case 2:
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        break;
    }
    return action;
}
}
