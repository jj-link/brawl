#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319E4(u32, const char *);
extern void fn_8024CB94(void *, void *, void *);
extern u8 *fn_8024E864(int, u32, int, int);
extern u8 lbl_8052CDC0[];
extern u8 lbl_805297D0[];
extern u8 *fn_8022EFF8(u32);
extern void fn_8022F500(void *, void *);
extern void *memcpy(void *, const void *, u32);

void fn_8024EA24(u8 *self) {
    u8 *p;
    u8 v;
    v = (*(u8 **)(self + 0x10))[0x31] + 1;
    (*(u8 **)(self + 0x10))[0x31] = v;
    self[0x35] = v;
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), 4, 2, v);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        p[0x14] = *(u16 *)(*(u8 **)(self + 0x30) + 2);
        p[0x15] = (int)*(u16 *)(*(u8 **)(self + 0x30) + 2) >> 8;
        p[0x16] = *(u16 *)(self + 0x14);
        p[0x17] = (int)*(u16 *)(self + 0x14) >> 8;
        fn_8024CB94(*(u8 **)(self + 0x10), 0, p);
    }
}
void fn_8024EAE8(u8 *self, int a, u32 b) {
    u8 *p;
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), 8, 3, self[0x36]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
    } else {
        p[0x14] = (u8)*(u16 *)(self + 0x14);
        p[0x15] = (u8)((int)*(u16 *)(self + 0x14) >> 8);
        p[0x16] = (u8)*(u16 *)(self + 0x16);
        p[0x17] = (u8)((int)*(u16 *)(self + 0x16) >> 8);
        p[0x18] = (u8)a;
        p[0x19] = (u8)(a >> 8);
        p[0x1A] = (u8)b;
        p[0x1B] = (u8)(b >> 8);
        fn_8024CB94((void *)*(u32 *)(self + 0x10), 0, p);
    }
}
void fn_8024EBC0(u8 *self, int a, u32 b, u32 c) {
    u8 *p;
    p = fn_8024E864(*(u16 *)(self + 0x28), 8, 3, b);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        p[0x14] = 0;
        p[0x15] = 0;
        p[0x16] = (u8)a;
        p[0x17] = (u8)(a >> 8);
        p[0x18] = (u8)c;
        p[0x19] = (u8)(c >> 8);
        p[0x1a] = 0;
        p[0x1b] = 0;
        fn_8024CB94(self, 0, p);
    }
}
void fn_8024EC80(u8 *self, u8 *arg) {
    u8 *p;
    u16 n;
    u8 *q;
    u8 t;
    n = 0;
    p = *(u8 **)(self + 0x10);
    t = p[0x31] + 1;
    p[0x31] = t;
    self[0x35] = t;
    if (arg[2] != 0) n = 4;
    if (arg[0x20] != 0) n += 4;
    if (arg[6] != 0) n += 0x18;
    if (arg[0x24] != 0) n += 0xB;
    p = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), (u16)(n + 4), 4, self[0x35]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        q = p + 0x18;
        p[0x14] = (u8)*(u16 *)(self + 0x16);
        p[0x15] = (u8)(*(u16 *)(self + 0x16) >> 8);
        p[0x16] = 0;
        p[0x17] = 0;
        if (arg[2] != 0) {
            q[0] = 1;
            q[1] = 2;
            q[2] = (u8)*(u16 *)(arg + 4);
            q[3] = (u8)(*(u16 *)(arg + 4) >> 8);
            q += 4;
        }
        if (arg[0x20] != 0) {
            q[0] = 2;
            q[1] = 2;
            q[2] = (u8)*(u16 *)(arg + 0x22);
            q[3] = (u8)(*(u16 *)(arg + 0x22) >> 8);
            q += 4;
        }
        if (arg[6] != 0) {
            q[0] = 3;
            q[1] = 0x16;
            q[2] = arg[8];
            q[3] = arg[9];
            q[4] = (u8)*(u32 *)(arg + 0xC);
            q[5] = (u8)(*(u32 *)(arg + 0xC) >> 8);
            q[6] = (u8)(*(u32 *)(arg + 0xC) >> 16);
            q[7] = (u8)(*(u32 *)(arg + 0xC) >> 24);
            q[8] = (u8)*(u32 *)(arg + 0x10);
            q[9] = (u8)(*(u32 *)(arg + 0x10) >> 8);
            q[10] = (u8)(*(u32 *)(arg + 0x10) >> 16);
            q[11] = (u8)(*(u32 *)(arg + 0x10) >> 24);
            q[12] = (u8)*(u32 *)(arg + 0x14);
            q[13] = (u8)(*(u32 *)(arg + 0x14) >> 8);
            q[14] = (u8)(*(u32 *)(arg + 0x14) >> 16);
            q[15] = (u8)(*(u32 *)(arg + 0x14) >> 24);
            q[16] = (u8)*(u32 *)(arg + 0x18);
            q[17] = (u8)(*(u32 *)(arg + 0x18) >> 8);
            q[18] = (u8)(*(u32 *)(arg + 0x18) >> 16);
            q[19] = (u8)(*(u32 *)(arg + 0x18) >> 24);
            q[20] = (u8)*(u32 *)(arg + 0x1C);
            q[21] = (u8)(*(u32 *)(arg + 0x1C) >> 8);
            q[22] = (u8)(*(u32 *)(arg + 0x1C) >> 16);
            q[23] = (u8)(*(u32 *)(arg + 0x1C) >> 24);
            q += 0x18;
        }
        if (arg[0x24] != 0) {
            q[0] = 4;
            q[1] = 9;
            q[2] = arg[0x26];
            q[3] = arg[0x27];
            q[4] = arg[0x28];
            q[5] = (u8)*(u16 *)(arg + 0x2A);
            q[6] = (u8)(*(u16 *)(arg + 0x2A) >> 8);
            q[7] = (u8)*(u16 *)(arg + 0x2C);
            q[8] = (u8)(*(u16 *)(arg + 0x2C) >> 8);
            q[9] = (u8)*(u16 *)(arg + 0x2E);
            q[10] = (u8)(*(u16 *)(arg + 0x2E) >> 8);
        }
        fn_8024CB94(*(void **)(self + 0x10), 0, p);
    }
}
void fn_8024EF78(u8 *self, u8 *cfg) {
    u16 len = 0;
    u8 *packet;
    u8 *p;
    if (cfg[2]) len = 4;
    if (cfg[0x20]) len += 4;
    if (cfg[6]) len += 0x18;
    if (cfg[0x24]) len += 0xB;
    packet = fn_8024E864(*(u16 *)(*(u8 **)(self + 0x10) + 0x28), (u16)(len + 6), 5, self[0x36]);
    if (packet == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
    } else {
        p = packet + 0x1A;
        packet[0x14] = *(u16 *)(self + 0x16);
        packet[0x15] = *(u16 *)(self + 0x16) >> 8;
        packet[0x16] = 0;
        packet[0x17] = 0;
        packet[0x18] = *(u16 *)cfg;
        packet[0x19] = *(u16 *)cfg >> 8;
        if (cfg[2]) {
            p[0] = 1;
            p[1] = 2;
            p[2] = *(u16 *)(cfg + 4);
            p[3] = *(u16 *)(cfg + 4) >> 8;
            p += 4;
        }
        if (cfg[0x20]) {
            p[0] = 2;
            p[1] = 2;
            p[2] = *(u16 *)(cfg + 0x22);
            p[3] = *(u16 *)(cfg + 0x22) >> 8;
            p += 4;
        }
        if (cfg[6]) {
            p[0] = 3;
            p[1] = 0x16;
            p[2] = cfg[8];
            p[3] = cfg[9];
            p[0x4] = *(u32 *)(cfg + 0xc);
            p[0x5] = *(u32 *)(cfg + 0xc) >> 8;
            p[0x6] = *(u32 *)(cfg + 0xc) >> 16;
            p[0x7] = *(u32 *)(cfg + 0xc) >> 24;
            p[0x8] = *(u32 *)(cfg + 0x10);
            p[0x9] = *(u32 *)(cfg + 0x10) >> 8;
            p[0xa] = *(u32 *)(cfg + 0x10) >> 16;
            p[0xb] = *(u32 *)(cfg + 0x10) >> 24;
            p[0xc] = *(u32 *)(cfg + 0x14);
            p[0xd] = *(u32 *)(cfg + 0x14) >> 8;
            p[0xe] = *(u32 *)(cfg + 0x14) >> 16;
            p[0xf] = *(u32 *)(cfg + 0x14) >> 24;
            p[0x10] = *(u32 *)(cfg + 0x18);
            p[0x11] = *(u32 *)(cfg + 0x18) >> 8;
            p[0x12] = *(u32 *)(cfg + 0x18) >> 16;
            p[0x13] = *(u32 *)(cfg + 0x18) >> 24;
            p[0x14] = *(u32 *)(cfg + 0x1c);
            p[0x15] = *(u32 *)(cfg + 0x1c) >> 8;
            p[0x16] = *(u32 *)(cfg + 0x1c) >> 16;
            p[0x17] = *(u32 *)(cfg + 0x1c) >> 24;
            p += 0x18;
        }
        if (cfg[0x24]) {
            p[0] = 4;
            p[1] = 9;
            p[2] = cfg[0x26];
            p[3] = cfg[0x27];
            p[4] = cfg[0x28];
            p[5] = *(u16 *)(cfg + 0x2A);
            p[6] = *(u16 *)(cfg + 0x2A) >> 8;
            p[7] = *(u16 *)(cfg + 0x2C);
            p[8] = *(u16 *)(cfg + 0x2C) >> 8;
            p[9] = *(u16 *)(cfg + 0x2E);
            p[10] = *(u16 *)(cfg + 0x2E) >> 8;
        }
        fn_8024CB94(*(u8 **)(self + 0x10), 0, packet);
    }
}
typedef struct Context { u8 pad[0x28]; u16 id; } Context;
typedef struct Channel { u8 pad[0x10]; Context *ctx; u8 pad2[2]; u16 id; u8 pad3[0x1e]; u8 ident; } Channel;
void fn_8024F270(Channel *ch, u8 *src, int len, int size) {
    u8 *packet, *start, *out, *end;
    int n, a, b;
    u8 optlen, type;
    u16 total;
    packet = fn_8022EFF8(2);
    if (packet == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, "L2CAP - no buffer for cfg_rej");
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
void fn_8024F424(u8 *self) {
    u8 *p;
    u8 v;
    v = (*(u8**)(self + 0x10))[0x31] + 1;
    (*(u8**)(self + 0x10))[0x31] = v;
    self[0x35] = v;
    p = fn_8024E864(*(u16*)(*(u8**)(self + 0x10) + 0x28), 4, 6, v);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        p[0x14] = *(u16*)(self + 0x16);
        p[0x15] = *(u16*)(self + 0x16) >> 8;
        p[0x16] = *(u16*)(self + 0x14);
        p[0x17] = *(u16*)(self + 0x14) >> 8;
        *(u16*)(p + 6) = 0;
        fn_8022F500(*(u8**)(self + 0x10) + 0x44, p);
        fn_8024CB94(*(u8**)(self + 0x10), 0, 0);
    }
}
void fn_8024F4F8(u8 *self, u32 a, int b, u32 c) {
    u8 *p = fn_8024E864(*(u16 *)(self + 0x28), 4, 7, a);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        p[0x14] = b;
        p[0x15] = b >> 8;
        p[0x16] = c;
        p[0x17] = c >> 8;
        *(u16 *)(p + 6) = 0;
        fn_8022F500(self + 0x44, p);
        fn_8024CB94(self, 0, 0);
    }
}
void fn_8024F5B8(u8 *self, u8 *src, int len) {
    u8 *p;
    u8 *dst;
    int i;
    p = fn_8024E864(*(u16 *)(self + 0x28), (u32)len, 8, ++self[0x31]);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for echo_req");
        }
    } else {
        dst = p + 0x14;
        if (len != 0) {
            for (i = 0; i < len; i++) {
                u8 *s = src + i;
                *dst++ = *s;
            }
        }
        fn_8024CB94(self, 0, p);
    }
}
void fn_8024F728(u8 *self, u32 a, u8 *buf, u32 size) {
    u16 lim;
    u8 *p;
    u8 *dst;
    int i;
    if (*(u16 *)(lbl_805297D0 + 0x7E) < 0x294)
        lim = *(u16 *)(lbl_805297D0 + 0x7C);
    else
        lim = 0x294;
    if (size > (u16)(lim - 12))
        size = 0;
    p = fn_8024E864(*(u16 *)(self + 0x28), size, 9, a);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2)
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
    } else {
        dst = p + 0x14;
        if (size != 0) {
            for (i = 0; i < (int)size; i++)
                *dst++ = buf[i];
        }
        fn_8024CB94(self, 0, p);
    }
}
void fn_8024F8C4(u8 *self, u32 a, u32 b) {
    u8 *p;
    p = fn_8024E864(*(u16 *)(self + 0x28), 4, 0xB, a);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, "L2CAP - no buffer for conn_req");
        }
    } else {
        p[0x14] = (u8)b;
        p[0x15] = (u8)(b >> 8);
        p[0x16] = 1;
        p[0x17] = 0;
        fn_8024CB94(self, 0, p);
    }
}
