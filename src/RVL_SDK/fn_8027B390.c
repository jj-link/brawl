#pragma force_active on
extern void fn_8021AEC4(int, int, void (*)(void));
extern void *memset(void *, int, unsigned long);
extern void fn_8027B1D4(void);

void fn_8027B390(unsigned char *arg0, int arg1) {
    if (arg0[0x1EC] != 0) {
        int off;
        fn_8021AEC4(arg1, 1, fn_8027B1D4);
        off = arg1 * 0x68;
        memset(arg0 + off + 0x30, 0, 0x20);
        (arg0 + off)[0x5C] = 1;
        (arg0 + off)[0x62] = 0;
    }
}
