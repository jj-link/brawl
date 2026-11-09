#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" int fn_800BA3D8(void*);
extern "C" void fn_80016900(void*, int, int);
extern "C" void OSReport(const char*, ...);

extern void* g_gfApplication;
extern sndSystem* g_sndSystem;
extern char lbl_8045D250[];
extern char lbl_8045D2A4[];
extern float lbl_805A2858;

class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual float slot6();
};

struct Mid {
    char pad[0xC];
    VObj* v;
};

struct Self {
    char pad0[0x8];
    int entries[3];
    int count;
    int index;
    char pad1[0x10];
    int flags2c;
    u32 flags30;
    char pad2[0xB4];
    MuObject* obj;
    char pad3[0x54];
    int counter;
    u8 f144;
    char pad4[2];
    u8 f147;
};

extern "C" int fn_8010A36C(Self* self, int* out) {
    gfPadStatus status;
    u32 flags = self->flags30;
    int old;
    int idx;
    MuObject* obj;

    g_gfPadSystem->getSysPadStatus(fn_800BA3D8((char*)self + 0x20), &status);

    old = self->index;
    if ((flags & 1) && old > 0) {
        if (self->f144 != 0) {
            self->index = self->index - 1;
        } else if (self->index == 0 || self->index == 2) {
            self->index = self->index - 2;
        }
    }
    if (flags & 2) {
        idx = self->index;
        if (idx < self->count - 1) {
            if (self->f144 != 0) {
                self->index = idx + 1;
            } else if (idx == 0 || idx == 2) {
                self->index = self->index + 2;
            }
        }
    }
    if (old != self->index) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
    obj = self->obj;
    self->counter = self->counter + 1;
    if (self->counter == 30) {
        self->counter = 0;
    }
    obj->changeClrAnimNIf(lbl_8045D250);
    obj->setFrameMatCol((f32)self->counter);
    obj->setFrameVisible((f32)self->index);
    if (((u32*)&status)[3] & 0x100) {
        *out = self->entries[self->index];
        return 1;
    }
    {
        VObj* v = ((Mid*)*(char**)((char*)obj + 0x14))->v;
        if (lbl_805A2858 == v->slot6()) {
            u32 f = self->flags2c;
            if ((f & 0x200) || (f & 0x1000)) {
                OSReport(lbl_8045D2A4);
                self->f147 = 1;
                fn_80016900(g_gfApplication, 0, 0);
                return 2;
            }
        }
    }
    return 0;
}
