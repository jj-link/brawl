#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Packet {
    u16 unk0;
    u16 length;
    u16 unk4;
    u16 unk6;
    u8 data[1];
} Packet;

extern void fn_80242908(void *);

void fn_80246EE4(Packet *p, int command, int count, u8 *src)
{
    u8 *dst;
    int i;

    command |= 0xFC00;
    p->length = count + 3;
    p->unk4 = 0;
    p->data[0] = command;
    p->data[1] = command >> 8;
    p->data[2] = count;
    dst = p->data + 3;

    for (i = 0; i < count; i++) {
        *dst++ = src[i];
    }

    fn_80242908(p);
}
