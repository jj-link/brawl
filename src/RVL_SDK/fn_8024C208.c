#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Packet { u16 event, len, offset; } Packet;
typedef struct Link { char pad[0x28]; u16 handle; } Link;
typedef struct Context { char pad[0x10]; Link *link; char pad14[2]; u16 cid; char pad18[0x58]; char queue[8]; u16 count; } Context;
extern void fn_8022F500(void *, void *);
extern Packet *fn_8022F77C(void *);
extern void fn_8022F0E0(void *);
extern void fn_802319FC(int, const char *, int);
extern void fn_8024CB94(void *, int, void *);
extern u8 lbl_805297D0[];
extern u8 lbl_8052CDC0[];
extern char lbl_80483818[];
void fn_8024C208(Context *self, Packet *packet) {
    u8 *p;
    if (packet != 0 && self->count != 0) {
        fn_8022F500(self->queue, packet);
        packet = fn_8022F77C(self->queue);
    } else if (packet == 0) {
        packet = fn_8022F77C(self->queue);
    }
    while (packet != 0) {
        if (packet->offset < 9) {
            if (lbl_8052CDC0[0] >= 1)
                fn_802319FC(0x80000, lbl_80483818, packet->offset);
            fn_8022F0E0(packet);
            packet = fn_8022F77C(self->queue);
        } else {
            packet->offset -= 8;
            p = (u8 *)(packet + 1) + packet->offset + 2;
            packet->len += 4;
            *p++ = self->link->handle | 0x2000;
            *p++ = (self->link->handle | 0x2000) >> 8;
            if (packet->len > *(u16 *)(lbl_805297D0 + 0x7c)) {
                *p++ = *(u16 *)(lbl_805297D0 + 0x7c);
                *p++ = *(u16 *)(lbl_805297D0 + 0x7c) >> 8;
            } else {
                *p++ = packet->len;
                *p++ = packet->len >> 8;
            }
            *p++ = packet->len - 4;
            *p++ = (packet->len - 4) >> 8;
            *p++ = self->cid;
            *p++ = self->cid >> 8;
            packet->len += 4;
            fn_8024CB94(self->link, 0, packet);
            packet = fn_8022F77C(self->queue);
        }
    }
}