typedef unsigned long u32;

struct TRKState {
    unsigned char reserved[0x98];
    u32 stopped;
    u32 pending_event;
    unsigned char* pending;
};

extern struct TRKState gTRKState;

void TRKTargetSetInputPendingPtr(unsigned char* pending) {
    gTRKState.pending = pending;
}

