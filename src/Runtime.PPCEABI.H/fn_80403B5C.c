typedef unsigned long u32;

struct TRKState {
    unsigned char reserved[0x98];
    u32 stopped;
    u32 pending_event;
    unsigned char* pending;
};

extern struct TRKState gTRKState;

int fn_80403B5C(void) {
    gTRKState.stopped = 1;
    return 0;
}
