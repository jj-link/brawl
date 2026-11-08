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
extern int fn_803E16C8(void *, void *);
extern void fn_803E5500(void *);
extern int fn_803E94E8(void *);
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
static inline int ready(char *self)
{
    int status = prepare(self);
    if (status != 0) return status;
    return (*(u16 *)(self + 0x1F8C) & 8) ? 0 : 9;
}
int fn_803EA198(s8 arg0, char *out)
{
    char *self = get_entry(arg0);
    int status;
    PF_enterCritical(self + 0x1F90);
    status = ready(self);
    if (status != 0) {
        PF_exitCritical(self + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = status;
        *(int *)(self + 0x1F80) = status;
        return status;
    }
    *(int *)(out + 8) = *(u16 *)self;
    *(int *)(out + 12) = *(unsigned char *)(self + 6);
    *(int *)out = *(int *)(self + 0x34);
    status = fn_803E16C8(self, out + 4);
    if (status != 0) {
        PF_exitCritical(self + 0x1F90);
        *(int *)(lbl_805644C0 + 0x40) = status;
        *(int *)(self + 0x1F80) = status;
        return status;
    }
    PF_exitCritical(self + 0x1F90);
    return 0;
}