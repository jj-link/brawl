#pragma force_active on
extern int lbl_805A0C1C;
extern void *fn_802137A4(int, int, int);
extern int fn_80212A40(int, int, int, void *, void *);
extern void fn_80213C80(void);

int fn_802150CC(int a, int b, int c, int d, int e)
{
    char *obj;

    obj = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (obj == 0) {
        return -0x76;
    }
    *(int *)(obj + 0x100) = d;
    *(int *)(obj + 0x104) = e;
    *(int *)(obj + 0x108) = 0;
    return fn_80212A40(a, b, c, (void *)fn_80213C80, obj);
}
