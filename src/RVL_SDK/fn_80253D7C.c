#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Owner {
    u8 pad[0x6C];
    u8 mode;
} Owner;

typedef struct Entry {
    u8 pad[0x69];
    u8 flags;
} Entry;

typedef struct Req {
    u8 id;
    u8 pad0[9];
    u8 a;
    u8 pad1[3];
    u16 b;
    u8 pad2;
    u8 c;
} Req;

extern unsigned char lbl_8052D5A8[];
extern char lbl_80484A08[];

extern void fn_80250678(Owner *, u8, u16, u8, u8);
extern void fn_80250828(Owner *, u16, u16, u32, u16);
extern void fn_80254BF4(Owner *, int, int);
extern void fn_802319E4(int, const char *);
extern void *fn_80251AD0(Owner *, u16);
extern void fn_8025648C(void *);

void fn_80253D7C(Owner *arg0, int arg1, Req *arg2)
{
    u8 id = arg2->id;

    if (arg1 != 0) {
        if (arg0->mode != 6) {
            fn_80250678(arg0, id, arg2->b, arg2->a, arg2->c);
            return;
        }
        fn_80254BF4(arg0, id, 0);
        if (lbl_8052D5A8[0x414] >= 2U) {
            fn_802319E4(0x90001, lbl_80484A08);
        }
    } else {
        Entry *e = fn_80251AD0(arg0, id);
        if (e == 0 || !(e->flags & 1)) {
            return;
        }
        e->flags = e->flags & 0xFE;
        fn_8025648C(e);
        fn_80250828(arg0, id, arg2->b, arg2->a, arg2->c);
    }
}
