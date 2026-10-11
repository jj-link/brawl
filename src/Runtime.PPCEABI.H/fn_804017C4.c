typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern void fn_8000449C(void* destination, const void* source, u32 size);

int fn_804017C4(struct TRKMessageBuffer* buffer, const void* input,
                unsigned long count) {
    int status = 0;

    if (count == 0) {
        return 0;
    }
    if ((0x880 - buffer->cursor) < count) {
        status = 0x301;
        count = 0x880 - buffer->cursor;
    }
    if (count == 1) {
        buffer->data[buffer->cursor] = *(const unsigned char*)input;
    } else {
        fn_8000449C(buffer->data + buffer->cursor, input, count);
    }
    buffer->cursor += count;
    buffer->end = buffer->cursor;
    return status;
}

int fn_80401868(struct TRKMessageBuffer* buffer, unsigned long position) {
    int status = 0;

    if (position > 0x880) {
        status = 0x301;
    } else {
        buffer->cursor = position;
        if (position > buffer->end) {
            buffer->end = position;
        }
    }
    return status;
}
