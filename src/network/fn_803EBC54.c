#include <string.h>
#pragma force_active on
typedef struct { int value; char pad[4]; signed char letter; unsigned char flags; } Item;
typedef struct { char data[0x4e]; int value; } Info;
typedef struct { Item *item; int zero; } Context;
extern int fn_803D72C0(int, int *);
extern int fn_803D72F8(int, int, Item *);
extern int fn_803EB528(Context *, void *);
extern int fn_803EE908(void);
extern int lbl_8059FF10;
extern int lbl_80597FB0[];
extern int lbl_80598018[];

int fn_803EBC54(unsigned int arg0, void *arg1, int arg2, Item *arg3) {
    int handle;
    Context ctx;
    Info info;
    int result;
    int index;
    if (arg0 >= 4) return -2;
    if (arg3 == 0) return -2;
    if (arg0 == 2 && arg1 == 0) return -2;
    if (arg0 == 3 && arg3->value == 0) return -2;
    if (arg0 <= 2) {
        if (fn_803D72C0(lbl_8059FF10 + ((unsigned char)arg0 * 8), &handle) != 0) return -1;
        if (fn_803D72F8(handle, 0, arg3) != 0) return -1;
    }
    ctx.item = arg3;
    ctx.zero = 0;
    if (arg0 == 2) {
        memcpy(&info, arg1, 0x4e);
        info.value = arg2;
    }
    if (arg0 == 2)
        result = fn_803EB528(&ctx, &info);
    else
        result = fn_803EB528(&ctx, 0);
    if (result != 0) return -1;
    index = arg3->letter - 0x41;
    if (arg0 <= 2) {
        lbl_80597FB0[index] = handle;
        lbl_80598018[index] = arg3->value;
        if (arg0 == 0 && fn_803EE908() != 0)
            ctx.item->flags |= 0x10;
    } else {
        lbl_80597FB0[index] = 0;
        lbl_80598018[index] = 0;
    }
    return 0;
}