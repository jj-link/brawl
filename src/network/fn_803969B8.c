#pragma force_active on
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern void *fn_80397128(int a, int b);

int NHTTPGetResultCode(int arg0) {
    void *p;
    fn_803974FC();
    p = fn_80397128(fn_80397580(), arg0);
    if (p == 0) {
        return -1;
    }
    if (*(int *)((char *)p + 0x14) != 0) {
        return *(int *)((char *)p + 0x18);
    }
    return -1;
}