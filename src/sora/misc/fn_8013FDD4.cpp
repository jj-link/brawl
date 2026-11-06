#include <types.h>
#include <revolution/OS/OSTime.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_8059E742;
extern unsigned char* lbl_805A0434;
extern const float lbl_805A2B10;
extern const float lbl_805A2AC8;
unsigned char fn_800CB194(muWifiInterfaceTask*, int);
int fn_800CB0D8(muWifiInterfaceTask*, int);
int fn_800CB354(muWifiInterfaceTask*, int);
}

struct Entry {
    signed char active;
    char b1, b2, b3;
    short b4;
    char pad6[2];
    float b8, bc;
    char pad10[8];
    unsigned int tick;
    char pad1c[4];
};
struct State {
    char pad0[0x11];
    unsigned char count, mask;
    char pad13[0x9d];
    Entry entries[4];
    char pad130[0x69];
    unsigned char n;
    unsigned char ids[3];
    unsigned char ranks[4];
    unsigned char order[4];
    char pad1a5[0x17];
    char flag;
    char pad1bd[0x13];
    int value;
    int mode;
};

extern "C" int fn_8013FDD4(State* self) {
    unsigned int offset;
    Entry* e;
    unsigned char bits;
    signed char* active;
    unsigned int i;
    self->flag = 0;
    self->count = 0;
    bits = lbl_805A0434[0x34a9];
    active = &self->entries[0].active;
    for (i = 0; i < 4; ++i) {
        offset = (unsigned char)i * 32;
        e = (Entry*)((char*)self + offset + 0xb0);
        e->active = 0;
        e->b4 = 0;
        e->b1 = 0;
        e->b3 = 0;
        e->b2 = 0;
        e->tick = OSGetTick();
        e->b8 = lbl_805A2B10;
        e->bc = lbl_805A2AC8;
        if (bits & (1 << (unsigned char)i)) {
            self->count++;
            active[offset] = 1;
        }
    }
    self->count = 0;
    self->mask = 0;
    for (unsigned char i = 0; i < 4; i++) {
        if (self->entries[i].active) {
            self->mask |= 1 << i;
            self->count++;
        }
    }
    muWifiInterfaceTask* wifi = g_muWifiInterfaceTask;
    self->n = 0;
    memset(self->ids, 0, 3);
    memset(self->ranks, 0xff, 4);
    for (int i = 0; i < 4; i++) {
        if (lbl_8059E742 == fn_800CB194(wifi, i) && fn_800CB0D8(wifi, i) == 0) {
            self->ids[self->n] = i;
            self->ranks[self->n] = fn_800CB354(wifi, i) - 1;
            self->n++;
        }
    }
    memset(self->order, 0xff, 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < self->n; j++) {
            if (self->ranks[j] == i) self->order[i] = j;
        }
    }
    self->mode = 0x13;
    self->value = 0;
    lbl_805A0434[0x33ce] = 1;
    return 1;
}