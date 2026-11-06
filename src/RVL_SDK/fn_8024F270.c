#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Context { u8 pad[0x28]; u16 id; } Context;
typedef struct Channel { u8 pad[0x10]; Context *ctx; u8 pad2[2]; u16 id; u8 pad3[0x1e]; u8 ident; } Channel;
extern u8 lbl_8052CDC0[];
extern char lbl_80483DEC[];
extern u8 *fn_8022EFF8(u32);
extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, void *, void *);
extern void *memcpy(void *, const void *, u32);

void fn_8024F270(Channel *ch, u8 *src, int len, int size)
{
    u8 *packet, *start, *out, *end;
    int n, a, b;
    u8 optlen, type;
    u16 total;
    packet = fn_8022EFF8(2);
    if (packet == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, lbl_80483DEC);
    } else {
        *(u16 *)(packet + 4) = 0;
        start = packet + 10;
        packet[8] = ch->ctx->id | 0x2000;
        packet[9] = (ch->ctx->id | 0x2000) >> 8;
        a = size + 10;
        b = size + 6;
        start[2] = a;
        start[3] = a >> 8;
        start[4] = 1;
        start[5] = 0;
        start[6] = 5;
        start[7] = ch->ident;
        start[8] = b;
        start[9] = b >> 8;
        start[10] = ch->id;
        start[11] = ch->id >> 8;
        start[12] = 0;
        start[13] = 0;
        start[14] = 3;
        start[15] = 0;
        out = start;
        start += 16;
        end = src + len;
        while (src < end) {
            type = src[0];
            optlen = src[1];
            switch (type & 0x7f) {
            case 1:
            case 2:
            case 3:
                src += optlen + 2;
                break;
            default:
                n = optlen + 2;
                if (n <= len) {
                    if (!(type & 0x80)) {
                        memcpy(start, src, n);
                        start += n;
                    }
                    src += n;
                } else {
                    src = end;
                }
                break;
            }
        }
        total = start - out - 2;
        out[0] = total;
        out[1] = total >> 8;
        *(u16 *)(packet + 2) = total + 4;
        fn_8024CB94(ch->ctx, ch, packet);
    }
}