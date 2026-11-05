#pragma force_active on
typedef struct Request {
    char pad[0x100];
    void (*callback)(void);
    void *context;
    int type;
    unsigned int buffer;
} Request;
extern int lbl_805A0C1C;
extern Request *fn_802137A4(int, int, int);
extern void fn_80213C80(void);
extern int fn_80212C08(int, int, void *, int, void *, int, void (*)(void), void *);

int fn_80215008(int arg0, unsigned int arg1, void (*arg2)(void), void *arg3) {
    Request *request;
    if (arg1 == 0 || (arg1 & 0x1f)) {
        return -0x65;
    }
    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -0x76;
    }
    request->callback = arg2;
    request->context = arg3;
    request->type = 5;
    request->buffer = arg1;
    return fn_80212C08(arg0, 0xb, 0, 0, request, 8, fn_80213C80, request);
}
