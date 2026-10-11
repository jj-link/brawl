typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

struct TRKReplyPacket {
    u32 length;
    unsigned char command;
    unsigned char reserved5[3];
    unsigned char status;
    unsigned char reserved9[3];
    u32 sequence;
    unsigned char payload[0x30];
};

extern int fn_80403B5C(void);
extern int fn_80401868(struct TRKMessageBuffer* buffer, u32 position);
extern u32 fn_80403D94(void);
extern u32 TRKTargetStopped(void);
extern int fn_80403E20(u32 count, int step_over);
extern int fn_80403DA4(u32 range_start, u32 range_end, int step_over);
extern void fn_8000446C(void* destination, int value, u32 size);
extern void fn_80405B6C(void* payload, u32 size);
extern u32 lbl_8059B940[1];

static inline void TRKInitializeReply(struct TRKReplyPacket* reply,
                                      unsigned char command) {
    fn_8000446C(reply, 0, sizeof(*reply));
    reply->command = command;
    reply->sequence = lbl_8059B940[0];
    ++lbl_8059B940[0];
}

static inline void TRKSendReply(struct TRKReplyPacket* reply,
                                unsigned char status) {
    reply->length = sizeof(*reply);
    reply->status = status;
    reply->sequence = lbl_8059B940[0]++;
    fn_80405B6C(reply, sizeof(*reply));
}

static inline int TRKReplyStatus(unsigned char status) {
    struct TRKReplyPacket reply;

    TRKInitializeReply(&reply, 0x80);
    TRKSendReply(&reply, status);
    return 0;
}

int fn_80401EF0(struct TRKMessageBuffer* buffer) {
    unsigned char status;

    switch (fn_80403B5C()) {
    case 0:
        status = 0;
        break;
    case 0x704:
        status = 0x21;
        break;
    case 0x705:
        status = 0x22;
        break;
    case 0x706:
        status = 0x20;
        break;
    default:
        status = 1;
        break;
    }
    return TRKReplyStatus(status);
}

int fn_80401FBC(struct TRKMessageBuffer* buffer) {
    int operation;
    u32 steps;
    u32 range_start;
    u32 range_end;
    int status;

    fn_80401868(buffer, 0);
    operation = buffer->data[8];
    range_start = ((u32*)buffer->data)[4];
    range_end = ((u32*)buffer->data)[5];

    switch (operation) {
    case 0:
    case 16:
        steps = buffer->data[12];
        if (steps < 1) {
            return TRKReplyStatus(0x11);
        }
        break;
    case 1:
    case 17: {
        u32 address = fn_80403D94();

        if (address < range_start || address > range_end) {
            return TRKReplyStatus(0x11);
        }
        break;
    }
    default:
        return TRKReplyStatus(0x12);
    }

    if ((int)TRKTargetStopped() == 0) {
        return TRKReplyStatus(0x16);
    }
    TRKReplyStatus(0);
    status = 0;

    switch (operation) {
    case 0:
    case 16:
        status = fn_80403E20(steps, operation == 16);
        break;
    case 1:
    case 17:
        status = fn_80403DA4(range_start, range_end, operation == 17);
        break;
    }
    return status;
}
