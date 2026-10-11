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

int fn_8040163C(struct TRKMessageBuffer* buffer, unsigned long long value) {
    unsigned char swapped[8];
    unsigned char* bytes;
    int status;
    unsigned long length;

    if (gTRKBigEndian != 0) {
        bytes = (unsigned char*)&value;
    } else {
        swapped[0] = ((unsigned char*)&value)[7];
        swapped[1] = ((unsigned char*)&value)[6];
        swapped[2] = ((unsigned char*)&value)[5];
        swapped[3] = ((unsigned char*)&value)[4];
        swapped[4] = ((unsigned char*)&value)[3];
        swapped[5] = ((unsigned char*)&value)[2];
        swapped[6] = ((unsigned char*)&value)[1];
        swapped[7] = ((unsigned char*)&value)[0];
        bytes = swapped;
    }
    length = 8;
    status = 0;
    if ((0x880 - buffer->cursor) < length) {
        status = 0x301;
        length = 0x880 - buffer->cursor;
    }
    if (length == 1) {
        buffer->data[buffer->cursor] = bytes[0];
    } else {
        fn_8000449C(buffer->data + buffer->cursor, bytes, length);
    }
    buffer->cursor += length;
    buffer->end = buffer->cursor;
    return status;
}

int fn_80401738(struct TRKMessageBuffer* buffer, void* destination,
                unsigned long count) {
    int status = 0;

    if (count == 0) {
        return 0;
    }
    if (count > (buffer->end - buffer->cursor)) {
        status = 0x302;
        count = buffer->end - buffer->cursor;
    }
    fn_8000449C(destination, buffer->data + buffer->cursor, count);
    buffer->cursor += count;
    return status;
}
