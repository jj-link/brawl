#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    u8 pad[0x414];
    void (*callback)(u16);
    u8 pad2[0x5A];
    u16 arg;
} Object;

extern Object *fn_8025AEE4(int);
extern void fn_8025AFE8(Object *);
extern void fn_802319FC(int, const char *, int);

extern u8 lbl_8052D9C0[];
extern char lbl_804850B8[];
extern char lbl_804850E8[];

void fn_8025A090(int arg0)
{
    Object *obj = fn_8025AEE4(arg0);

    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, lbl_804850B8, arg0);
        }
    } else {
        if (lbl_8052D9C0[0x4630] >= 4U) {
            fn_802319FC(0xA0003, lbl_804850E8, arg0);
        }

        if (obj->callback != 0) {
            obj->callback(obj->arg);
        }

        fn_8025AFE8(obj);
    }
}
