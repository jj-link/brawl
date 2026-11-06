#include <types.h>
#pragma force_active on
typedef struct { void *unk0; void *unk4; } Obj;
extern int fn_803D6A50(int, void *, int, int, int);
extern void fn_803D674C(int, short);
extern unsigned short fn_803D68CC(int, int);
extern int fn_803DD968(void *, int);
extern int fn_803E9D60(void *, int);
extern int fn_803DE0C8(Obj *, int, int, int, int, int *);
extern char lbl_8059FED0[2];
extern char lbl_8059FED4[2];
extern char lbl_8059FED8[2];
extern char lbl_8059FEDC[4];
int fn_803DF5E4(Obj *arg0, int arg1, int arg2, int arg3, int arg4, int *arg5) {
    int temp;
    *arg5 = 0;
    if (arg3 & arg4) return 10;
    if (fn_803D6A50(arg2, lbl_8059FED0, 1, 1, 1) == 0)
        fn_803D674C(arg2, 2);
    if (fn_803D6A50(arg2, lbl_8059FED4, 1, 0, 1) == 0 ||
        fn_803D6A50(arg2, lbl_8059FED8, 1, 0, 1) == 0) {
        temp = fn_803DD968(arg0->unk4, arg1);
        if (temp != 0) return temp;
        if (fn_803D68CC(arg2, 1) == 1 &&
            fn_803D6A50(arg2, lbl_8059FEDC, 2, 0, 1) == 0)
            return 0;
    } else {
        temp = fn_803E9D60(arg0->unk4, arg1);
        if (temp != 0) return temp;
    }
    temp = fn_803DE0C8(arg0, arg1, arg2, arg3, arg4, arg5);
    return temp & ((-temp | temp) >> 31);
}