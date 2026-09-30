typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0;
    u32 x4;
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern void fn_8000446C(void* destination, int value, u32 size);

void fn_80401898(struct TRKMessageBuffer* buffer, int preserve_data) {
    buffer->end = 0;
    buffer->cursor = 0;
    if (!preserve_data) {
        fn_8000446C(buffer->data, 0, 0x880);
    }
}
