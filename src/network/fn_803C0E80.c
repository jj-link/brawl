#pragma force_active on
typedef unsigned short u16;
extern int fn_803AA4E8(void *);
extern int fn_803AA514(void *);
extern int fn_803AA540(void *);
extern int fn_803AA7D0(void *, int);
extern void fn_803B032C(void *);
extern void fn_803B1AA4(void *);
extern void fn_803BC090(void *);
extern int fn_803C06B8(void *);
extern char lbl_8053B248[];

static inline void unmount(char *self)
{
    if (*(u16 *)(self + 0x1878) & 2) {
        fn_803BC090(self);
        fn_803B1AA4(self);
        fn_803B032C(self);
        if (fn_803AA7D0(self, 1) == 0) {
            if (*(u16 *)(self + 0x1878) & 2)
                *(int *)(self + 0x1618) = 0;
            *(u16 *)(self + 0x1878) &= ~2;
        }
        --*(int *)(lbl_8053B248 + 0x10);
    }
}
static inline int mount(char *self)
{
    if (!(*(u16 *)(self + 0x1878) & 2)) {
        int status = fn_803C06B8(self);
        if (status != 0) return status;
        *(u16 *)(self + 0x187c) &= 0xfff8;
        ++*(int *)(lbl_8053B248 + 0x10);
    }
    return 0;
}
static inline int prepare(char *self)
{
    if (fn_803AA4E8(self)) {
        if (fn_803AA514(self)) {
            int status;
            unmount(self);
            status = mount(self);
            if (status != 0) return status;
        }
    } else {
        if (*(u16 *)(self + 0x1878) & 2) {
            if (fn_803AA514(self)) {
                fn_803BC090(self);
                fn_803B1AA4(self);
                fn_803B032C(self);
                if (fn_803AA7D0(self, 1) == 0) {
                    if (*(u16 *)(self + 0x1878) & 2)
                        *(int *)(self + 0x1618) = 0;
                    *(u16 *)(self + 0x1878) &= ~2;
                }
                --*(int *)(lbl_8053B248 + 0x10);
            }
            *(u16 *)(self + 0x1878) &= ~2;
        }
    }
    return 0;
}
int fn_803C0E80(char *self)
{
    int status;
    if (!self) return 10;
    status = prepare(self);
    if (status != 0) return status;
    if (!(*(u16 *)(self + 0x1878) & 2)) return 9;
    return fn_803AA540(self) != 0 ? 11 : 0;
}