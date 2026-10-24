#include <types.h>
#pragma force_active on

typedef struct Obj {
    char pad0[0xC];
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[8];
    int unk2C;
} Obj;

extern Obj *fn_80377D90(Obj *, int, int);
extern int fn_80373FDC(Obj *self, Obj *other, int a2, int a3, int a4, int a5, int a6, int a7);
extern u32 fn_8035D728(void);
extern void fn_80374778(Obj *self);
extern int fn_80373AA0(Obj *self, int a1, int a2, int a3);
extern int fn_80373C54(Obj *self, int a1);

int fn_80376AAC(Obj *arg0, int arg1, int arg2) {
    Obj *temp_r31;
    int flag;

    temp_r31 = fn_80377D90(arg0, arg1, arg2);
    if (arg0->unk2C != 0 && fn_80373FDC(arg0, temp_r31, arg1, arg2, 1, 0, 0, 0) == 0) {
        return 0;
    }
    if (temp_r31 == 0) {
        return 1;
    }
    if (temp_r31->unkC == 0) {
        if (temp_r31->unk20 == 0 || (u32)(fn_8035D728() - temp_r31->unk1C) < (u32)temp_r31->unk20) {
            return 1;
        }
        if (temp_r31->unkC < 5) {
            if (temp_r31->unk10 != 0) {
                fn_80374778(temp_r31);
                if (fn_80373AA0(temp_r31, 6, 0, 0) == 0) {
                    flag = 0;
                    goto chk0;
                }
            } else {
                if (temp_r31->unkC == 4) {
                    temp_r31->unk14 = 1;
                }
                fn_80374778(temp_r31);
            }
        } else if (temp_r31->unkC != 7) {
            fn_80374778(temp_r31);
            if (fn_80373C54(temp_r31, 1) == 0) {
                flag = 0;
                goto chk0;
            }
        }
        flag = 1;
chk0:
        if (flag == 0) {
            return 0;
        }
    } else {
        if (temp_r31->unkC < 5) {
            if (temp_r31->unk10 != 0) {
                fn_80374778(temp_r31);
                if (fn_80373AA0(temp_r31, 2, 0, 0) == 0) {
                    flag = 0;
                    goto chk1;
                }
            } else {
                if (temp_r31->unkC == 4) {
                    temp_r31->unk14 = 1;
                }
                fn_80374778(temp_r31);
            }
        } else if (temp_r31->unkC != 7) {
            fn_80374778(temp_r31);
            if (fn_80373C54(temp_r31, 1) == 0) {
                flag = 0;
                goto chk1;
            }
        }
        flag = 1;
chk1:
        if (flag == 0) {
            return 0;
        }
    }
    return 1;
}
