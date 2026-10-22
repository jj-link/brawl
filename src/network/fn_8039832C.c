#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s32 id;
    u32 type;
    s32 state;
} Object;

extern s32 lbl_805A1160;
extern s32 lbl_805A115C;

extern s32 fn_8039A260(void);
extern s32 fn_8039A274(void);
extern s32 fn_80398558(Object *, s32, u32);
extern s32 fn_80398420(Object *, s32, u32);

s32 fn_8039832C(Object *arg0, s32 arg1, u32 arg2)
{
    s32 id;

    id = (lbl_805A1160 + 1) | 0x80000000;
    lbl_805A1160 = id;
    arg0->id = id;
    arg0->state = 0;
    arg0->type = arg2;

    if ((arg2 == 9 || arg2 == 10 || (u32)(arg2 - 0x109) <= 1) &&
        fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }

    if (arg2 == 9 || arg2 == 0x109) {
        if (lbl_805A115C != 0) {
            return -22;
        }
        lbl_805A115C = arg0->id;
    }

    if (arg2 & 0x100) {
        return fn_80398558(arg0, arg1, arg2);
    }

    return fn_80398420(arg0, arg1, arg2);
}
