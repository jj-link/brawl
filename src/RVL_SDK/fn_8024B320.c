#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Callback {
    u16 a;
    u16 b;
    void (*func)(void *, u16, u16, u8);
} Callback;

typedef struct Obj {
    char pad0[4];
    int state;
    char pad8[8];
    char *ptr;
    u16 a;
    u16 b;
    char timer[0x18];
    Callback *cb;
    char pad34[2];
    u8 c;
} Obj;

extern u8 lbl_8052CDC0[];
extern char lbl_804831D8[];
extern char lbl_80483200[];

extern void fn_802319FC(int, char *, int);
extern void fn_80240674(void *);
extern void fn_8024FA74(void *);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024EAE8(void *, int, int);
extern void fn_8022F0E0(int);
extern void fn_8024F4F8(void *, u8, u16, u16);

void fn_8024B320(Obj *arg0, u16 arg1, int arg2)
{
    Callback *cb;

    if (lbl_8052CDC0[0] >= 4U) {
        fn_802319FC(0x80003, lbl_804831D8, arg1);
    }

    switch (arg1) {
    case 3:
        fn_80240674(arg0->ptr + 0x2A);
        fn_8024FA74(arg0);
        break;

    case 7:
        arg0->state = 4;
        fn_80231FB0(arg0->timer, 3, 0x3C);
        if (lbl_8052CDC0[0] >= 3U) {
            fn_802319FC(0x80002, lbl_80483200, arg0->a);
        }
        cb = arg0->cb;
        cb->func(arg0->ptr + 0x2A, arg0->a, cb->b, arg0->c);
        break;

    case 8:
        fn_8024EAE8(arg0, 3, 0);
        fn_8024FA74(arg0);
        break;

    case 19:
    case 29:
        fn_8022F0E0(arg2);
        break;

    case 26:
        fn_8024FA74(arg0);
        break;

    case 17:
        fn_8024F4F8(arg0->ptr, arg0->c, arg0->a, arg0->b);
        fn_80240674(arg0->ptr + 0x2A);
        fn_8024FA74(arg0);
        break;
    }
}
