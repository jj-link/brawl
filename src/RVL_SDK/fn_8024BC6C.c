#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char jumptable_80483008[];

extern void fn_802319FC(int, const char *, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern void fn_8024C208(void *, unsigned short *);
extern void fn_8024EC80(void *, unsigned short *);
extern void fn_8024EF78(void *, unsigned short *);
extern void fn_8024F424(void *);
extern void fn_8024FA74(void *);
extern unsigned char fn_8024FD88(void *, unsigned short *);
extern void fn_8024FF10(void *, unsigned short *);

typedef struct Callbacks {
    char pad[0x10];
    void (*event10)(unsigned short, unsigned short *);
    void *unk14;
    void (*event18)(unsigned short, int);
    void *unk1c;
    void (*event20)(void *);
    void (*event24)(unsigned short, unsigned short *);
} Callbacks;

typedef struct Object {
    char pad0[4];
    int state;
    char pad8[8];
    char *data;
    unsigned short id;
    char pad16[2];
    char timer[0x18];
    Callbacks *callbacks;
    unsigned char flag;
} Object;

void fn_8024BC6C(Object *obj, unsigned short event, unsigned short *arg)
{
    char *base = jumptable_80483008;
    void (*callback)(unsigned short, int) = obj->callbacks->event18;
    unsigned short id = obj->id;

    if (lbl_8052CDC0[0] >= 4)
        fn_802319FC(0x80003, base + 0x628, event);

    switch (event) {
    case 3:
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x40, obj->id);
        fn_8024FA74(obj);
        callback(id, 0);
        break;

    case 6:
        if (obj->callbacks->event20)
            obj->callbacks->event20(obj->data + 0x2a);
        break;

    case 14: {
        int oldstate = obj->state;
        unsigned char oldflag = obj->flag;

        obj->state = 5;
        obj->flag = 0;
        fn_80231FB0(obj->timer, 3, 30);
        if (fn_8024FD88(obj, arg)) {
            obj->callbacks->event10(obj->id, arg);
        } else {
            fn_80232020(obj->timer);
            obj->state = oldstate;
            obj->flag = oldflag;
            fn_8024EF78(obj, arg);
        }
        break;
    }

    case 17:
        obj->state = 8;
        fn_80231FB0(obj->timer, 3, 30);
        if (lbl_8052CDC0[0] >= 3)
            fn_802319FC(0x80002, base + 0x54c, obj->id);
        obj->callbacks->event18(obj->id, 1);
        break;

    case 19:
        obj->callbacks->event24(obj->id, arg);
        break;

    case 26:
        fn_8024F424(obj);
        obj->state = 7;
        fn_80231FB0(obj->timer, 3, 30);
        break;

    case 29:
        *arg = obj->id;
        fn_8024C208(obj, arg);
        break;

    case 23:
        fn_8024FF10(obj, arg);
        fn_8024EC80(obj, arg);
        obj->state = 5;
        obj->flag = 0;
        fn_80231FB0(obj->timer, 3, 30);
        break;
    }
}
