#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Buf {
    u8 pad[12];
    u8 *ptr;
    u8 *end;
} Buf;

static inline s32 read_byte(u8 *out, Buf *buf)
{
    if (buf->ptr >= buf->end)
        return -0x90;

    *out = *buf->ptr++;
    return buf->ptr >= buf->end ? -0x90 : 0;
}

s32 fn_80261004(u16 *out, Buf *buf)
{
    u8 byte;
    unsigned int sh;
    s32 err;

    err = read_byte(&byte, buf);
    sh = byte << 8;
    if (err < 0)
        return err;

    err = read_byte(&byte, buf);
    *out = sh + byte;
    return err < 0 ? err : 0;
}
