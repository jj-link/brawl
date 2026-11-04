#pragma force_active on
extern "C" int fn_8007D1AC(void);
extern "C" void fn_8007C9DC(void);
extern "C" int fn_8007C168(void);
extern "C" void fn_8007C944(void);
extern "C" int fn_8007CB08(void);
extern "C" int fn_8007D028(int, int, int, int, int, int);
extern "C" void fn_8007D1BC(void);
extern "C" void fn_8007FE00(int, int, int, int, int, int, int);
extern "C" char g_thpObject[];
extern int lbl_8049DDB0[4];
extern int lbl_8059DBA0;
extern int lbl_8059DBA4;
extern int lbl_805A0214;
extern int lbl_805A0238;
extern int lbl_805A023C;
extern unsigned int lbl_805A0240;
extern unsigned char lbl_805A024E;
extern int lbl_805A0250;
extern int lbl_805A0254;

extern "C" int fn_8007EF70(int a1, int a2, int a3, int a4, int a5) {
    int ret = -1;
    int st;
    int t;
    unsigned int sum;
    unsigned int* e8;

    if (lbl_805A0214 != 0) {
        st = fn_8007D1AC();
        if (st == 5) {
            fn_8007C9DC();
            fn_8007C168();
            lbl_805A0214 = 0;
            return lbl_805A0238 - 1;
        }
        if (st == 3) {
            return lbl_805A0238 - 1;
        }
        if (lbl_805A024E != 0) {
            if (st == 2) {
                fn_8007CB08();
            }
        } else if (st == 4) {
            fn_8007C944();
        }
        if (a4 < 0) {
            a4 = lbl_8049DDB0[0];
        }
        if (a5 < 0) {
            a5 = lbl_8049DDB0[1];
        }
        if (lbl_805A0250 == 0) {
            ret = fn_8007D028(lbl_8059DBA0, lbl_8059DBA4, a2, a3, a4, a5);
            fn_8007D1BC();
        } else if (*(int*)(g_thpObject + 0xA0) != 0 &&
                   *(unsigned char*)(g_thpObject + 0xA4) != 0 &&
                   *(void**)(g_thpObject + 0xE8) != 0) {
            e8 = *(unsigned int**)(g_thpObject + 0xE8);
            fn_8007FE00(lbl_805A0250, lbl_805A0254, e8[0], e8[1], e8[2], a4, a5);
            e8 = *(unsigned int**)(g_thpObject + 0xE8);
            sum = e8[3] + *(unsigned int*)(g_thpObject + 0xC0);
            ret = sum % *(unsigned int*)(g_thpObject + 0x50);
            fn_8007D1BC();
            if (lbl_805A023C != ret) {
                lbl_805A023C = ret;
                lbl_805A0240 = 0;
            } else if (lbl_805A024E == 0) {
                t = lbl_805A0238 - 30;
                lbl_805A0240++;
                if (t < 0) {
                    t = 0;
                }
                if (lbl_805A023C >= t &&
                    (unsigned int)((lbl_805A0238 - lbl_805A023C) * 6) < lbl_805A0240) {
                    ret = lbl_805A0238 - 1;
                }
            }
        }
    }
    return ret;
}
