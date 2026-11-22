#include <gm/gm_global.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>
#include <ms/ms_message.h>
#pragma force_active on

struct TargetData { char pad[0x5c8]; unsigned char f5c8; };
struct SelCharSelf {
    char pad[0x1b0]; int f1b0; int f1b4; char p1b8[8]; int f1c0;
    char p1c4[4]; int f1c8; char p1cc[12]; int f1d8; int f1dc;
    char p1e0[0x14]; TargetData* f1f4; char p1f8[0x178]; char nameEntry[0x90]; int f400;
};

extern "C" {
int fn_16_998(void*, gfPadStatus*, char*, int, int);
void fn_16_AF8(void*);
int fn_16_1A70(const char*);
int fn_8004D148(void*);
int fn_8004D808(void*, const char*);
void fn_8004D334(void*, int, const void*, int);
void fn_8004D674(void*, int, short*);
void fn_800D3184(void*, int, short*, int);
void fn_10_18908(void*, int, int, int, int);
void fn_10_14F38(void*, int, int);
extern void* g_muWifiInterfaceTask;
}

static inline void copyPad(gfPadStatus& d, const gfPadStatus& s) {
 d.m_buttonsCurrentFrame = s.m_buttonsCurrentFrame;
 d.m_buttonsCurrentFrame2 = s.m_buttonsCurrentFrame2;
 d.m_buttonsHeld = s.m_buttonsHeld;
 d.m_buttonsPressedThisFrame = s.m_buttonsPressedThisFrame;
 d.m_buttonsReleasedThisFrame = s.m_buttonsReleasedThisFrame;
 d.m_buttonsPressedThisFrame2 = s.m_buttonsPressedThisFrame2;
 d._0x18 = s._0x18; d._0x1c = s._0x1c; d._0x20 = s._0x20;
 d._0x24 = s._0x24; d._0x28 = s._0x28; d._0x2c = s._0x2c;
 d.m_stickX = s.m_stickX; d.m_stickY = s.m_stickY;
 d.m_subStickX = s.m_subStickX; d.m_subStickY = s.m_subStickY;
 d.m_lTriggerAnalog = s.m_lTriggerAnalog; d.m_rTriggerAnalog = s.m_rTriggerAnalog;
 d._0x36 = s._0x36; d._0x37 = s._0x37; d.m_error = s.m_error;
 d.m_controllerType = s.m_controllerType;
}

static inline int addName(const char* name, int arg, wchar_t* wide) {
    void* global = g_GameGlobal;
    if (fn_16_1A70(name) == 0) return -1;
    int index = fn_8004D148(global);
    if (index >= 0x78) return -1;
    if (fn_8004D808(global, name) >= 0) return -1;
    Message::utf8to16(wide, name);
    fn_8004D334(global, index, wide, arg);
    return index;
}

extern "C" int fn_10_18E38(void* arg0, int arg1, const gfPadStatus* arg2, const gfPadStatus* arg3) {
    SelCharSelf* self = (SelCharSelf*)arg0;
    gfPadStatus status;
    copyPad(status, *arg2);
    status.m_buttonsCurrentFrame2 = arg3->m_buttonsHeld;
    status.m_buttonsPressedThisFrame = arg3->m_buttonsPressedThisFrame;
    status.m_buttonsPressedThisFrame2 = arg3->m_buttonsReleasedThisFrame;
    char name[24];
    int result = 0;
    self->f400 = self->f1dc;
    switch (fn_16_998(self->nameEntry, &status, name, 0, 1)) {
    case 0: {
        wchar_t wide[6];
        int index = addName(name, arg1, wide);
        if (index >= 0) {
            fn_10_18908(arg0, index, self->f1b4, self->f1f4->f5c8, self->f1c0);
            self->f1c8 = index;
            void* task = g_muWifiInterfaceTask;
            if (task != 0) {
                short text[6];
                int r;
                int kind = 0;
                if (index < 0) goto clear;
                {
                    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
                    if (state >= 0 && state < 4) kind = 1; else kind = 0;
                    if (kind != 0) kind = 0;
                    else {
                        if (state >= 4 && state < 0xc) kind = 1; else kind = 0;
                        if (kind != 0) kind = 1;
                        else {
                            if (state >= 0xc && state < 0x10) r = 1; else r = 0;
                            kind = 3;
                            if (r != 0) kind = 2;
                        }
                    }
                }
                if (kind == 2) fn_8004D674(g_GameGlobal, index, text);
                else goto clear;
                goto done;
clear:
                text[0] = 0;
done:
                int slot = self->f1b0;
                fn_800D3184(task, slot, text, index >= 0 ? index & 0xff : 0x78);
            }
            self->f1d8 = 0;
            fn_10_14F38(arg0, 0, self->f1b4);
            result = 1;
        } else {
            g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
        }
        break;
    }
    case 1: result = 1; break;
    case 2: break;
    }
    if (result != 0) fn_16_AF8(self->nameEntry);
    return result;
}
