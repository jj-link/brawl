#pragma force_active on
extern "C" {
int strlen(const char*);
void fn_80015F78(int*, int);
void fn_80016130(int*, int, int, char*, char*, char*);
void fn_800145A0(int, int*, int, int);
void __dl__FPv(void*);
}
static inline unsigned int findlast(int* s) {
    char* base;
    unsigned int offset = 0xFFFFFFFF;
    unsigned int n;
    if (!(((unsigned int)s[0]) >> 31)) {
        base = (char*)s + 1;
        n = *(unsigned char*)s & 0x7F;
    } else {
        base = (char*)s[2];
        n = s[1];
    }
    if (n != 0) {
        n -= 1;
        if (n < 0xFFFFFFFF)
            offset = n;
        char* p = base + offset;
        for (;;) {
            if (*p == '/')
                return p - base;
            if (p <= base)
                break;
            --p;
        }
    }
    return 0xFFFFFFFF;
}
extern "C" void fn_80014480(int arg0, char* arg1) {
    struct Locals {
        char flag;
        char pad[3];
        char type;
        char pad2[3];
        int s[3];
    } l;
    l.s[0] = 0;
    l.s[1] = 0;
    l.s[2] = 0;
    int len = strlen(arg1);
    fn_80015F78(l.s, len);
    l.flag = l.type;
    fn_80016130(l.s, 0, 0, arg1, arg1 + len, &l.flag);
    fn_800145A0(arg0, l.s, 0, findlast(l.s) + 1);
    if (((unsigned int)l.s[0]) >> 31)
        __dl__FPv((void*)l.s[2]);
}