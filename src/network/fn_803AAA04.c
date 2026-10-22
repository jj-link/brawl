#pragma force_active on
extern int fn_803AD644(void*, int, int, int, unsigned short, int);
extern int fn_803ADD34(int);
extern char lbl_8053B248[];

int fn_803AAA04(char* arg0, int a1, int a2, int a3, int a4) {
    int r;
    int t;

    if (arg0 == 0) {
        return 10;
    }
    r = fn_803AD644(*(void**)(arg0 + 0x188C), a1, a2, a3, *(unsigned short*)arg0, a4);
    if (r != 0) {
        if (r == 0x15) {
            t = fn_803ADD34(*(int*)(arg0 + 0x188C));
            *(int*)(lbl_8053B248 + 0x20) = t;
            *(int*)(arg0 + 0x1870) = t;
            return 0x1000;
        }
        return -1;
    }
    return 0;
}
