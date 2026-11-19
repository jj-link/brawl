#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Blob {
    u8 v[9];
} Blob;

typedef struct Entry {
    u8 pad0[0xD];
    u8 unkD;
    u8 pad1[0x51 - 0xE];
    Blob blk;
    u8 pad2[0x69 - 0x5A];
    u8 unk69;
} Entry;

typedef struct Req {
    u8 id;
    u8 pad0[0x11];
    u16 flags;
} Req;

extern Entry *fn_80251AD0(void *, u8);
extern void fn_80250BB0(void *, u8, u8 *, u16);
extern void fn_80250D00(void *, u8, u8 *, int);
extern void fn_802544C4(u8 *, Req *);
extern void fn_802552C0(void *, u8, int, u8 *, int);
extern void fn_8025640C(void *, int);
extern void fn_8025648C(void *);
extern void *memset(void *, int, unsigned int);

void fn_80253E64(void *arg0, int arg1, int arg2, Req *arg3)
{
    Blob buf;
    Entry *temp;

    temp = fn_80251AD0(arg0, arg3->id);
    if (temp == 0) {
        if (arg1 != 0) {
            memset(&buf, 0, 9);
            fn_802544C4(buf.v, arg3);
            fn_80250BB0(arg0, arg3->id, buf.v, arg3->flags);
        }
        return;
    }

    if (arg1 != 0 && arg2 != 0) {
        buf = temp->blk;
        fn_802552C0(arg0, arg3->id, 0, temp->blk.v, 0);
        return;
    }

    buf = temp->blk;
    fn_802544C4(buf.v, arg3);
    if (arg1 != 0) {
        fn_80250BB0(arg0, arg3->id, buf.v, arg3->flags);
        return;
    }

    temp = fn_80251AD0(arg0, arg3->id);
    if (temp != 0 && (temp->unk69 & 6)) goto valid;
    return;
valid:
    fn_8025648C(temp);
    if (temp->unk69 & 2) {
        temp->unk69 = temp->unk69 & ~2;
        temp->blk = buf;
        if (buf.v[5] == 0xC || buf.v[5] == 0x30) {
            arg3->flags = 0x3F7F;
        } else {
            temp->blk.v[5] = 0xC;
            temp->unk69 = temp->unk69 | 4;
            fn_802552C0(arg0, arg3->id, 1, temp->blk.v, 0xC00);
            fn_8025640C(temp, 0x3C);
            return;
        }
    } else {
        temp->unk69 = temp->unk69 & ~4;
    }

    if ((arg3->flags & 0xC00) == 0xC00 || (arg3->flags & 0x3000) == 0x3000) {
        fn_80250D00(arg0, temp->unkD, buf.v, 0);
        return;
    }
    if (temp->blk.v[5] == 0xC) {
        temp->blk.v[5] = 0x30;
        temp->unk69 = temp->unk69 | 4;
        fn_802552C0(arg0, arg3->id, 1, temp->blk.v, 0x3000);
        fn_8025640C(temp, 0x3C);
    } else if (temp->blk.v[5] == 0x30) {
        temp->blk.v[5] = 0;
        fn_80250D00(arg0, temp->unkD, buf.v, 0);
    }
done:
    ;
}
