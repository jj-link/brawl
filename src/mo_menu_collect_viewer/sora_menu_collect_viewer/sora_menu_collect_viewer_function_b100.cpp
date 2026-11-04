#pragma force_active on
#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>

extern "C" {
extern gfPadSystem* g_gfPadSystem;
extern sndSystem* g_sndSystem;
extern const float lbl_6_rodata_6E8;
extern const double lbl_6_rodata_7D8;

int getSysPadStatus__11gfPadSystemFiP11gfPadStatus(gfPadSystem*, int, gfPadStatus*);
void setFrameNode__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
int playSE__9sndSystemF5SndIDiiii(sndSystem*, int, int, int, int, int);
int fn_800BA2E0();
int fn_8006CEEC(void*, int);

struct Menu {
    char pad0[0x44];
    void* object;
    char pad48[0x48];
    u32 buttons;
    char pad94[0x94];
    int state;
    char pad12c[8];
    int row;
    int column;
    int accepted;
    char pad140[0x121];
    u8 mode;
};

int fn_6_B100(Menu* self) {
    gfPadStatus status;
    int action = 0;
    int row = self->row;
    int column = self->column;
    u32 buttons = self->buttons;

    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &status);

    if (buttons & 8) {
        if (--row < 0)
            row = 0;
    }
    if (buttons & 4) {
        if (++row >= 3)
            row = 2;
    }
    if (row == 2) {
        if (buttons & 1) {
            if (--column < 0)
                column = 0;
        }
        if (buttons & 2) {
            if (++column >= 2)
                column = 1;
        }
    }

    if (row != self->row || column != self->column) {
        self->row = row;
        self->column = column;
        void* object = self->object;
        float frame = lbl_6_rodata_6E8 + row;
        if (row == 2)
            frame += column;
        setFrameNode__8MuObjectFf(object, frame);
        setFrameVisible__8MuObjectFf(object, frame);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
    }

    if (status.m_buttonsPressedThisFrame.bits & 0x100) {
        self->accepted = fn_800BA2E0();
        switch (row) {
        case 0:
            action = 1;
            break;
        case 1:
            action = 2;
            break;
        case 2:
            action = 4;
            if (column == 0)
                action = 3;
            break;
        }
    }
    if (status.m_buttonsPressedThisFrame.bits & 0x200)
        action = 4;

    int state;
    switch (action) {
    case 1:
        self->mode = 0;
        state = 2;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        break;
    case 2:
        self->mode = 1;
        state = 2;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        break;
    case 3:
        if (fn_8006CEEC((char*)self + 0x164, 0x7FFF) > 0 &&
            fn_8006CEEC((char*)self + 0x179, 0x7FFF) > 0) {
            state = 6;
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
        } else {
            state = 5;
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 3, -1, 0, 0, -1);
        }
        break;
    case 4:
        state = 10;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        break;
    default:
        state = self->state;
        break;
    }
    return state;
}
}
