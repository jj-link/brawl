#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct FILE {
    u32 handle;
    struct {
        u32 : 2;
        u32 open_mode : 3;
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
extern void __stdio_atexit(void);
extern int _fseek(struct FILE*, long, int);
extern void __prep_buffer(struct FILE*);
extern int __flush_buffer(struct FILE*, u32*);
extern void* __memrchr(const void*, int, u32);
extern void* memcpy(void*, const void*, u32);

u32 __fwrite(const u8* next, u32 size, u32 count, struct FILE* file) {
    int buffered;
    u32 remaining;
    u32 written;
    u32 chunk;
    const u8* newline;

    if (fwide(file, 0) == 0) {
        fwide(file, -1);
    }
    if ((remaining = size * count) == 0 || file->state.bytes.error || file->mode.file_kind == 0) {
        return 0;
    }
    if (file->mode.file_kind == 2) {
        __stdio_atexit();
    }
    buffered = (!file->mode.binary || file->mode.buffer_mode == 2) || file->mode.buffer_mode == 1;
    if (file->state.bits.io_state == 0 && (file->mode.open_mode & 2)) {
        if ((file->mode.open_mode & 4) && _fseek(file, 0, 2) != 0) {
            return 0;
        }
        file->state.bits.io_state = 1;
        __prep_buffer(file);
    }
    if (file->state.bits.io_state != 1) {
        file->state.bytes.error = 1;
        file->buffer_len = 0;
        return 0;
    }
    written = 0;
    if (remaining && (file->buffer_ptr != file->buffer || buffered)) {
        file->buffer_len = file->buffer_size - (file->buffer_ptr - file->buffer);
        do {
            newline = 0;
            chunk = file->buffer_len;
            if (chunk > remaining) {
                chunk = remaining;
            }
            if (file->mode.buffer_mode == 1 && chunk) {
                newline = __memrchr(next, '\n', chunk);
                if (newline) {
                    chunk = newline + 1 - next;
                }
            }
            if (chunk) {
                memcpy(file->buffer_ptr, next, chunk);
                next += chunk;
                remaining -= chunk;
                file->buffer_ptr += chunk;
                file->buffer_len -= chunk;
            }
            if ((!file->buffer_len || newline || file->mode.buffer_mode == 0) && __flush_buffer(file, 0) != 0) {
                file->state.bytes.error = 1;
                file->buffer_len = 0;
                remaining = 0;
                break;
            }
            written += chunk;
        } while (remaining && buffered);
    }
    if (remaining && !buffered) {
        u8* saved_buffer = file->buffer;
        u32 saved_size = file->buffer_size;
        file->buffer = (u8*)next;
        file->buffer_size = remaining;
        file->buffer_ptr = (u8*)next + remaining;
        if (__flush_buffer(file, &chunk) != 0) {
            file->state.bytes.error = 1;
            file->buffer_len = 0;
        } else {
            written += chunk;
        }
        file->buffer = saved_buffer;
        file->buffer_size = saved_size;
        __prep_buffer(file);
        file->buffer_len = 0;
    }
    if (file->mode.buffer_mode != 2) {
        file->buffer_len = 0;
    }
    return written / size;
}
