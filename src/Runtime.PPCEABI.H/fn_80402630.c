typedef unsigned long u32;
typedef unsigned short u16;

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

extern void fn_8000446C(void* destination, int value, u32 size);
extern void fn_80405B6C(void* payload, u32 size);
extern u32 lbl_8059B940[1];
extern void fn_80401898(struct TRKMessageBuffer* buffer, int preserve_data);
extern int fn_80401868(struct TRKMessageBuffer* buffer, u32 position);
extern int fn_804015D4(struct TRKMessageBuffer* buffer,
                     const unsigned char* input, int count);
extern int fn_80401738(struct TRKMessageBuffer* buffer, void* destination,
                     u32 count);
extern int fn_804017C4(struct TRKMessageBuffer* buffer, const void* input,
                     u32 count);
extern int fn_8040123C(void* packet);
extern int fn_80404C58(u32 begin, u32 end, struct TRKMessageBuffer* buffer,
                     u32* transferred, int read);
extern int fn_8040474C(u32 begin, u32 end, struct TRKMessageBuffer* buffer,
                     u32* transferred, int read);
extern int fn_804045DC(u32 begin, u32 end, struct TRKMessageBuffer* buffer,
                     u32* transferred, int read);
extern int fn_804041A4(u32 begin, u32 end, struct TRKMessageBuffer* buffer,
                     u32* transferred, int read);
extern int fn_80404D98(void* destination, u32 address, u32* size,
                     int translate, int read);

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

static inline int TRKReplyMemoryError(int status) {
    switch (status) {
    case 0x702:
        status = 0x15;
        break;
    case 0x700:
        status = 0x13;
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
        status = 3;
        break;
    }
    return TRKReplyStatus((unsigned char)status);
}

int fn_80402630(struct TRKMessageBuffer* buffer) {
    struct TRKReplyPacket reply;
    u32 transferred;
    u32 begin = *(u16*)(buffer->data + 12);
    u32 end = *(u16*)(buffer->data + 16);
    int status;

    if (begin > end) {
        return TRKReplyStatus(0x14);
    }

    /* The snapshot header deliberately leaves its other bytes unwritten. */
    reply.command = 0x80;
    reply.length = 0x468;
    reply.sequence = lbl_8059B940[0]++;
    fn_80401898(buffer, 0);
    fn_804015D4(buffer, (const unsigned char*)&reply, sizeof(reply));

    status = fn_80404C58(0, 0x24, buffer, &transferred, 1);
    if (status == 0) {
        status = fn_8040474C(0, 0x21, buffer, &transferred, 1);
    }
    if (status == 0) {
        status = fn_804045DC(0, 0x60, buffer, &transferred, 1);
    }
    if (status == 0) {
        status = fn_804041A4(0, 0x1f, buffer, &transferred, 1);
    }
    if (status != 0) {
        switch (status) {
        case 0x703:
            status = 0x12;
            break;
        case 0x701:
            status = 0x14;
            break;
        case 0x702:
            status = 0x15;
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
            status = 3;
            break;
        }
        return TRKReplyStatus((unsigned char)status);
    }
    return fn_8040123C(buffer);
}

int fn_80402854(struct TRKMessageBuffer* buffer) {
    unsigned char memory[0x820] __attribute__((aligned(32)));
    int options;
    int status;
    u32 address;
    u32 requested_length;
    u32 length;

    options = buffer->data[8];
    address = *(u32*)(buffer->data + 16);
    requested_length = *(u16*)(buffer->data + 12);

    if (options & 2) {
        return TRKReplyStatus(0x12);
    }
    length = requested_length;
    fn_80401868(buffer, 0x40);
    fn_80401738(buffer, memory, length);
    status = fn_80404D98(memory, address, &length,
                        ((options >> 3) & 1) ^ 1, 0);
    fn_80401898(buffer, 0);
    if (status == 0) {
        struct TRKReplyPacket reply;

        fn_8000446C(&reply, 0, sizeof(reply));
        reply.length = sizeof(reply);
        reply.command = 0x80;
        reply.status = status;
        reply.sequence = lbl_8059B940[0]++;
        status = fn_804017C4(buffer, &reply, sizeof(reply));
    }
    if (status != 0) {
        return TRKReplyMemoryError(status);
    }
    return fn_8040123C(buffer);
}

int fn_80402A70(struct TRKMessageBuffer* buffer) {
    unsigned char memory[0x820] __attribute__((aligned(32)));
    int options;
    register int status;
    register unsigned char reply_status;
    u32 address;
    u32 requested_length;
    u32 length;

    options = buffer->data[8];
    address = *(u32*)(buffer->data + 16);
    requested_length = *(u16*)(buffer->data + 12);

    if (options & 2) {
        return TRKReplyStatus(0x12);
    }
    length = requested_length;
    status = fn_80404D98(memory, address, &length,
                        ((options >> 3) & 1) ^ 1, 1);
    fn_80401898(buffer, 0);
    if (status == 0) {
        struct TRKReplyPacket reply;

        fn_8000446C(&reply, 0, sizeof(reply));
        reply.length = length + sizeof(reply);
        reply.status = status;
        reply.command = 0x80;
        reply.sequence = lbl_8059B940[0]++;
        fn_804017C4(buffer, &reply, sizeof(reply));
        if (options & 0x40) {
            status = fn_804017C4(buffer, memory + (address & 0x1f), length);
        } else {
            status = fn_804017C4(buffer, memory, length);
        }
    }
    if (status != 0) {
        switch (status) {
        case 0x702:
            reply_status = 0x15;
            break;
        case 0x700:
            reply_status = 0x13;
            break;
        case 0x704:
            reply_status = 0x21;
            break;
        case 0x705:
            reply_status = 0x22;
            break;
        case 0x706:
            reply_status = 0x20;
            break;
        default:
            reply_status = 3;
            break;
        }
        return TRKReplyStatus(reply_status);
    }
    return fn_8040123C(buffer);
}
