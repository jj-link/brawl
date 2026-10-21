#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    u8 type;
    u8 pad[0x413];
    void (*callback)(u16);
} Object;

extern Object *fn_8025AEE4(int);
extern void fn_8025AFE8(Object *);
extern void fn_8024AB20(int);
extern void fn_802319FC(int, const char *, int);

extern u8 lbl_8052D9C0[];
extern char lbl_80484FB8[];
extern char lbl_80484FE4[];

void fn_80259D14(int arg0, int arg1)
{
    Object *obj = fn_8025AEE4(arg0);

    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, lbl_80484FB8, arg0);
        }
    } else {
        if (arg1 != 0) {
            fn_8024AB20(arg0);
        }

        if (lbl_8052D9C0[0x4630] >= 4U) {
            fn_802319FC(0xA0003, lbl_80484FE4, arg0);
        }

        if (obj->callback != 0) {
            obj->callback(obj->type == 3 ? 0 : 0xFFF1);
        }

        fn_8025AFE8(obj);
    }
}
