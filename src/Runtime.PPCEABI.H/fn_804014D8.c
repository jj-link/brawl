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

static inline int AppendBuffer(struct TRKMessageBuffer* buffer,
                               const void* bytes, unsigned long length) {
    int status;

    status = 0;
    if ((0x880 - buffer->cursor) < length) {
        status = 0x301;
        length = 0x880 - buffer->cursor;
    }
    if (length == 1) {
        buffer->data[buffer->cursor] = *(const unsigned char*)bytes;
    } else {
        fn_8000449C(buffer->data + buffer->cursor, bytes, length);
    }
    buffer->cursor += length;
    buffer->end = buffer->cursor;
    return status;
}

static inline int AppendWord(struct TRKMessageBuffer* buffer, u32 word) {
    unsigned char swapped[4];
    unsigned char* bytes;

    if (gTRKBigEndian != 0) {
        bytes = (unsigned char*)&word;
    } else {
        swapped[0] = ((unsigned char*)&word)[3];
        swapped[1] = ((unsigned char*)&word)[2];
        swapped[2] = ((unsigned char*)&word)[1];
        swapped[3] = ((unsigned char*)&word)[0];
        bytes = swapped;
    }
    return AppendBuffer(buffer, bytes, 4);
}

int fn_804014D8(struct TRKMessageBuffer* buffer, const u32* values, int count) {
    int i = 0;
    int status = 0;

    for (; status == 0 && i < count; i++) {
        status = AppendWord(buffer, values[i]);
    }
    return status;
}

static inline int AppendByte(struct TRKMessageBuffer* buffer,
                             unsigned char byte) {
    int status;

    if (buffer->cursor >= 0x880) {
        status = 0x301;
    } else {
        buffer->data[buffer->cursor++] = byte;
        buffer->end += 1;
        status = 0;
    }
    return status;
}

int fn_804015D4(struct TRKMessageBuffer* buffer, const unsigned char* input,
                int count) {
    int i = 0;
    int status = 0;

    for (; status == 0 && i < count; i++) {
        status = AppendByte(buffer, input[i]);
    }
    return status;
}
