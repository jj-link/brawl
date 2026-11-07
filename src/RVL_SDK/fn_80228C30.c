#pragma force_active on
extern char lbl_8047E240[];
extern int lbl_8059ED80;
extern void *fn_802137A4(int, int, int);
extern int fn_802137A8(int, void *);
extern int fn_802123A8(void *, int);
extern void fn_80228834(const char *, ...);
extern void fn_802288DC(const char *, ...);
extern void *memset(void *, int, unsigned int);
extern int snprintf(char *, unsigned int, const char *, ...);
int fn_80228C30(int arg0, int arg1, int arg2, int *arg3)
{
    const char *base = lbl_8047E240;
    int result;
    char *request = 0;
    int error;
    if (arg3 == 0) {
        result = -4;
    } else {
        request = fn_802137A4(lbl_8059ED80, 0x80, 0x20);
        if (request == 0)
            fn_802288DC(base + 0x154, lbl_8059ED80, 0x80, request);
        if (request == 0) {
            fn_802288DC(base + 0x178);
            result = -22;
        } else {
            memset(request, 0, 0x80);
            snprintf(request + 0x40, 0x40, base + 0x19c, arg0, arg1, arg2);
            fn_80228834(base + 0x1b0, request + 0x40);
            result = fn_802123A8(request + 0x40, 0);
            fn_80228834(base + 0x1c4, result);
            *arg3 = result;
        }
    }
    if (request != 0) {
        error = fn_802137A8(lbl_8059ED80, request);
        if (error < 0)
            fn_802288DC(base + 0x108, lbl_8059ED80, request, error);
    }
    return result;
}