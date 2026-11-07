#include <mu/mu_object.h>
#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
int fn_800B61C0(void*);
void fn_8019D950(void*);
extern char lbl_33_data_3E0[];
extern char lbl_33_data_3E4[];
}

struct Name { char s[65]; };
struct Self {
    char pad0[0x110];
    int input;
    char pad114[0x1ac-0x114];
    int done;
    int pad;
    int selection;
    char pad1b8[0x1d0-0x1b8];
    MuObject* obj;
    char pad1d4[4];
    int state;
};

extern "C" void fn_33_31D0(Self* self) {
    switch (self->state) {
    case 0:
        self->state = 0xc9;
    case 0xc9:
        if (fn_800B61C0(self->obj)) self->state = 0xcf;
        break;
    case 0xcf:
        self->state = 0xd0;
        break;
    case 0xd0: {
        int input = self->input;
        int selection = self->selection;
        if ((input & 1) && selection != 0) selection = 0;
        if ((input & 2) && selection < 1) selection = 1;
        if (selection != *(int*)((char*)self + 0x1b4)) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            self->obj->setFrameMatCol((float)(int)(selection != 0));
            self->selection = selection;
        }
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(self->pad, &status);
        if (status.m_buttonsPressedThisFrame.bits & 0x100) {
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        } else if (status.m_buttonsPressedThisFrame.bits & 0x200) {
            self->selection = 1;
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        } else {
            return;
        }
        MuObject* obj = self->obj;
        char* mdl = *(char**)((char*)obj + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* src = off ? mdl + off : 0;
        Name n1;
        Name n2;
        Name n3;
        Name n4;
        n1.s[0] = 0;
        strcat(n1.s, src);
        n2 = n1;
        strcat(n2.s, lbl_33_data_3E4);
        n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_33_data_3E0, 1);
        n4 = n3;
        obj->changeNodeAnimNIf(n4.s);
        self->state = 0x102;
        break;
    }
    case 0x102:
        if (fn_800B61C0(self->obj)) {
            self->done = 1;
            fn_8019D950(self->obj->m_sceneModel);
            self->state = 0x10b;
        }
        break;
    case 0x10b:
        break;
    }
}
