#pragma force_active on
#include <revolution/VF/pf_critical.h>
extern int fn_803D620C(s8);
extern int fn_803D6D64(void *);
extern int fn_803D6D70(void *);
extern void fn_803D6D7C(void *);
extern int fn_803D6D8C(void *);
extern void fn_803D6D98(void *);
extern int fn_803D70F0(void *, int);
extern void fn_803DBFD0(void *);
extern void fn_803E5500(void *);
extern int fn_803E94E8(void *);
extern int fn_803E96F4(void *, int);
extern char lbl_805644C0[];

static inline char *get_entry(s8 letter)
{
    s16 idx = fn_803D620C(letter) - 0x41;
    PF_enterCritical(lbl_805644C0 + 0x64);
    if (idx < 0 || idx >= 26) {
        PF_exitCritical(lbl_805644C0 + 0x64);
        return 0;
    }
    PF_exitCritical(lbl_805644C0 + 0x64);
    {
        char *base = lbl_805644C0;
        base = base + idx * 0x1FC8;
        return base + 0xA0;
    }
}
static inline int finish(char *self, int flags)
{
    int status = fn_803D70F0(self, flags);
    if (status != 0) return status;
    if (*(u16 *)(self + 0x1F8C) & 8) {
        *(int *)(self + 0x1654) = 0;
        *(int *)(self + 0x189C) = 0;
        *(int *)(self + 0x1AE4) = 0;
        *(int *)(self + 0x1D2C) = 0;
    }
    *(u16 *)(self + 0x1F8C) &= ~8;
    return 0;
}
static inline void unmount(char *self)
{
    if (fn_803D6D8C(self) && !(*(u16 *)(self + 0x1F8C) & 8)) {
        fn_803E5500(self);
        fn_803DBFD0(self);
        finish(self, 1);
        fn_803D6D98(self);
        --*(int *)(lbl_805644C0 + 0x34);
    }
}
static inline int mount(char *self)
{
    if (!(*(u16 *)(self + 0x1F8C) & 8)) {
        int status = fn_803E94E8(self);
        if (status != 0) return status;
        *(u16 *)(self + 0x1FAC) &= 0xFFF8;
        fn_803D6D98(self);
        ++*(int *)(lbl_805644C0 + 0x34);
    }
    fn_803D6D7C(self);
    return 0;
}
static inline int prepare(char *self)
{
    if (fn_803D6D64(self)) {
        unmount(self);
        if (fn_803D6D70(self)) {
            int status = mount(self);
            if (status != 0) return status;
        }
    } else {
        unmount(self);
        if (fn_803D6D70(self)) fn_803D6D7C(self);
    }
    return 0;
}
int fn_803EAAE4(s8 arg0, s32 arg1)
{
    s32 acc;
    char *self;
    int status;
    int ret;
    acc = 0;
    self = get_entry(arg0);
    if (!(*(u16 *)(self + 0x1F8C) & 1)) {
        *(int *)(lbl_805644C0 + 0x40) = 0xa;
        return 0xa;
    }
    PF_enterCritical(self + 0x1F90);
    status = prepare(self);
    if (status != 0) {
        PF_exitCritical(self + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = status;
        *(int *)(self + 0x1F80) = status;
        return status;
    }
    if (!(*(u16 *)(self + 0x1F8C) & 8)) {
        PF_exitCritical(self + 0x1F90);
        return 0;
    }
    if (((int)*(int *)(self + 0x161C) != 0) || ((int)*(int *)(self + 0x1620) != 0)) {
        acc = 1;
        *(int *)(lbl_805644C0 + 0x40) = 0x13;
        *(int *)(self + 0x1F80) = 0x13;
        if (!(arg1 & 1)) {
            PF_exitCritical(self + 0x1F90);
            return 0x13;
        }
    }
    ret = fn_803E96F4(self, arg1);
    if ((ret != 0) && (acc == 0)) {
        acc = 1;
        *(int *)(lbl_805644C0 + 0x40) = ret;
        *(int *)(self + 0x1F80) = ret;
        if (!(arg1 & 1)) {
            acc = ret;
        }
    }
    PF_exitCritical(self + 0x1F90);
    return acc;
}