#pragma force_active on
extern char lbl_8053B248[];

extern void *fn_803A976C(void *dest, int value, unsigned int size);
extern int fn_803AA4E8(void *obj);
extern int fn_803AA514(void *obj);
extern int fn_803AA56C(void *obj);
extern int fn_803AA7D0(void *obj, int arg);
extern void fn_803AFB84(void *obj, unsigned int a, unsigned int b, unsigned short c, unsigned short d);
extern void fn_803AFB98(void *obj, unsigned int v);
extern void fn_803AFBA8(void *obj, unsigned int v);
extern void fn_803B032C(void *obj);
extern void fn_803B1AA4(void *obj);
extern void fn_803BC090(void *obj);
extern int fn_803C06B8(void *obj);

static inline void unmount(char *self)
{
    if (*(unsigned short *)(self + 0x1878) & 2) {
        fn_803BC090(self);
        fn_803B1AA4(self);
        fn_803B032C(self);
        if (fn_803AA7D0(self, 1) == 0) {
            if (*(unsigned short *)(self + 0x1878) & 2)
                *(int *)(self + 0x1618) = 0;
            *(unsigned short *)(self + 0x1878) &= ~2;
        }
        --*(int *)(lbl_8053B248 + 0x10);
    }
}
static inline int mount(char *self)
{
    if (!(*(unsigned short *)(self + 0x1878) & 2)) {
        int status = fn_803C06B8(self);
        if (status != 0) return status;
        *(unsigned short *)(self + 0x187c) &= 0xfff8;
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
        if (*(unsigned short *)(self + 0x1878) & 2) {
            if (fn_803AA514(self)) {
                fn_803BC090(self);
                fn_803B1AA4(self);
                fn_803B032C(self);
                if (fn_803AA7D0(self, 1) == 0) {
                    if (*(unsigned short *)(self + 0x1878) & 2)
                        *(int *)(self + 0x1618) = 0;
                    *(unsigned short *)(self + 0x1878) &= ~2;
                }
                --*(int *)(lbl_8053B248 + 0x10);
            }
            *(unsigned short *)(self + 0x1878) &= ~2;
        }
    }
    return 0;
}

int fn_803C19B0(char *arg0)
{
    char *p4;
    int idx;
    char *obj;
    char *e;
    unsigned int va;
    unsigned int vb;
    unsigned short nf;
    int ctr;
    int r;

    if (arg0 == 0 ||
        (p4 = *(char **)(arg0 + 4), *(unsigned short *)(p4 + 8) < 1) ||
        *(unsigned short *)(p4 + 0xA) < 2 ||
        (va = *(unsigned int *)(p4 + 0)) == 0 ||
        (vb = *(unsigned int *)(p4 + 4)) == 0 ||
        (va & 3) != 0 ||
        (vb & 3) != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    if (*(unsigned int *)(p4 + 0xC) == 0) {
        *(unsigned int *)(p4 + 0xC) = 1;
    }
    p4 = *(char **)(arg0 + 4);
    if (*(unsigned int *)(p4 + 0x10) == 0) {
        *(unsigned int *)(p4 + 0x10) = 1;
    }
    p4 = *(char **)(arg0 + 4);
    r = *(unsigned short *)(p4 + 8) / *(unsigned int *)(p4 + 0xC);
    if ((unsigned int)r < 1) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    r = *(unsigned short *)(p4 + 0xA) / *(unsigned int *)(p4 + 0x10);
    if ((unsigned int)r < 2) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    arg0[9] = 0;
    e = lbl_8053B248 + 0x48;
    idx = 0;
    arg0[8] = 0;
    for (idx = 0; idx < 26; idx++) {
        obj = e;
        if (!(*(unsigned short *)(obj + 0x1878) & 1)) break;
        e += 0x1898;
    }

    if (idx < 0 || idx >= 26 || *(int *)(lbl_8053B248 + 0xC) < 0 || *(int *)(lbl_8053B248 + 0xC) >= 26) {
        *(int *)(lbl_8053B248 + 0x1c) = 4;
        return 4;
    }

    *(int *)(obj + 0x38) = -1;
    *(int *)(obj + 0x3c) = -1;
    fn_803A976C(obj, 0, 0x1898);
    *(int *)(obj + 0x188c) = *(int *)arg0;
    obj[0x187a] = (short)idx + 0x41;
    *(int *)(obj + 0x1860) = 1;
    *(char **)(obj + 0x1868) = obj + 0x1864;
    {
        int temp = fn_803AA56C(obj);
        if (temp != 0) {
            r = temp;
        } else {
            p4 = *(char **)(arg0 + 4);
            fn_803AFB84(obj, *(unsigned int *)p4, *(unsigned int *)(p4 + 4), *(unsigned short *)(p4 + 8), *(unsigned short *)(p4 + 0xA));
            fn_803AFB98(obj, *(unsigned int *)(*(char **)(arg0 + 4) + 0xC));
            fn_803AFBA8(obj, *(unsigned int *)(*(char **)(arg0 + 4) + 0x10));
            r = 0;
        }
    }
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        return r;
    }

    *(unsigned short *)(obj + 0x1878) = (unsigned short)(*(unsigned short *)(obj + 0x1878) | 1);
    arg0[9] |= 1;
    obj[0x187a] = idx + 0x41;
    arg0[8] = idx + 0x41;
    *(int *)(lbl_8053B248 + 0xC) = *(int *)(lbl_8053B248 + 0xC) + 1;

    r = prepare(obj);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
        return 0;
    }
    if (fn_803AA4E8(obj) != 0) {
        r = mount(obj);
        if (r != 0) {
            *(int *)(lbl_8053B248 + 0x1c) = r;
            *(int *)(obj + 0x186c) = r;
            return 0;
        }
        arg0[9] |= 2;
    }
    return 0;
}
