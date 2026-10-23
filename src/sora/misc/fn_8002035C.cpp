typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {
extern void OSReport(const char *, ...);
extern void OSSleepTicks(u64);
extern int fn_8001B8E0(int, int);
extern void fn_8001B9EC(void *, int);
extern int fn_8020A710(void *, int, int);
extern int fn_8020B9BC(void *, int, int);
extern char lbl_80420FC0[];

#pragma force_active on
int fn_8002035C(int arg0, int arg1) {
    char sp8[0x7C];
    char *base;
    int ret;
    int r25;
    int flag;
    int r26;
    u32 q;

    base = lbl_80420FC0;
    fn_8001B9EC(sp8, arg0);
    ret = 0;
    OSReport(base + 0x598, sp8);
    do {
        r25 = fn_8020B9BC(sp8, arg1, 2);
        flag = 0;
        if ((u32)r25 + 3 <= 1) {
            q = (*(u32 *)0x800000F8 / 4) / 1000;
            OSSleepTicks((u64)q << 4);
            flag = 1;
        } else if (r25 != -0xC) {
            fn_8001B8E0(r25, 0);
        }
    } while (flag != 0);

    if (r25 == 0) {
        ret = 1;
    } else {
        do {
            r26 = fn_8020A710(sp8, 0x34, 2);
            flag = 0;
            if ((u32)r26 + 3 <= 1) {
                q = (*(u32 *)0x800000F8 / 4) / 1000;
                OSSleepTicks((u64)q << 4);
                flag = 1;
            } else if (r26 != -0xC) {
                fn_8001B8E0(r26, 0);
            }
        } while (flag != 0);

        if (r26 != 0) {
            OSReport(base + 0x5B0, r26);
        } else {
            do {
                r25 = fn_8020B9BC(sp8, arg1, 2);
                flag = 0;
                if ((u32)r25 + 3 <= 1) {
                    q = (*(u32 *)0x800000F8 / 4) / 1000;
                    OSSleepTicks((u64)q << 4);
                    flag = 1;
                } else if (r25 != -0xC) {
                    fn_8001B8E0(r25, 0);
                }
            } while (flag != 0);

            if (r25 != 0) {
                OSReport(base + 0x2D0, r25);
            } else {
                ret = 1;
            }
        }
    }
    return ret;
}
}
