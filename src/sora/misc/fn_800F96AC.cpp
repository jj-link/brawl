#include <mu/mu_object.h>
#include <gf/gf_3d_scene.h>
#include <snd/snd_system.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B9F90(void* out, void* arg, int flag);
int fn_800B61C0(void* obj);
int fn_800F9A14(void* self);
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
extern const f32 lbl_805A2680;
}

struct Name {
    char s[65];
};

struct Self {
    char pad0[0x48];
    char pad48[0xA8];
    int state;
    char padF4[4];
    int sub;
    char padFC[4];
    union {
        u8 flags;
        struct {
            u8 bit7 : 1;
            u8 bit6 : 1;
            u8 rest : 6;
        } bits;
    };
    char pad101[0x264 - 0x101];
    nw4r::g3d::ScnMdl* scn;
    MuObject* obj;
};

extern "C" void fn_800F96AC(Self* self) {
    char padBuf[0x40];
    fn_800B9F90(padBuf, (char*)self + 0x48, 0);
    switch (self->state) {
    case 0x0:
        self->state = 0x12E;
        /* fallthrough */
    case 0x12E:
        self->state = 0x12F;
        break;
    case 0x12F:
        if ((self->flags >> 7) & 1) {
            g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->scn);
            MuObject* obj = self->obj;
            char* mdl = *(char**)((char*)obj + 8);
            int off = *(int*)(mdl + 0x3c);
            const char* src = off ? mdl + off : 0;
            Name n4;
            Name n3;
            Name n2;
            Name n1;
            n1.s[0] = 0;
            strcat(n1.s, src);
            n2 = n1;
            strcat(n2.s, lbl_8059E484);
            n3 = n2;
            sprintf(n3.s + strlen(n3.s), lbl_8059E480, 0);
            n4 = n3;
            obj->changeNodeAnimNIf(n4.s);
            switch (self->sub) {
            case 0:
                break;
            case 1:
                if ((self->flags >> 6) & 1) {
                    g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
                }
                /* fallthrough */
            case 2:
                self->flags &= ~0x40;
                self->obj->setFrameMatCol(lbl_805A2680);
                break;
            }
            self->state = 0x137;
        }
        break;
    case 0x137:
        if (fn_800B61C0(self->obj)) {
            self->state = 0x13D;
        }
        break;
    case 0x13D:
        if (fn_800F9A14(self)) {
            MuObject* obj = self->obj;
            char* mdl = *(char**)((char*)obj + 8);
            int off = *(int*)(mdl + 0x3c);
            const char* src = off ? mdl + off : 0;
            Name n4;
            Name n3;
            Name n2;
            Name n1;
            n1.s[0] = 0;
            strcat(n1.s, src);
            n2 = n1;
            strcat(n2.s, lbl_8059E484);
            n3 = n2;
            sprintf(n3.s + strlen(n3.s), lbl_8059E480, 1);
            n4 = n3;
            obj->changeNodeAnimNIf(n4.s);
            self->state = 0x144;
        }
        break;
    case 0x144:
        if (fn_800B61C0(self->obj)) {
            self->bits.bit7 = 0;
            g_gfSceneRoot->remove(self->scn);
            self->state = 0x12F;
        }
        break;
    }
}
