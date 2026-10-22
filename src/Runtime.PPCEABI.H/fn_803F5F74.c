#pragma force_active on
typedef int (*ConvFn)(char*, unsigned short, void*);

extern char lbl_804942B8[];
extern char* strncpy(char*, const char*, unsigned long);

unsigned long wcstombs(char* arg0, unsigned short* arg1, unsigned long arg2) {
    char buf[16];
    int n;
    unsigned long i;
    unsigned short* p;
    unsigned short c;

    i = 0;
    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    p = arg1;
    goto check;

body:
    c = *p;
    if (c == 0) {
        arg0[i] = 0;
        goto done;
    }
    p++;
    n = (*(ConvFn*)(*(char**)(lbl_804942B8 + 0x38) + 0x24))(buf, c, *(void**)(lbl_804942B8 + 0x38));
    if ((unsigned long)(i + n) > arg2) {
        goto done;
    }
    strncpy(arg0 + i, buf, n);
    i += n;

check:
    if (i <= arg2) {
        goto body;
    }
done:
    return i;
}
