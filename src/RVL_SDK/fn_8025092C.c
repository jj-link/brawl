#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(int, u8);

typedef struct Obj {
    u8 id;
    u8 pad1;
    u8 state;
    u8 pad3[0x0f];
    u16 value;
    u16 mtu;
    u8 pad16[0x72];
    u32 flags;
    Cb cb1;
    Cb cb2;
} Obj;

extern u8 lbl_8052D5A8[];
extern char lbl_80483F84[];

extern Obj *fn_80251AD0(void *, u16);
extern Obj *fn_80251B24(u32);
extern void fn_80231A14(int, char *, int, int);
extern void fn_802545FC(void *, int, int, int);
extern void fn_802563B4(void *);

void fn_8025092C(void *arg0, u16 arg1, u32 arg2)
{
    Obj *obj;
    Cb cb;

    obj = fn_80251AD0(arg0, arg1);
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_80231A14(0x90003, lbl_80483F84, arg1, arg2);
    }
    if (obj == 0) {
        obj = fn_80251B24(arg1);
        if (obj == 0) {
            fn_802545FC(arg0, arg1, 0, 1);
            return;
        }
        ((u8 *)arg0 + arg1)[0x24] = obj->id;
    }
    if (arg2 != 0 && arg2 < obj->mtu) {
        obj->mtu = arg2;
    }
    fn_802563B4(arg0);
    fn_802545FC(arg0, arg1, obj->value, 0);
    cb = obj->cb1;
    if (cb != 0 && (obj->flags & 0x200)) {
        cb(0x200, obj->id);
    }
    cb = obj->cb2;
    if (cb != 0) {
        cb(0, obj->id);
    }
    obj->state = 2;
}
