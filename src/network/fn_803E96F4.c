#pragma force_active on
typedef unsigned short u16;
extern void fn_803E5500(void *);
extern void fn_803DBFD0(void *);
extern int fn_803DA954(void *);
extern void fn_803DA9AC(void *);
extern int fn_803D70F0(void *, int);
extern void fn_803D6D7C(void *);
extern void fn_803D6D98(void *);
extern char lbl_805644C0[];

static inline int finish(char *self, int flags)
{
    int status = fn_803D70F0(self, flags);
    if (status != 0)
        return status;
    if (*(u16 *)(self + 0x1F8C) & 8) {
        *(int *)(self + 0x1654) = 0;
        *(int *)(self + 0x189C) = 0;
        *(int *)(self + 0x1AE4) = 0;
        *(int *)(self + 0x1D2C) = 0;
    }
    *(u16 *)(self + 0x1F8C) &= ~8;
    return 0;
}
int fn_803E96F4(char *self, int flags)
{
    int result = 0;
    int status;
    if (!(*(u16 *)(self + 0x1F8C) & 8))
        return 9;
    fn_803E5500(self);
    fn_803DBFD0(self);
    status = fn_803DA954(self);
    if (status != 0)
        result = status;
    if (status == 0 || (flags & 1)) {
        fn_803DA9AC(self);
        status = finish(self, flags);
        if (status != 0 && result == 0)
            result = status;
    }
    if (result == 0 || (flags & 1)) {
        fn_803D6D7C(self);
        fn_803D6D98(self);
        --*(int *)(lbl_805644C0 + 0x34);
    }
    return result;
}