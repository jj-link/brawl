#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0[3];
    u8 *cur;
    u8 *end;
} Stream;

s32 fn_802610A0(u8 *dst, u32 n, Stream *s) {
    s32 status;
    u32 i;

    for (i = 0; i < n; i++) {
        u8 *end;
        u8 *cur = s->cur;
        u8 c;
        end = s->end;
        if (cur >= end) {
            status = -0x90;
        } else {
            u8 *next = cur + 1;
            s->cur = next;
            c = *cur;
            status = (next >= end) ? -0x90 : 0;
        }
        *dst++ = c;
        if (status < 0) {
            return status;
        }
    }
    return 0;
}
