#include <gf/gf_pad_system.h>
#pragma force_active on

extern "C" void fn_800307B4(void*);
extern "C" void fn_800C753C();
extern "C" int fn_800BA2E0();
extern int g_muWifiInterfaceTask;

struct Pending {
    char pad[0xF0];
    int state;
};

struct Menu {
    char pad0[0x40];
    int mode;
    char pad44[0x128 - 0x44];
    int selection;
    char pad12C[0x134 - 0x12C];
    unsigned char flag;
    char pad135[3];
    int state;
    char pad13C[4];
    int timer;
    char pad144[0x1DC - 0x144];
    int accepted;
    char pad1E0[0x1EC - 0x1E0];
    Pending* pending;
    unsigned char flag1F0;
    int update();
};

inline int Menu::update() {
    gfPadStatus pad;
    int expired = 0;
    Menu* self = this;
    int notify = 0;
    int ready;
    if (self->selection == 0 && self->flag == 0 && self->flag1F0 == 0) {
        if (--self->timer <= 0) {
            expired = 1;
        }
    }
    g_gfPadSystem->getSysPadStatus(0xF0, &pad);
    if (self->mode == 1) {
        Pending* pending = self->pending;
        if (pending == 0) {
            ready = 1;
        } else if (pending->state == 0) {
            fn_800307B4(pending);
            ready = 1;
            self->pending = 0;
        } else {
            ready = 0;
        }
        if (ready != 0) {
            notify = 1;
        }
    } else {
        ready = 1;
        if ((unsigned int)(self->selection - 1) <= 1) {
            notify = 1;
        }
    }
    if (notify != 0 && g_muWifiInterfaceTask != 0) {
        fn_800C753C();
    }
    if (((pad.m_buttonsPressedThisFrame.bits & 0x1100) || expired != 0) && ready != 0) {
        if (self->selection == 0 && self->flag != 0) {
            self->accepted = fn_800BA2E0();
            return 7;
        }
        return 10;
    }
    return self->state;
}

extern "C" int fn_2_39A28(Menu* self) {
    return self->update();
}
