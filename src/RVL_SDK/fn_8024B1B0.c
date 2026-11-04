#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Callbacks {
    char pad[8];
    void (*error)(u16, int);
    char pad2[12];
    void (*disconnect)(u16, int);
} Callbacks;
typedef struct Obj {
    char pad0[4];
    int state;
    char pad8[8];
    char *ptr;
    u16 cid;
    char pad16[2];
    char timer[0x18];
    Callbacks *cb;
    char pad34[3];
    u8 flag;
} Obj;
extern u8 lbl_8052CDC0[];
extern char jumptable_80483008[];
extern void fn_802319FC(int, char *, int);
extern void fn_80231A14(int, char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024EA24(void *);
extern void fn_8024FA74(void *);
extern void fn_8022F0E0(int);
extern void fn_80240674(void *);

void fn_8024B1B0(Obj *obj, u16 event, int arg) {
    char *base = jumptable_80483008;
    Callbacks *cb = obj->cb;
    void (*disconnect)(u16, int) = cb->disconnect;
    void (*error)(u16, int) = cb->error;
    u16 cid = obj->cid;
    if (lbl_8052CDC0[0] >= 4)
        fn_802319FC(0x80003, base + 0x13c, event);
    switch (event) {
    case 3:
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x40, obj->cid);
        fn_8024FA74(obj);
        disconnect(cid, 0);
        break;
    case 7:
        obj->state = 3;
        fn_80231FB0(obj->timer, 3, 0x3c);
        fn_8024EA24(obj);
        obj->flag = 0;
        break;
    case 8:
        if (lbl_8052CDC0[0] >= 3)
            fn_80231A14(0x80002, base + 0x84, obj->cid, 5);
        fn_8024FA74(obj);
        error(cid, 5);
        break;
    case 19:
    case 29:
        fn_8022F0E0(arg);
        break;
    case 26:
        fn_80240674(obj->ptr + 0x2a);
        fn_8024FA74(obj);
        break;
    }
}