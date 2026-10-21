#pragma force_active on
extern int fn_8035B1C4(void *, int *);
extern void fn_8035B120(void *, int);

void fn_803708EC(void **arg0, int arg1) {
    struct {
        int a[6];
    } s;
    int r;
    void *obj;

    obj = *arg0;
    s.a[0] = arg1;
    r = fn_8035B1C4(*(void **)((char *)obj + 0x444), &s.a[0]);
    if (r != 0) {
        fn_8035B120(*(void **)((char *)obj + 0x444), r);
    }
}
