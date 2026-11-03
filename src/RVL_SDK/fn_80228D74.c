#pragma force_active on
typedef struct Request {
    int value;
    char pad[4];
    int value8;
    char pad2[0x28];
    int value34;
} Request;
extern char lbl_8047E240[];
extern int lbl_8059ED80;
extern void fn_80228834(const char *, ...);
extern void fn_802288DC(const char *, ...);
extern Request *fn_802137A4(int, int, int);
extern int fn_802137A8(int, void *);
extern int fn_802124C8(int, void *, void *);
extern void fn_80228A88(void);
extern void *memset(void *, int, unsigned int);
int fn_80228D74(int arg0, int arg1, int arg2)
{
    const char *base = lbl_8047E240;
    Request *request;
    int result;
    int error;
    fn_80228834(base + 0x214);
    request = fn_802137A4(lbl_8059ED80, 0x80, 0x20);
    if (request == 0)
        fn_802288DC(base + 0x154, lbl_8059ED80, 0x80, request);
    if (request == 0) {
        fn_802288DC(base + 0x240);
        result = -22;
    } else {
        memset(request, 0, 0x80);
        request->value = arg1;
        request->value8 = arg2;
        request->value34 = 0;
        result = fn_802124C8(arg0, (void *)fn_80228A88, request);
        fn_80228834(base + 0x224, result);
        if (result < 0 && request != 0) {
            error = fn_802137A8(lbl_8059ED80, request);
            if (error < 0)
                fn_802288DC(base + 0x108, lbl_8059ED80, request, error);
        }
    }
    return result;
}