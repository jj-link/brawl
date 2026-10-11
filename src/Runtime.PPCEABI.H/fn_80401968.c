typedef unsigned long u32;

struct TRKMessageBuffer {
    u32 x0; /* Lock storage. */
    int x4; /* In-use flag. */
    u32 end;
    u32 cursor;
    unsigned char data[0x880];
};

extern char lbl_80599F78[3][0x890];
extern const char lbl_80420488[];

int fn_804035BC(void* buffer);
int fn_804035B4(void* buffer);
int fn_804035C4(void* buffer);
void fn_80401C54(const char* text);

static inline struct TRKMessageBuffer* get_message_buffer(int index) {
    struct TRKMessageBuffer* buffer = 0;

    if (index >= 0 && index < 3) {
        buffer = (struct TRKMessageBuffer*)lbl_80599F78[index];
    }
    return buffer;
}

int fn_80401968(int* out_index, struct TRKMessageBuffer** out_buffer) {
    int status = 0x300;
    int index;
    struct TRKMessageBuffer* buffer;

    *out_buffer = 0;
    for (index = 0; index < 3; ++index) {
        buffer = get_message_buffer(index);
        fn_804035BC(buffer);
        if (buffer->x4 == 0) {
            buffer->end = 0;
            buffer->cursor = 0;
            buffer->x4 = 1;
            *out_buffer = buffer;
            *out_index = index;
            status = 0;
            index = 3;
        }
        fn_804035B4(buffer);
    }
    if (status == 0x300) {
        fn_80401C54(lbl_80420488);
    }
    return status;
}

int TRKInitializeMessageBuffers(void) {
    int index;

    for (index = 0; index < 3; ++index) {
        char* buffer = lbl_80599F78[index];

        fn_804035C4(buffer);
        fn_804035BC(buffer);
        ((struct TRKMessageBuffer*)buffer)->x4 = 0;
        fn_804035B4(buffer);
    }
    return 0;
}
