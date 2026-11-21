#include <types.h>
#include <revolution/CX/CXCompression.h>
#pragma force_active on

typedef struct {
    u32 dest;
    s32 remaining;
    s32 total;
    u16 repeat;
    u8 code;
    u8 bitcount;
} RLContext;

static inline u32 ReadHeaderRL(RLContext *c, const u8 *data, u32 len) {
    u8 b;
    u32 n;
    s32 total;
    u32 cnt;
    const u8 *p;

    total = c->total;
    cnt = len;
    p = data;
    n = 0;
    goto header_check;
header_loop:
    c->bitcount--;
    b = c->bitcount;
    if (b <= 3)
        c->remaining |= (u32)(*p) << ((3 - b) * 8);
    else if (b <= 6)
        c->remaining |= (u32)(*p) << ((6 - b) * 8);
    p++;
    n++;
    if (c->bitcount == 4 && c->remaining > 0)
        c->bitcount = 0;
    cnt--;
    if (cnt == 0 && c->bitcount != 0)
        return n;
header_check:
    if (c->bitcount != 0)
        goto header_loop;
    if (total > 0 && total < c->remaining)
        c->remaining = total;
    return n;
}

s32 CXReadUncompRL(CXUncompContext *ctx, const CXStream *src, u32 len) {
    RLContext *c = (RLContext *)ctx;
    const u8 *data = (const u8 *)src;
    const u8 *p;
    u32 cnt;
    s32 total;
    u32 n;
    u8 byte;
    u8 b;
    u16 rv;
    u8 fill;
    u8 *dst;

    if (c->bitcount == 0)
        goto decompress_check;

    if (c->bitcount == 8) {
        byte = *data;
        if ((byte & 0xF0) != 0x30)
            return -1;
        if (byte & 0x0F)
            return -1;
    }

    n = ReadHeaderRL(c, data, len);

    len -= n;
    data += n;

    if (len != 0)
        goto decompress_check;
    if (c->bitcount == 0)
        return c->remaining;
    return -1;

decompress_loop:
    if (!(c->code & 0x80)) {
        while (c->repeat != 0) {
            byte = *data;
            len--;
            data++;
            dst = (u8 *)c->dest;
            *dst = byte;
            c->dest = (u32)(dst + 1);
            c->repeat--;
            c->remaining--;
            if (len == 0)
                return c->remaining;
        }
    } else if (c->repeat != 0) {
        fill = *data;
        len--;
        data++;

        while (c->repeat != 0) {
            dst = (u8 *)c->dest;
            *dst = fill;
            c->dest = (u32)(dst + 1);
            c->repeat--;
            c->remaining--;
        }

        if (len == 0)
            return c->remaining;
    }

    byte = *data;
    data++;
    len--;
    c->code = byte;
    c->repeat = byte & 0x7F;

    if (byte & 0x80)
        c->repeat += 3;
    else
        c->repeat += 1;

    if (c->repeat > c->remaining) {
        if (c->total == 0)
            return -4;
        c->repeat = c->remaining;
    }

    if (len == 0)
        return c->remaining;

decompress_check:
    if (c->remaining > 0)
        goto decompress_loop;
    if (c->total == 0 && len > 0x20)
        return -3;
    return 0;
}
