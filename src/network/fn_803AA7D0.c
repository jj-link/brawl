#pragma force_active on
extern int fn_803AD1A4(int, int);
extern int fn_803ADD34(int);
extern char lbl_8053B248[];

int fn_803AA7D0(void* arg0, int arg1) {
    int result;

    if (arg0 == 0) {
        return 0xA;
    }

    result = fn_803AD1A4(*(int*)((char*)arg0 + 0x188C), (unsigned)__cntlzw(arg1 - 1) >> 5);

    if (result != 0) {
        if (result == 0x15) {
            int t = fn_803ADD34(*(int*)((char*)arg0 + 0x188C));
            *(int*)(lbl_8053B248 + 0x20) = t;
            *(int*)((char*)arg0 + 0x1870) = t;
            return 0x1000;
        }
        return -1;
    }
    return 0;
}
