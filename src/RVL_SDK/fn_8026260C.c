#pragma force_active on
extern void fn_80261318();
extern void fn_8026171C();
extern void fn_80261E34();
extern void fn_8026541C();
extern void fn_802657A4();
extern void fn_802659C4();
extern void fn_80265AE0();
extern void fn_80265B24();
extern void fn_80265D48();
extern void fn_80265E6C();

int fn_8026260C(unsigned char *obj) {
    unsigned char *p;
    unsigned char n;
    int t;
    int v;

    p = *(unsigned char **)(obj + 0x19d0);
    switch (p[0x2c]) {
    case 1:
        *(int *)(obj + 0x1820) = 0x40;
        *(int *)(obj + 0x1824) = 0x40;
        *(void (**)())(obj + 0x180c) = fn_80261318;
        *(void (**)())(obj + 0x1810) = fn_8026171C;
        *(void (**)())(obj + 0x1814) = fn_80261E34;
        obj[0x19c8] = 8;
        break;
    case 2:
        *(int *)(obj + 0x1820) = 0x19;
        *(int *)(obj + 0x1824) = 0x6C;
        *(void (**)())(obj + 0x180c) = fn_802657A4;
        *(void (**)())(obj + 0x1810) = fn_80265B24;
        *(void (**)())(obj + 0x1814) = fn_8026541C;
        obj[0x19c8] = 4;
        break;
    case 4:
        *(int *)(obj + 0x1820) = 5;
        *(int *)(obj + 0x1824) = 0x24;
        *(void (**)())(obj + 0x180c) = fn_802659C4;
        *(void (**)())(obj + 0x1810) = fn_80265D48;
        *(void (**)())(obj + 0x1814) = fn_8026541C;
        obj[0x19c8] = 2;
        break;
    case 8:
        *(int *)(obj + 0x1820) = 1;
        *(int *)(obj + 0x1824) = 0;
        *(void (**)())(obj + 0x180c) = fn_80265AE0;
        *(void (**)())(obj + 0x1810) = fn_80265E6C;
        *(void (**)())(obj + 0x1814) = fn_8026541C;
        obj[0x19c8] = 1;
        break;
    default:
        return -0x70;
    }

    p[0x2e] = obj[0x17e8];
    *(int *)(p + 0x18) = *(int *)(obj + 0x17f0);
    *(unsigned short *)(p + 0x1c) = *(unsigned short *)(obj + 0x17ec);
    *(unsigned short *)(p + 0x1e) = *(unsigned short *)(obj + 0x17ee);
    n = p[0x2c];
    p[0x20] = (n + obj[0x17e9] - 1) / n;
    n = p[0x2c];
    p[0x21] = (n + obj[0x17ea] - 1) / n;
    n = p[0x2c];
    t = *(unsigned short *)(obj + 0x17dc);
    *(unsigned short *)(p + 0x30) = (t + n - 1) / n;
    n = p[0x2c];
    *(unsigned short *)(p + 0x32) = (n + *(unsigned short *)(obj + 0x17de) - 1) / n;
    n = p[0x2c];
    t = (n + obj[0x17f4] - 1) / n;
    p[0x22] = t;
    n = p[0x2c];
    p[0x23] = (n + obj[0x17f5] - 1) / n;
    if ((unsigned char)t != 0) {
        v = (*(unsigned short *)(p + 0x1c) - 1) * p[0x20];
    } else {
        v = (*(unsigned short *)(p + 0x1c) + 1) * p[0x20];
    }
    *(int *)(p + 0x24) = v;
    if (p[0x23] != 0) {
        v = (*(unsigned short *)(p + 0x1e) - 1) * p[0x21];
    } else {
        v = (*(unsigned short *)(p + 0x1e) + 1) * p[0x21];
    }
    *(int *)(p + 0x28) = v;

    switch (obj[0x17e8]) {
    case 4:
        *(unsigned short *)(p + 0x34) = *(unsigned short *)(p + 0x30);
        *(unsigned short *)(p + 0x36) = *(unsigned short *)(p + 0x32);
    case 5:
        break;
    case 1:
        *(unsigned short *)(p + 0x34) = (*(unsigned short *)(p + 0x30) + 1) / 2;
        *(unsigned short *)(p + 0x36) = *(unsigned short *)(p + 0x32);
        break;
    case 2:
        *(unsigned short *)(p + 0x34) = (*(unsigned short *)(p + 0x30) + 1) / 2;
        *(unsigned short *)(p + 0x36) = (*(unsigned short *)(p + 0x32) + 1) / 2;
        break;
    case 0:
        *(unsigned short *)(p + 0x34) = (*(unsigned short *)(p + 0x30) + 3) / 4;
        *(unsigned short *)(p + 0x36) = *(unsigned short *)(p + 0x32);
        break;
    case 3:
        *(unsigned short *)(p + 0x34) = *(unsigned short *)(p + 0x30);
        *(unsigned short *)(p + 0x36) = (*(unsigned short *)(p + 0x32) + 1) / 2;
        break;
    default:
        return -0x70;
    }
    return 0;
}
