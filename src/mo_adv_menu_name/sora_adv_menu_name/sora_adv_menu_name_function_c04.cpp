#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>
#include <types.h>
#pragma force_active on

struct Entry {
    char pad0[0x10];
    int buttons;
    char pad14[0x98];
    int busy;
    int flag220;
    int flag224;
};
struct Menu {
    char pad0[0x48];
    int choice;
    int choice2;
    int state[2];
    int result[2];
    char pad60[0xa8];
    int delay;
    int cursor[2];
    int scroll[2];
    int count;
    char pad120[4];
    unsigned char joined;
    char pad125[0x27];
    void* obj14c;
    void* obj150;
    char pad154[0x14];
    int mode;
    char pad16c[4];
    Entry entries[2];
    int other;
    char pad2e4[0x65];
    unsigned char enabled;
};
extern "C" {
int fn_800BA3D8(void*);
int fn_800B61C0(void*);
void fn_800B96E8(void*, unsigned char);
void fn_28_870(Menu*, int);
void fn_28_13A8(Menu*, int, unsigned int, gfPadStatus);
}
extern "C" void fn_28_C04(Menu* self) {
    int buttons[2] = {0, 0};
    gfPadStatus status[2] = {};
    int cursor[2] = {0, 0};

    if (self->delay > 0 && --self->delay > 0)
        return;

    for (int i = 0; i < 2; ++i) {
        if (i != 1 || self->joined) {
            buttons[i] = self->entries[i].buttons;
            int port = fn_800BA3D8(&self->entries[i]);
            g_gfPadSystem->getSysPadStatus(port, &status[i]);
        } else {
            buttons[i] = 0;
            status[i].init();
        }
        if (self->mode == 1) {
            if (((buttons[i] & 8) || (buttons[i] & 1)) && self->choice2 != 0) {
                self->choice2 = 0;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            if (((buttons[i] & 4) || (buttons[i] & 2)) && self->choice2 != 1) {
                self->choice2 = 1;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            if (fn_800B61C0(self->obj150)) {
                if (status[i].m_buttonsPressedThisFrame.bits & 0x100) {
                    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                    self->entries[i].flag224 = 1;
                    self->state[i] = 0;
                }
                if (status[i].m_buttonsPressedThisFrame.bits & 0x200) {
                    g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                    self->entries[i].flag224 = 1;
                    self->state[i] = 2;
                }
            }
        }
        if (self->mode == 3) {
            cursor[i] = self->cursor[i];
            if (self->entries[i].busy == 0) {
                int found = -1;
                for (int j = 0; j < 8; ++j) {
                    if (j != fn_800BA3D8(&self->entries[0])) {
                        gfPadStatus tmp;
                        g_gfPadSystem->getSysPadStatus(j, &tmp);
                        if (tmp.m_buttonsPressedThisFrame.bits & 0x1000)
                            found = j;
                    }
                }
                if (found >= 0 && !self->joined) {
                    fn_800B96E8(&self->entries[1], (unsigned char)found);
                    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                    self->joined = 1;
                    self->mode = 2;
                }
                if (!self->joined && i == 1)
                    return;
                if (buttons[i] & 8) {
                    if (cursor[i] > 0) {
                        --cursor[i];
                        if (i == 0) self->other = 1;
                        else if (i == 1) self->other = 0;
                    }
                    if (self->cursor[i] == 0 && self->scroll[i] > 0) {
                        --self->scroll[i];
                        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                    }
                }
                if (buttons[i] & 4) {
                    if (!self->joined && i == 1)
                        return;
                    int limit = self->count < 4 ? self->count : 4;
                    if (cursor[i] < limit) {
                        ++cursor[i];
                        if (i == 0) self->other = 1;
                        else if (i == 1) self->other = 0;
                    }
                    if (limit == self->cursor[i] && self->scroll[i] < self->count - 4) {
                        ++self->scroll[i];
                        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                    }
                }
                if (self->enabled)
                    fn_28_870(self, i);
                if (cursor[i] != self->cursor[i]) {
                    g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                    self->cursor[i] = cursor[i];
                }
                if (status[i].m_buttonsPressedThisFrame.bits & 0x100) {
                    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                    self->state[i] = 0;
                    self->result[i] = 0;
                    self->entries[i].busy = 1;
                }
                if (status[i].m_buttonsPressedThisFrame.bits & 0x200) {
                    if (!self->joined) {
                        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                        self->state[0] = 2;
                        self->entries[0].busy = 1;
                    } else if (i == 1) {
                        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                        self->state[1] = 2;
                        self->entries[1].busy = 1;
                    }
                }
            }
            if (self->entries[i].busy == 3 && (status[i].m_buttonsPressedThisFrame.bits & 0x200)) {
                g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                self->entries[i].busy = 1;
                self->state[i] = 1;
                self->result[i] = 2;
            }
        }
        if (self->mode == 4) {
            if (i == 1) return;
            if ((buttons[i] & 1) && self->choice != 0) {
                self->choice = 0;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            if ((buttons[i] & 2) && self->choice != 1) {
                self->choice = 1;
                g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            }
            if (fn_800B61C0(self->obj14c)) {
                if (status[i].m_buttonsPressedThisFrame.bits & 0x100) {
                    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                    self->entries[i].flag220 = 1;
                    if (self->choice == 0) self->state[i] = 0;
                    else self->state[i] = 2;
                }
                if (status[i].m_buttonsPressedThisFrame.bits & 0x200) {
                    g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
                    self->entries[i].flag220 = 1;
                    self->state[i] = 2;
                }
            }
        }
        if (self->mode == 6) {
            if (i == 1) return;
            fn_28_13A8(self, 0, buttons[0], status[0]);
        }
        if (self->mode == 7)
            fn_28_13A8(self, 1, buttons[1], status[1]);
    }
}
