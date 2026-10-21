#pragma force_active on
typedef unsigned short u16;

extern void fn_803BC090(void);
extern void fn_803B1AA4(void *);
extern int fn_803B02D4(void *);
extern void fn_803B032C(void *);
extern int fn_803AA7D0(void *, int);
extern char lbl_8053B248[];

static inline int finish(char *self, int flags)
{
    int status = fn_803AA7D0(self, flags);

    if (status != 0)
        return status;

    if (*(u16 *)(self + 0x1878) & 2)
        *(int *)(self + 0x1618) = 0;

    *(u16 *)(self + 0x1878) &= ~2;
    return 0;
}

int fn_803C0838(char *self, int arg1)
{
    int result = 0;
    int status;

    if (!(*(u16 *)(self + 0x1878) & 2))
        return 9;

    fn_803BC090();
    fn_803B1AA4(self);
    status = fn_803B02D4(self);

    if (status != 0)
        result = status;

    if (status == 0 || (arg1 & 1)) {
        fn_803B032C(self);
        status = finish(self, arg1);
        if (status != 0 && result == 0)
            result = status;
    }

    if (result == 0 || (arg1 & 1))
        --*(int *)(lbl_8053B248 + 0x10);

    return result;
}
