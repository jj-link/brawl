// MSL wide-character conversion and stream orientation dispatch.
typedef unsigned char u8;

extern char lbl_804942B8[];

int fn_803F5EF4(int a, int b, int c) {
    void* table = *(void**)(lbl_804942B8 + 0x38);
    return (*(int (**)(int, int, int))((char*)table + 0x20))(a, b, c);
}

int fn_803F5F0C(unsigned short* pwc, const char* s, int n) {
    if (s == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (pwc != 0) {
        *pwc = (u8)*s;
    }
    if (*(signed char*)s == 0) {
        return 0;
    }
    return 1;
}

int fn_803F5F58(char* s, char c) {
    if (s == 0) {
        return 0;
    }
    *s = c;
    return 1;
}
