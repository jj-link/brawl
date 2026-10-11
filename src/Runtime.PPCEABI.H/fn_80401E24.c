// MetroTRK SerialIO option handler and its fixed-size reply packet.
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

extern void fn_8000446C(void* destination, int value, u32 size);
extern void fn_80405B6C(void* payload, u32 size);
extern int fn_80401C54(const char* text);
extern void fn_80405EFC(unsigned char value);
extern u32 lbl_8059B940[1];

static const char option[0x20] = "\nMetroTRK Option : SerialIO - ";
static const char enable[8] = "Enable\n";
static const char disable[0x10] = "Disable\n";

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

int fn_80401E24(struct TRKMessageBuffer* buffer) {
    unsigned char override_flag = buffer->data[12];

    if (buffer->data[8] == 1) {
        fn_80401C54(option);
        if (override_flag != 0) {
            fn_80401C54(enable);
        } else {
            fn_80401C54(disable);
        }
        fn_80405EFC(override_flag);
    }
    {
        struct TRKReplyPacket reply;
        TRKInitializeReply(&reply, 0x80);
        TRKSendReply(&reply, 0);
    }
    return 0;
}
