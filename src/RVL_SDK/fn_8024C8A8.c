#pragma force_active on
extern void fn_8024AED0(void *, int, void *);
extern void *fn_8024E7C4();

int fn_8024C8A8(void) {
    char *p;
    char *q;

    p = fn_8024E7C4();
    if (p == 0) {
        return 0;
    }
    q = *(char **)(p + 0x8);
    while (q != 0) {
        if (*(int *)(*(char **)(q + 0x30) + 0x20) != 0) {
            fn_8024AED0(q, 6, 0);
        }
        q = *(char **)(q + 0x8);
    }
    return 1;
}
