#pragma force_active on
typedef unsigned int u32;

struct PadStatus {
    u32 words[16];
};

struct Menu {
    unsigned char pad[0x1DC];
    int port;
};

extern "C" {
extern void* g_gfPadSystem;
extern const u32 lbl_10_rodata_798[];

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, void*);
void* memset(void*, int, unsigned long);
}

inline PadStatus getStatus(Menu* self) {
    PadStatus status;
    if (self->port >= 0)
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(
            g_gfPadSystem, self->port, &status);
    else
        memset(&status, 0, sizeof(status));
    return status;
}

extern "C" bool fn_10_19604(Menu* self) {
    PadStatus status = getStatus(self);
    return (status.words[3] & lbl_10_rodata_798[status.words[15]]) != 0;
}
