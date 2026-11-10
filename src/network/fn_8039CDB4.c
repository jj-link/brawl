#pragma dead_store off
#include <types.h>
#pragma force_active on

extern int lbl_805A1170;
extern int lbl_805A1188[2];
extern char lbl_8059FCE8[5];
extern char lbl_80491CC8[];
extern char lbl_80491CD8[];
extern int lbl_8059FCF0;

extern int fn_8039C984(int, int **);
extern int fn_80399074(void *, int *);
extern int fn_80398FF4(void *);
extern char *fn_80399A58(void);
extern int fn_80397664(char *, unsigned int);
extern void fn_80397DE0(int, char *, ...);
extern int fn_80398EEC(void *, int);

static inline int cleanup(void)
{
    int value;
    int *object;
    int result;

    if (lbl_805A1188[0] == 0)
        return 0;

    if (--lbl_805A1188[0] > 0)
        return 0;

    result = fn_8039C984(lbl_805A1188[1], &object);
    if (result != 0)
        return result;

    result = fn_80399074(&lbl_8059FCF0, &value);
    if (result != 0)
        return result;

    object[9] = value;
    return fn_80398FF4(&lbl_8059FCF0);
}

int fn_8039CDB4(int arg) {
    char *name;
    int base;
    int result;

    if (lbl_805A1188[0] != 0 && lbl_805A1188[1] != arg) {
        lbl_805A1188[0] = 1;
        cleanup();
        return -1;
    }

    if (++lbl_805A1188[0] > 1) {
        return 0;
    }

    base = lbl_805A1170 + 0x800;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 14 > 0x100) {
        result = -11;
    } else {
        switch (arg) {
        case 0:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CD8);
            goto success;
        case 1:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CC8);
            goto success;
        default:
            result = -3;
            break;
        success:
            result = 0;
            break;
        }
    }
    if (result != 0) return result;
    result = fn_80398EEC(&lbl_8059FCF0, base);
    if (result != 0) return result;
    lbl_805A1188[1] = arg;
    return 0;
}
