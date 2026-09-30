typedef void (*handler_t)(int);

extern void exit(int status);
extern handler_t lbl_80599F28[8];

int fn_803FA1D0(int sig) {
    handler_t handler;

    if (sig < 1 || sig > 7) {
        return -1;
    }
    handler = lbl_80599F28[sig - 1];
    if (handler != (handler_t) 1) {
        lbl_80599F28[sig - 1] = 0;
    }
    if (handler == (handler_t) 1 || (handler == (handler_t) 0 && sig == 1)) {
        return 0;
    }
    if (handler == (handler_t) 0) {
        exit(0);
    }
    handler(sig);
    return 0;
}
