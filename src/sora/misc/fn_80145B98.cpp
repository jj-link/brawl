#include <types.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <nt/nt_send.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void* fn_800D9CB0(void* arg0);
extern "C" unsigned char lbl_8059E742;
extern "C" unsigned char lbl_8059E745;
extern "C" char lbl_8045EE64[];

struct NtRecv {
    char pad0[0x18];
    int state;
    unsigned int mask;
    void* buf;
    char pad24[0xC];
    unsigned int tick;
};

struct WifiEntry {
    char pad0[0xE8];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

extern "C" int fn_80145B98(NtRecv* self, unsigned int arg1) {
    unsigned char idx;
    unsigned char other;
    unsigned int flag;
    unsigned int task;
    unsigned int i;

    if (self->buf == 0) {
        netReport__FPCce(lbl_8045EE64);
        return 0;
    }
    if (arg1 == 0xFF) {
        return 0;
    }
    idx = lbl_8059E742;
    if (idx >= 4) {
        return 0;
    }
    other = lbl_8059E745;
    flag = 0;
    task = (unsigned int)g_muWifiInterfaceTask;
    if (idx == other && idx != 0xFF) {
        flag = 1;
    }
    ((WifiEntry*)(task + idx * 0x218))->flag = flag;
    if (arg1 == 0xFE) {
        self->mask |= g_NtAIDBitmap;
    } else if (arg1 == 0xFD) {
        i = 0;
        do {
            int valid;
            if ((unsigned char)i >= 4) {
                valid = 0;
            } else {
                valid = !(((unsigned char*)fn_800D9CB0((void*)task))[(unsigned char)i + 0x68] - 1);
            }
            if (valid) {
                self->mask |= (1u << (unsigned char)i);
            }
            i++;
        } while (i < 4);
    } else {
        self->mask |= g_NtAIDBitmap & (1 << arg1);
    }
    self->mask &= ~(1 << lbl_8059E742);
    self->state = 1;
    self->tick = OSGetTick();
    return 1;
}
