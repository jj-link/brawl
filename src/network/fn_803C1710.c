#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
extern int fn_803A962C(s8);
extern int fn_803AA4E8(void *);
extern int fn_803AA514(void *);
extern int fn_803AA7D0(void *, int);
extern void fn_803B032C(void *);
extern void fn_803B1AA4(void *);
extern int fn_803B7540(void *, void *);
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
static inline int ready(char *self)
{
    int status;
    if (!self) return 10;
    status = prepare(self);
    if (status != 0) return status;
    return (*(u16 *)(self + 0x1878) & 2) ? 0 : 9;
}
int fn_803C1710(s8 arg0, char *out)
{
    s16 temp;
    char *self;
    char *base;
    int status;
    temp = fn_803A962C(arg0) - 0x41;
    if (temp < 0 || temp >= 26) self = 0;
    else {
        base = lbl_8053B248;
        base = base + temp * 0x1898;
        self = base + 0x48;
    }
    if (!self) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    if (!out) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(self + 0x186c) = 10;
        return 10;
    }
    status = ready(self);
    if (status != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = status;
        *(int *)(self + 0x186c) = status;
        return status;
    }
    *(int *)(out + 8) = *(u16 *)self;
    *(int *)(out + 12) = *(unsigned char *)(self + 6);
    *(int *)out = *(int *)(self + 0x34);
    status = fn_803B7540(self, out + 4);
    if (status != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = status;
        *(int *)(self + 0x186c) = status;
        return status;
    }
    return 0;
}