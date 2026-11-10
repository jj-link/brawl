#include <types.h>
#pragma force_active on

extern int lbl_805A1170;
extern char lbl_8059FCE8[5];
extern char lbl_80491CA8[14];
extern char lbl_80491CB8[14];
extern int fn_8039C984(int, int *);
extern char *fn_80399A58(void);
extern int fn_80397664(char *, unsigned int);
extern void fn_80397DE0(int, char *, ...);
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398BD8(int, int, void *);

int fn_8039BF0C(int arg0)
{
    int handle;
    int sp8;
    int context[0x29];
    char *name;
    int base;
    int result;
    int temp;
    int status;

    result = fn_8039C984(arg0, &sp8);
    if (result != 0) {
        return result;
    }

    base = lbl_805A1170 + 0x800;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 0xe > 0x100) {
        result = -11;
    } else {
        switch (arg0) {
        case 0:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CA8);
            goto success;
        case 1:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CB8);
            goto success;
        default:
            result = -3;
            goto done;
        }
    success:
        result = 0;
    done:
        ;
    }
    if (result != 0) {
        return result;
    }

    result = fn_8039832C(context, base, 4);
    if (result != 0) {
        return result;
    }

    handle = sp8;
    temp = fn_80398818(context, 0, 0);
    if (temp != 0) {
        status = temp;
    } else {
        status = fn_80398BD8(handle, 0x80, context);
    }

    result = fn_80398680(context);
    if (status != 0) {
        result = status;
    }
    return result;
}
