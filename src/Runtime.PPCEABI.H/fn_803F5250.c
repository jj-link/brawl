// MSL buffered read, including byte and wide-character pushback.
typedef unsigned long u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct FILE {
    u32 handle;
    struct {
        u32 : 4;
        u32 readable : 1;
        u32 buffer_mode : 2;
        u32 file_kind : 3;
        u32 : 2;
        u32 binary : 1;
        u32 : 19;
    } mode;
    union {
        struct {
            u32 io_state : 3;
            u32 : 29;
        } bits;
        struct {
            u8 flags, eof, error, reserved;
        } bytes;
    } state;
    u8 pushback[12];
    u32 position;
    u8* buffer;
    u32 buffer_size;
    u8* buffer_ptr;
    u32 buffer_len;
    u32 buffer_alignment;
    u32 saved_buffer_len;
};

extern int fwide(struct FILE*, int);
extern int fn_803F3600(void);
extern int fn_803F5098(struct FILE*, u32*, int);
extern void __prep_buffer(struct FILE*);
extern void* memcpy(void*, const void*, u32);

u32 fn_803F5250(u8* next, u32 size, u32 count, struct FILE* file) {
    int buffered;
    u32 remaining;
    u32 read;
    u32 chunk;
    int result;

    if (fwide(file, 0) == 0) {
        fwide(file, -1);
    }
    if ((remaining = size * count) == 0 || file->state.bytes.error || file->mode.file_kind == 0) {
        return 0;
    }
    buffered = 1;
    if (file->mode.binary && file->mode.buffer_mode != 2) {
        buffered = 0;
    }
    if (file->state.bits.io_state == 0 && file->mode.readable) {
        file->state.bits.io_state = 2;
        file->buffer_len = 0;
    }
    if (file->state.bits.io_state < 2) {
        file->state.bytes.error = 1;
        file->buffer_len = 0;
        return 0;
    }
    if ((file->mode.buffer_mode & 1) && fn_803F3600() != 0) {
        file->state.bytes.error = 1;
        file->buffer_len = 0;
        return 0;
    }
    read = 0;
    if (remaining && file->state.bits.io_state >= 3) {
        do {
            if (fwide(file, 0) == 1) {
                *(u16*)next = ((u16*)file->pushback)[file->state.bits.io_state];
                next += 2;
                read += 2;
                remaining -= 2;
            } else {
                *next++ = file->pushback[file->state.bits.io_state];
                read++;
                remaining--;
            }
            file->state.bits.io_state--;
        } while (remaining && file->state.bits.io_state >= 3);
        if (file->state.bits.io_state == 2) {
            file->buffer_len = file->saved_buffer_len;
        }
    }
    if (remaining && (file->buffer_len || buffered)) {
        do {
            if (file->buffer_len == 0) {
                result = fn_803F5098(file, 0, 0);
                if (result != 0) {
                    if (result == 1) {
                        file->state.bytes.error = 1;
                        file->buffer_len = 0;
                    } else {
                        file->buffer_len = 0;
                        file->state.bits.io_state = 0;
                        file->state.bytes.eof = 1;
                    }
                    remaining = 0;
                    break;
                }
            }
            chunk = file->buffer_len;
            if (chunk > remaining) {
                chunk = remaining;
            }
            memcpy(next, file->buffer_ptr, chunk);
            remaining -= chunk;
            next += chunk;
            read += chunk;
            file->buffer_ptr += chunk;
            file->buffer_len -= chunk;
        } while (remaining && buffered);
    }
    if (remaining && !buffered) {
        u8* saved_buffer = file->buffer;
        u32 saved_size = file->buffer_size;
        file->buffer = next;
        file->buffer_size = remaining;
        result = fn_803F5098(file, &chunk, 1);
        if (result != 0) {
            if (result == 1) {
                file->state.bytes.error = 1;
                file->buffer_len = 0;
            } else {
                file->buffer_len = 0;
                file->state.bits.io_state = 0;
                file->state.bytes.eof = 1;
            }
        }
        read += chunk;
        file->buffer = saved_buffer;
        file->buffer_size = saved_size;
        __prep_buffer(file);
        file->buffer_len = 0;
    }
    return read / size;
}
