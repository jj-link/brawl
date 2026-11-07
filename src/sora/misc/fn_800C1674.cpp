#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_80073F84(sndSystem*, int);
extern const float lbl_805A22F4;
extern const float lbl_805A22F8;

struct Entry {
    int kind;
    int unused;
    int bgm;
    unsigned char enabled;
    char pad[3];
};
struct Menu {
    char pad0[0x40];
    MuObject* object;
    char pad44[0x28];
    unsigned int direction;
    char pad70[0x98];
    unsigned char selected;
    char pad109[3];
    int fallback;
    char pad110[4];
    int delay;
    int timer;
    Entry entries[16];
    char pad21c[4];
    int index;
    char pad224[0x1a8];
    int bgm;
    unsigned char force;
};

extern "C" int fn_800C1674(Menu* self) {
    int allow = 1;
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xf0, &status);
    if (self->delay < 0)
        return self->fallback;
    if (++self->timer < self->delay)
        return self->fallback;
    Entry* entry = &self->entries[self->index];
    if (entry->kind == 2 && entry->enabled) {
        unsigned int direction = self->direction;
        unsigned int oldSelected = self->selected;
        unsigned int selected = oldSelected;
        if (direction & 1)
            selected = 1;
        if (direction & 2)
            selected = 0;
        if (selected != oldSelected) {
            self->object->setFrameMatCol(selected ? lbl_805A22F4 : lbl_805A22F8);
            self->selected = selected;
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        }
        allow = self->selected == 0;
    }
    unsigned int buttons = status.m_buttonsPressedThisFrame.bits;
    if ((buttons & 0x100) || (buttons & 0x1000) || self->force) {
        if (allow || self->force) {
            if (self->bgm != g_sndSystem->getBGMId())
                fn_80073F84(g_sndSystem, 0);
            return 4;
        }
        fn_80073F84(g_sndSystem, 0);
        g_sndSystem->playBGM(entry->bgm, 0, true);
    }
    return self->fallback;
}