#pragma force_active on

extern int lbl_805A1170;
extern char lbl_8059FCE8[5];
extern char lbl_80491CA8[];
extern char lbl_80491CB8[];
extern int fn_8039C984(int, unsigned int **);
extern char *fn_80399A58(void);
extern int fn_80397664(char *, unsigned int);
extern void fn_80397DE0(int, char *, ...);
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, unsigned int, int);
extern int fn_80398BD8(void *, int, void *);
extern int fn_8039CB7C(void *, int, void *);
extern int fn_8039C60C(void *, int, void *, int);

int fn_8039BD40(int arg0, int arg1) {
    char work[0x9c];
    unsigned int *p;
    unsigned int *q;
    char *name;
    int base;
    int status;
    int close;

    close = fn_8039C984(arg0, &p);
    if (close != 0) return close;
    if (p[2] == p[3]) return -6;
    base = lbl_805A1170 + 0x800;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 0xe > 0x100) {
        status = -0xb;
    } else {
        switch (arg0) {
        case 0:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CA8);
            goto success;
        case 1:
            fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CB8);
            goto success;
        default:
            status = -3;
            break;
        success:
            status = 0;
            break;
        }
    }
    if (status != 0) return status;
    close = fn_8039832C(work, base, 4);
    if (close != 0) return close;
    status = fn_8039CB7C(p, arg1, work);
    if (status == 0) {
        status = fn_8039C60C(p, arg1, work, arg0);
        if (status != 0) goto cleanup;
        goto shared;
    }
    if (status != -0xe) goto cleanup;
    p[0] = 0x42524B4E;
shared:
    q = p;
    close = fn_80398818(work, 0, 0);
    if (close != 0) {
        status = close;
    } else {
        status = fn_80398BD8(q, 0x80, work);
    }
cleanup:
    close = fn_80398680(work);
    if (status != 0) {
        close = status;
    }
    return close;
}
