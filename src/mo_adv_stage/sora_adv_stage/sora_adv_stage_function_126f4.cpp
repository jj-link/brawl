#include <gm/gm_global.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct AdvStageDataView {
    unsigned char pad0[0x5FD];
    unsigned char current;
    unsigned char pad1[0x4916 - 0x5FE];
    unsigned char previous;
};
struct Params {
    char pad0[0x48];
    float chance;
    char pad4c[0x19];
    unsigned char minimum;
    unsigned char count;
};
struct Slot {
    unsigned char active;
    char pad[0xb];
    int state;
    char pad10[0xc];
};
struct Self {
    char pad[0x90];
    Params* params;
    Slot* slots;
    char pad98[0x10];
    float time;
    int count;
    unsigned char started;
};
struct List {
    char pad[0x188];
    int capacity;
    int count;
};
extern "C" {
extern List* lbl_27_bss_5B98;
extern char lbl_40_data_2984[];
extern const float lbl_40_rodata_1B0;
void fn_40_B48(const char*, ...);
}

inline int findSlot(Self* self, Params* params) {
    for (int slot = 0; slot < params->count; slot++) {
        if (self->slots[slot].active == 0) return slot;
    }
    return -1;
}

inline int getSlot(Self* self, Params* params) {
    if (lbl_27_bss_5B98 && lbl_27_bss_5B98->count >= lbl_27_bss_5B98->capacity) {
        fn_40_B48(lbl_40_data_2984);
        return -1;
    }
    return findSlot(self, params);
}

extern "C" void fn_40_126F4(Self* self) {
    Params* params = self->params;
    if (randf() < params->chance) {
        AdvStageDataView* data = (AdvStageDataView*)g_GameGlobal->m_advData;
        unsigned char current = data->current;
        unsigned char previous = data->previous;
        int value = current - previous;
        int lower = current - 5;
        if (value < lower) value = lower;
        if (value < 0) value = 0;
        if (value > 14) value = 14;
        if ((unsigned char)value >= params->minimum - 1 && self->started) {
            int slot = getSlot(self, params);
            if (slot >= 0) {
                self->slots[slot].active = 1;
                self->slots[slot].state = 1;
                self->started = 0;
                self->count++;
                self->time = lbl_40_rodata_1B0;
            }
        }
    }
}
