typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern void fn_8000449C(void* destination, const void* source, u32 size);
extern int gTRKBigEndian;

static inline int TRKReadBuffer(struct TRKMessageBuffer* buffer,
                                void* destination, register unsigned int length) {
    u32 available;
    int status = 0;

    if (length == 0) {
        return 0;
    }
    available = buffer->end - buffer->cursor;
    if (length > available) {
        status = 0x302;
        length = available;
    }
    fn_8000449C(destination, buffer->data + buffer->cursor, length);
    buffer->cursor += length;
    return status;
}

static inline int TRKReadWord(struct TRKMessageBuffer* buffer, u32* output) {
    unsigned char swapped[4];
    unsigned char* bytes;
    int status;

    if (gTRKBigEndian != 0) {
        bytes = (unsigned char*)output;
    } else {
        bytes = swapped;
    }
    status = TRKReadBuffer(buffer, bytes, 4);
    if (gTRKBigEndian == 0 && status == 0) {
        ((unsigned char*)output)[0] = bytes[3];
        ((unsigned char*)output)[1] = bytes[2];
        ((unsigned char*)output)[2] = bytes[1];
        ((unsigned char*)output)[3] = bytes[0];
    }
    return status;
}

int fn_80401268(struct TRKMessageBuffer* buffer, u32* output, int count) {
    int index = 0;
    int status = 0;

    while (status == 0 && index < count) {
        status = TRKReadWord(buffer, output + index);
        ++index;
    }
    return status;
}
