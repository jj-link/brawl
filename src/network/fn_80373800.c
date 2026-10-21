#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct W {
    u8* buf;
    u32 unk4;
    u32 pos;
};

void fn_80373800(struct W* w, u16 v) {
    w->buf[w->pos++] = (u8)(v >> 8);
    w->buf[w->pos++] = (u8)v;
}
