typedef unsigned long u32;

struct TRKMessageBuffer;
struct TRKExceptionStatus {
    u32 words[3];
    unsigned char flags;
    unsigned char detected;
    unsigned short reserved;
};

extern struct TRKExceptionStatus gTRKExceptionStatus_804947AC;
extern u32 gTRKCPUState[];
extern int fn_804014D8(struct TRKMessageBuffer* buffer, const u32* values, int count);
extern int fn_80401268(struct TRKMessageBuffer* buffer, u32* values, int count);

/* Transfer an inclusive range of the saved integer register state. */
int fn_80404C58(u32 first, u32 last, struct TRKMessageBuffer* buffer,
                u32* transferred, int read) {
    struct TRKExceptionStatus saved;
    u32* registers;
    struct TRKExceptionStatus* status;
    u32 count;
    int result;

    if (last > 36) {
        return 0x701;
    }
    status = &gTRKExceptionStatus_804947AC;
    saved = *status;
    status->detected = 0;
    registers = &gTRKCPUState[first];
    count = last - first + 1;
    *transferred = count * sizeof(u32);
    if (read) {
        result = fn_804014D8(buffer, registers, count);
    } else {
        result = fn_80401268(buffer, registers, count);
    }
    if (status->detected != 0U) {
        *transferred = 0;
        result = 0x702;
    }
    gTRKExceptionStatus_804947AC = saved;
    return result;
}
