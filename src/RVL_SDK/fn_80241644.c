#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_80481BB0[];
extern char lbl_80481BF4[];
void fn_80231A74(int, void*, int, int, int, int, int, int);
void fn_802319FC(int, void*, int);
char* fn_8023A0F0(void);
char* fn_80239F18(unsigned char*);
void* memcpy(void*, void*, unsigned long);

void fn_80241644(unsigned char* a, void* b, unsigned char c) {
    char* p = fn_8023A0F0();
    if (p == 0) {
        p = fn_80239F18(a);
        if (p == 0) return;
    }
    if (*(unsigned char*)(lbl_80529CF8 + 0x27C0) >= 4)
        fn_80231A74(0xD0003, lbl_80481BB0, a[0], a[1], a[2], a[3], a[4], a[5]);
    if (*(unsigned char*)(lbl_80529CF8 + 0x27C0) >= 4)
        fn_802319FC(0xD0003, lbl_80481BF4, c);
    if (*(unsigned char*)(lbl_80529CF8 + 0x636) < 1)
        *(unsigned char*)(p + 0x83) = 0xFF;
    else
        *(unsigned char*)(p + 0x83) = c;
    *(unsigned char*)(p + 0x76) |= 0x10;
    memcpy(p + 0x25, b, 0x10);
    if (!(*(unsigned char*)(p + 0x76) & 8) || ((*(unsigned char*)(p + 0x81) & 0x40) && *(unsigned char*)(p + 0x85) == 0)) {
        *(unsigned char*)(p + 0x82) = 1;
        return;
    }
    {
        void (*f)(unsigned char*, char*, char*, void*, int) = *(void**)(lbl_80529CF8 + 0x1914);
        char* q;
        int i;
        if (f) f(a, p + 0x22, p + 0x35, b, *(unsigned char*)(p + 0x83));
        q = lbl_80529CF8;
        for (i = 0; i < 2; i++) {
            f = *(void**)(q + 0x1924);
            if (f) f(a, p + 0x22, p + 0x35, b, *(unsigned char*)(p + 0x83));
            q += 4;
        }
    }
}
