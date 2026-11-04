#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    u8 state;
    u8 flags;
    u8 pad[30];
    u16 mtu;
} Object;

typedef struct Config {
    u16 a;
    u8 b;
    u8 pad;
    u16 mtu;
    u8 pad2[26];
    u8 c;
} Config;

extern Object *fn_8025AEE4(int);
extern void fn_802319FC(int, const char *, int);
extern void fn_8024A9AC(int, Config *);
extern void fn_8025860C(Object *);
extern void fn_80231FB0(void *, int, int);
extern u8 lbl_8052D9C0[];
extern char lbl_80484F18[];
extern char lbl_80484F44[];

void fn_80259A5C(int arg0, Config *arg1)
{
    Object *obj = fn_8025AEE4(arg0);
    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, lbl_80484F18, arg0);
        }
    } else {
        if (arg1->b == 0) {
            obj->mtu = 0x100;
        } else if (arg1->mtu > 0x100U) {
            obj->mtu = 0x100;
        } else {
            obj->mtu = arg1->mtu;
        }
        arg1->c = 0;
        arg1->b = 0;
        arg1->a = 0;
        fn_8024A9AC(arg0, arg1);
        if (lbl_8052D9C0[0x4630] >= 4U) {
            fn_802319FC(0xA0003, lbl_80484F44, arg0);
        }
        obj->flags |= 2;
        if (obj->flags & 4) {
            obj->state = 3;
            if (obj->flags & 1) {
                fn_8025860C(obj);
            } else {
                fn_80231FB0((u8 *)obj + 8, 5, 30);
            }
        }
    }
}