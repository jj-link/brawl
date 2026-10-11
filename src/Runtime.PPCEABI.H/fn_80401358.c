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
    int status = 0;

    if (length == 0) {
        return 0;
    }
    if (length > (buffer->end - buffer->cursor)) {
        status = 0x302;
        length = buffer->end - buffer->cursor;
    }
    fn_8000449C(destination, buffer->data + buffer->cursor, length);
    buffer->cursor += length;
    return status;
}

int fn_80401358(struct TRKMessageBuffer* buffer, unsigned char* destination,
                int count) {
    int index = 0;
    int status = 0;

    while (status == 0 && index < count) {
        status = TRKReadBuffer(buffer, destination + index, 1);
        ++index;
    }
    return status;
}

int fn_804013F0(struct TRKMessageBuffer* buffer, unsigned long long* value) {
    unsigned char swapped[8];
    unsigned char* bytes;
    int status;

    if (gTRKBigEndian != 0) {
        bytes = (unsigned char*)value;
    } else {
        bytes = swapped;
    }
    status = TRKReadBuffer(buffer, bytes, 8);
    if (gTRKBigEndian == 0 && status == 0) {
        ((unsigned char*)value)[0] = bytes[7];
        ((unsigned char*)value)[1] = bytes[6];
        ((unsigned char*)value)[2] = bytes[5];
        ((unsigned char*)value)[3] = bytes[4];
        ((unsigned char*)value)[4] = bytes[3];
        ((unsigned char*)value)[5] = bytes[2];
        ((unsigned char*)value)[6] = bytes[1];
        ((unsigned char*)value)[7] = bytes[0];
    }
    return status;
}
