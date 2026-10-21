#pragma force_active on
extern "C" {
typedef int (*fn_ptr_t)(void*);

struct StateEntry {
    void (*enter)(void*);
    fn_ptr_t update;
};

extern StateEntry lbl_16_rodata_60[];
extern void* g_gfPadSystem;

void fn_800B9984(void* arg);
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, int port, void* status);

struct Menu {
    char pad0[0x9C];
    int state;
    int last;
    char pad1[0x478 - 0xA4];
    int port;
};

void fn_16_321C(Menu* self) {
    signed char status[0x40];
    int cur;

    fn_800B9984((char*)self + 0xAC);
    if (self->port >= 0) {
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, self->port, status);
        if (status[0x38]) {
            self->port = -1;
        }
    }
    cur = self->state;
    if (self->last != cur) {
        if (lbl_16_rodata_60[cur].enter) {
            lbl_16_rodata_60[cur].enter(self);
        }
        self->last = self->state;
    }
    if (lbl_16_rodata_60[self->state].update) {
        self->state = lbl_16_rodata_60[self->state].update(self);
    }
}
}
