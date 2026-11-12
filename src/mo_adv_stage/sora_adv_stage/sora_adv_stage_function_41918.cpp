#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <string.h>

#pragma force_active on

extern "C" {
int fn_800B5854(void*, int, int, int, int);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
int fn_800BA3D8(void*);
extern unsigned char lbl_40_rodata_9B0[];
}

struct Self {
    char _0[0x714];
    MuObject* obj;
    char _718[4];
    MuObject* entries[10];
    char _744[0x970 - 0x744];
    char pad[0x2b9];
    unsigned char flag;
};

extern "C" void fn_40_41918(Self* self) {
    fn_800B5854(self->obj, self->flag ? 0 : 2, 0x11, 1, 0);

    int i;
    MuObject* entry;
    char* p = (char*)self;
    for (i = 0; i < 10; i++, p += 4) {
        entry = *(MuObject**)(p + 0x71c);
        if (i == 0) {
            fn_801AAFF0(entry->m_scnMdl, 0x4c);
            fn_801AB014(entry->m_scnMdl, 0x4c);
        } else {
            fn_801AAFF0(entry->m_scnMdl, i + 0x43);
            fn_801AB014(entry->m_scnMdl, i + 0x43);
        }
    }

    if (self->flag) {
        gfPadStatus status;
        int index = fn_800BA3D8((char*)self + 0x970);
        if (index >= 0)
            g_gfPadSystem->getSysPadStatus(index, &status);
        else
            memset(&status, 0, sizeof(status));

        gfPadStatus copy = status;
        self->obj->setFrameTex((float)lbl_40_rodata_9B0[copy.m_controllerType]);
    }
}
