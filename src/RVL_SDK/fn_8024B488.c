#pragma force_active on
typedef unsigned short u16;
typedef struct Callbacks {
    char pad[8];
    void (*error)(u16, u16);
    void (*notify)(int);
    char pad10[8];
    void (*disconnect)(u16, int);
} Callbacks;
typedef struct Obj {
    char pad0[4];
    int state;
    char pad8[12];
    u16 cid;
    u16 value;
    char timer[0x18];
    Callbacks *cb;
} Obj;
extern unsigned char lbl_8052CDC0[];
extern char jumptable_80483008[];
extern void fn_802319FC(int, char *, int);
extern void fn_802319E4(int, char *);
extern void fn_80231A14(int, char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024FA74(void *);
extern void fn_8022F0E0(void *);

void fn_8024B488(Obj *obj, u16 event, unsigned short *arg) {
    char *base = jumptable_80483008;
    Callbacks *cb = obj->cb;
    void (*disconnect)(u16, int) = cb->disconnect;
    void (*error)(u16, u16) = cb->error;
    u16 cid = obj->cid;
    if (lbl_8052CDC0[0] >= 4)
        fn_802319FC(0x80003, base + 0x294, event);
    switch (event) {
    case 3:
        obj->state = 0;
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x40, obj->cid);
        fn_8024FA74(obj);
        disconnect(cid, 0);
        break;
    case 11:
        obj->value = arg[7];
        obj->state = 5;
        fn_80231FB0(obj->timer, 3, 30);
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x2bc, obj->cid);
        obj->cb->error(obj->cid, 0);
        break;
    case 12:
        fn_80231FB0(obj->timer, 3, 120);
        if (obj->cb->notify) {
            if (lbl_8052CDC0[0] >= 3)
                fn_802319E4(0x80002, base + 0x2f4);
            obj->cb->notify(0);
        }
        break;
    case 13:
        if (lbl_8052CDC0[0] >= 3)
            fn_80231A14(0x80002, base + 0x318, obj->cid, arg[5]);
        fn_8024FA74(obj);
        error(cid, arg[5]);
        break;
    case 30:
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x358, obj->cid);
        fn_8024FA74(obj);
        error(cid, 0xeeee);
        break;
    case 26:
        fn_8024FA74(obj);
        break;
    case 19:
    case 29:
        fn_8022F0E0(arg);
        break;
    }
}