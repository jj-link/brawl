#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    u8 type;
    u8 pad[0x21];
    u16 id;
    u8 pad2[0x3F0];
    void (*callback)(u16);
} Object;

extern Object *fn_8025AEE4(int);
extern void fn_8025AFE8(Object *);
extern void fn_8024A8F4(int, void *);
extern void fn_802319FC(int, void *, int);
extern void fn_80231A14(int, void *, int, int);

extern u8 lbl_8052D9C0[];
extern char lbl_80484DE0[];

void fn_802598CC(int arg0, unsigned arg1)
{
    char *s = lbl_80484DE0;
    Object *obj = fn_8025AEE4(arg0);

    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, s + 0xB0, arg0);
        }
    } else if (arg1 == 0 && obj->type == 1) {
        obj->type = 2;
        fn_8024A8F4(arg0, lbl_8052D9C0);
        if (lbl_8052D9C0[0x4630] >= 4U) {
            fn_802319FC(0xA0003, s + 0xDC, obj->id);
        }
    } else {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_80231A14(0xA0001, s + 0x108, arg1, obj->id);
        }
        if (obj->callback != 0) {
            if (arg1 == 14 || arg1 == 5 || arg1 == 24 || arg1 == 41 || arg1 == 6) {
                obj->callback(0xFFF6);
            } else if (arg1 == 15) {
                obj->callback(0xFFF7);
            } else {
                obj->callback(0xFFF1);
            }
        }
        fn_8025AFE8(obj);
    }
}
