typedef unsigned long u32;

struct TRKMessageBuffer;

struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
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
extern void fn_80405810(void);
extern void fn_800063F4(void);
extern void fn_80400EB4(struct TRKEvent* event, u32 type);
extern int fn_80400ECC(struct TRKEvent* event);
extern u32 lbl_8059B940[1];
extern void* lbl_8059B944;

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

int fn_80402CC8(struct TRKMessageBuffer* buffer) {
    TRKSendAcknowledgement(0);
    fn_80405810();
    return 0;
}

int fn_80402D44(struct TRKMessageBuffer* buffer) {
    TRKSendAcknowledgement(0);
    fn_800063F4();
    return 0;
}

int fn_80402DC0(struct TRKMessageBuffer* buffer) {
    struct TRKEvent event;

    lbl_8059B944 = 0;
    TRKSendAcknowledgement(0);
    fn_80400EB4(&event, 1);
    fn_80400ECC(&event);
    return 0;
}

int fn_80402E5C(struct TRKMessageBuffer* buffer) {
    lbl_8059B944 = (void*)1;
    return TRKSendAcknowledgement(0);
}
