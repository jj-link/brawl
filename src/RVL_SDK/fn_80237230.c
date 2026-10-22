#pragma force_active on
typedef unsigned short u16;

extern void fn_80230450(void);
extern void fn_80230454(void);
extern void fn_802324CC(int arg0, void *arg1);
extern void *fn_8022EE58(u16 size);
extern void fn_802324E0(void *arg);
extern void *memset(void *s, int c, unsigned long n);
extern int lbl_805A3A80;

void fn_80237230(signed char arg0, void *arg1) {
    void *p;

    fn_80230450();
    fn_802324CC(0x17, &lbl_805A3A80);
    fn_80230454();
    p = fn_8022EE58(0x34);
    if (p != 0) {
        memset(p, 0, 0x34);
        *(short *)p = 0x170C;
        *(void **)((char *)p + 0x30) = arg1;
        *(char *)((char *)p + 0x8) = arg0;
        fn_802324E0(p);
    }
}
