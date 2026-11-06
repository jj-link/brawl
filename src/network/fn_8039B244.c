#include <string.h>
#pragma force_active on
extern int lbl_805A1170;
extern char lbl_8059FCE8[5];
extern char lbl_80491CA8[];
extern char lbl_80491CB8[];
extern int fn_8039A260(void);
extern int fn_8039A274(void);
extern int fn_8039C984(int, unsigned int **);
extern char *fn_80399A58(void);
extern int fn_80397664(char *, unsigned int);
extern void fn_80397DE0(int, char *, ...);
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, unsigned int, int);
extern int fn_80398A08(void *, int, void *);
extern int fn_80398BD8(void *, int, void *);
extern int fn_8039B4C8(void *);
extern void fn_8039D0EC(void *, int);

int fn_8039B244(int arg0, int arg1, unsigned int arg2) {
    char work[0x9c];
    unsigned int *p;
    unsigned int offset;
    int status;
    unsigned int *entry;
    int base;
    char *name;
    int result, close_result;
    unsigned int count = 0;

    if (fn_8039A260() == 0 && fn_8039A274() == 0) return -9;
    entry = (unsigned int *)(lbl_805A1170 + 0x1800);
    memset(entry, 0, 0x80);
    if (arg2 == 0) return -28;
    result = fn_8039C984(arg1, &p);
    if (result != 0) return result;
    base = lbl_805A1170 + 0x800;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 14 > 0x100) {
        result = -11;
    } else {
        switch (arg1) {
        case 0:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CA8);
            goto success;
        case 1:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CB8);
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
    result = fn_8039832C(work, base, 4);
    if (result != 0) return result;
    status = -13;
    for (offset = 0x80; offset < p[5]; offset += 0x80) {
        int r = fn_80398818(work, offset, 0);
        if (r != 0) { status = r; break; }
        r = fn_80398A08(entry, 0x80, work);
        if (r != 0) { status = r; break; }
        if (entry[0] != 0) {
            count++;
            if (entry[0] == arg2) {
                status = -28;
                if (fn_8039A274() != 0) status = 0;
                else if (fn_8039B4C8(entry) != 0) status = 0;
                break;
            }
        }
    }
    if (status == -13 && p[2] != count) {
        p[2] = count;
        offset = (unsigned int)p;
        if (fn_80398818(work, 0, 0) == 0)
            fn_80398BD8((void *)offset, 0x80, work);
    }
    close_result = fn_80398680(work);
    if (status != 0) {
        if (arg2 == 0) status = -3;
        return status;
    }
    if (close_result != 0) return close_result;
    fn_8039D0EC(entry, arg0);
    return status;
}