typedef unsigned long u32;
typedef unsigned short u16;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
};

struct TRKStepState {
    int active;
    int mode;
    u32 count;
    u32 range_start;
    u32 range_end;
};

struct TRKNotificationPacket {
    u32 length;
    unsigned char command;
    unsigned char reserved5[3];
    u32 address;
    u32 instruction;
    u32 exception;
    unsigned char payload[0x2c];
};

extern u32 gTRKCPUState[];
extern u32 gTRKState[];
extern u32 gTRKExceptionStatus_804947AC[];
extern struct TRKStepState lbl_804947BC;
extern void fn_8000446C(void* destination, int value, u32 size);
extern int fn_80404D4C(void* destination, u32 address);
extern int fn_804015D4(struct TRKMessageBuffer* buffer,
                     const unsigned char* input, int count);
extern int fn_804035CC(int command);
extern void fn_80400EB4(struct TRKEvent* event, u32 type);
extern int fn_80400ECC(struct TRKEvent* event);

static inline void TRKResumeStep(void) {
    int mode = lbl_804947BC.mode;

    lbl_804947BC.active = 1;
    gTRKCPUState[0x1f8 / sizeof(u32)] |= 0x400;
    if (mode == 0 || mode == 16) {
        --lbl_804947BC.count;
    }
    gTRKState[0x98 / sizeof(u32)] = 0;
}

static inline int TRKStepDone(void) {
    int done = 1;

    if (lbl_804947BC.active != 0 &&
        (gTRKCPUState[0x2f8 / sizeof(u32)] & 0xffff) == 0xd00) {
        switch (lbl_804947BC.mode) {
        case 0:
            if (lbl_804947BC.count != 0) {
                done = 0;
            }
            break;
        case 1: {
            u32 address = gTRKCPUState[0x80 / sizeof(u32)];

            if (address >= lbl_804947BC.range_start &&
                address <= lbl_804947BC.range_end) {
                done = 0;
            }
            break;
        }
        }
    }
    return done;
}

static inline void TRKEnableTrace(void) {
    gTRKCPUState[0x1f8 / sizeof(u32)] |= 0x400;
}

static inline void TRKContinueStep(struct TRKStepState* step) {
    int mode;

    step->active = 1;
    mode = step->mode;
    TRKEnableTrace();
    if (mode == 0 || mode == 16) {
        --lbl_804947BC.count;
    }
    gTRKState[0x98 / sizeof(u32)] = 0;
}

int fn_80403DA4(u32 range_start, u32 range_end, int step_over) {
    if (step_over != 0) {
        return 0x703;
    }
    lbl_804947BC.mode = 1;
    lbl_804947BC.range_start = range_start;
    lbl_804947BC.range_end = range_end;
    TRKResumeStep();
    return 0;
}

int fn_80403E20(u32 count, int step_over) {
    if (step_over != 0) {
        return 0x703;
    }
    lbl_804947BC.mode = 0;
    lbl_804947BC.count = count;
    TRKResumeStep();
    return 0;
}

int fn_80403E8C(struct TRKMessageBuffer* buffer) {
    struct TRKNotificationPacket packet;
    u32 instruction;

    fn_8000446C(&packet, 0, sizeof(packet));
    packet.length = sizeof(packet);
    packet.command = 0x91;
    packet.address = gTRKExceptionStatus_804947AC[0];
    fn_80404D4C(&instruction, packet.address);
    packet.instruction = instruction;
    packet.exception = *(u16*)((unsigned char*)gTRKExceptionStatus_804947AC + 8);
    return fn_804015D4(buffer, (const unsigned char*)&packet, sizeof(packet));
}

int fn_80403F10(struct TRKMessageBuffer* buffer) {
    struct TRKNotificationPacket packet;
    u32 instruction;

    fn_8000446C(&packet, 0, sizeof(packet));
    packet.length = sizeof(packet);
    packet.command = 0x90;
    packet.address = gTRKCPUState[0x80 / sizeof(u32)];
    fn_80404D4C(&instruction, packet.address);
    packet.instruction = instruction;
    packet.exception = gTRKCPUState[0x2f8 / sizeof(u32)] & 0xffff;
    return fn_804015D4(buffer, (const unsigned char*)&packet, sizeof(packet));
}

int TRKTargetInterrupt(struct TRKEvent* event) {
    int status = 0;

    switch ((int)event->type) {
    case 3:
    case 4:
        if (lbl_804947BC.active != 0) {
            gTRKCPUState[0x1f8 / sizeof(u32)] &= ~0x400UL;
            if (TRKStepDone()) {
                lbl_804947BC.active = 0;
            } else {
                TRKContinueStep(&lbl_804947BC);
            }
        }
        if (lbl_804947BC.active == 0) {
            gTRKState[0x98 / sizeof(u32)] = 1;
            status = fn_804035CC(0x90);
        }
        break;
    }
    return status;
}

void TRKPostInterruptEvent(void) {
    struct TRKEvent event;
    u32 instruction;
    u32 type;

    if ((int)gTRKState[0x9c / sizeof(u32)] != 0) {
        gTRKState[0x9c / sizeof(u32)] = 0;
    } else {
        switch ((int)(gTRKCPUState[0x2f8 / sizeof(u32)] & 0xffff)) {
        case 0xd00:
        case 0x700:
            fn_80404D4C(&instruction, gTRKCPUState[0x80 / sizeof(u32)]);
            if (instruction == 0x0fe00000) {
                type = 5;
            } else {
                type = 3;
            }
            break;
        default:
            type = 4;
            break;
        }
        fn_80400EB4(&event, type);
        fn_80400ECC(&event);
    }
}
