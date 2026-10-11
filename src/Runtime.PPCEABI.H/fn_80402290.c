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

extern u32 TRKTargetStopped(void);
extern int TRKTargetContinue(void);
extern void fn_8000446C(void* destination, int value, u32 size);
extern void fn_80405B6C(void* payload, u32 size);
extern u32 lbl_8059B940[1];
extern int fn_80401868(struct TRKMessageBuffer* buffer, u32 position);
extern void fn_80401898(struct TRKMessageBuffer* buffer, int preserve_data);
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

static inline int TRKSendAcknowledgement(unsigned char status) {
    struct TRKReplyPacket reply;

    TRKInitializeReply(&reply, 0x80);
    TRKSendReply(&reply, status);
    return 0;
}

int fn_80402290(struct TRKMessageBuffer* buffer) {
    if ((int)TRKTargetStopped() == 0) {
        return TRKSendAcknowledgement(0x16);
    }
    TRKSendAcknowledgement(0);
    return TRKTargetContinue();
}

int fn_80402374(struct TRKMessageBuffer* buffer) {
    u32 transferred;
    int status = buffer->data[8];
    u32 begin = *(u16*)(buffer->data + 12);
    u32 end = *(u16*)(buffer->data + 16);

    fn_80401868(buffer, 0);
    if (begin > end) {
        return TRKSendAcknowledgement(0x14);
    }
    fn_80401868(buffer, 0x40);
    switch (status) {
    case 0:
        status = fn_80404C58(begin, end, buffer, &transferred, 0);
        break;
    case 1:
        status = fn_8040474C(begin, end, buffer, &transferred, 0);
        break;
    case 2:
        status = fn_804045DC(begin, end, buffer, &transferred, 0);
        break;
    case 3:
        status = fn_804041A4(begin, end, buffer, &transferred, 0);
        break;
    default:
        status = 0x703;
        break;
    }
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
        switch (status) {
        case 0x703:
            status = 0x12;
            break;
        case 0x701:
            status = 0x14;
            break;
        case 0x302:
            status = 2;
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
        return TRKSendAcknowledgement((unsigned char)status);
    }
    return fn_8040123C(buffer);
}
