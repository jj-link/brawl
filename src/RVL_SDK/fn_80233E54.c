#include <string.h>
#pragma force_active on
typedef unsigned char u8;
typedef struct {
    u8 addr[6];
    char name[0xf8];
    u8 value[3];
    u8 pad[15];
} Data;
extern u8 lbl_80529994[];
extern u8 lbl_805A0D30;
extern char lbl_8047FCE0[];
extern void fn_80232034(void *, const void *);
extern void fn_80233D94(void *);
extern u8 fn_8023C69C(const void *, void (*)(void *));
extern void fn_802319E4(int, const char *);

int fn_80233E54(const u8 *arg0, u8 *argarg1, const u8 *arg2) {
    Data data;
    u8 *arg1 = argarg1;
    if (*(void (**)(int, void *))(lbl_80529994 + 0x50) == 0)
        return 11;
    if (*arg2 == 0) {
        fn_80232034(lbl_80529994 + 0xf8, arg0);
        lbl_80529994[0xfe] = arg1[0];
        lbl_80529994[0xff] = arg1[1];
        lbl_80529994[0x100] = arg1[2];
        if (fn_8023C69C(arg0, fn_80233D94) == 1)
            return 1;
        if (lbl_805A0D30 >= 2)
            fn_802319E4(0x501, lbl_8047FCE0);
    }
    fn_80232034(data.addr, arg0);
    data.value[0] = arg1[0];
    data.value[1] = arg1[1];
    data.value[2] = arg1[2];
    strncpy(data.name, (const char *)arg2, 0x20);
    data.name[0x20] = 0;
    (*(void (**)(int, void *))(lbl_80529994 + 0x50))(2, &data);
    return 1;
}