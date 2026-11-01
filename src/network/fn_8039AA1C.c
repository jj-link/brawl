#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void fn_80397748(void *, u32, u32);
extern void fn_803995F8(u32 *);
extern u32 fn_80399AC8(void);
extern u16 fn_80399B14(void);
extern void fn_80399CB8(void *);

s32 fn_8039AA1C(void *raw, s32 mode)
{
    u32 *a = (u32 *)raw;
    s32 selected = mode;
    u32 i;
    u32 *q;
    u32 *p;

    fn_80397748(a, 0, 0x100);
    a[0] = 0;
    a[1] = 0x100;
    a[3] = fn_80399AC8();
    a[6] = 0;
    a[5] = 0;
    ((u16 *)a)[0x65] = fn_80399B14();

    switch (selected) {
    case 0:
        a[1] |= 0xD;
        break;
    case 1:
        a[1] |= 5;
        break;
    case 2:
        a[1] |= 9;
        break;
    case 3:
        a[1] |= 1;
        break;
    case 4:
        a[1] |= 2;
        break;
    default:
        return -3;
    }

    a[10] = 0;
    a[1] |= 0x200000;
    a[11] = 0;
    fn_803995F8(a + 8);
    ((u8 *)a)[0xC8] = 0;

    p = a;
    q = a + 0x22;
    i = 0;
    do {
        if (selected == 4) {
            fn_80399CB8(q);
        } else {
            p[0x23] = 0;
            p[0x22] = 0;
        }
        i++;
        q += 2;
        p += 2;
    } while (i < 8);

    fn_80399CB8(a + 16);
    fn_80399CB8(a + 18);

    a[0x18] = 0;
    q = a;
    p = a + 0x1A;
    i = 0;
    a[0x19] = 0;
    ((u8 *)a)[0xC9] = 0;
    do {
        fn_80399CB8(p);
        q[0x1E] = 0;
        i++;
        p += 2;
        q[0x20] = 0x10000;
        q++;
    } while (i < 2);

    fn_80399CB8(a + 12);
    fn_80399CB8(a + 14);
    fn_80399CB8(a + 20);
    fn_80399CB8(a + 22);
    fn_80399CB8(a + 52);
    fn_80399CB8(a + 54);
    fn_80399CB8(a + 56);

    a[51] = 0;
    a[59] = 0;
    a[60] = 0x80000000;
    return 0;
}
