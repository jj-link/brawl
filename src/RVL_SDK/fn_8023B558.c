#pragma force_active on
extern char lbl_80529CF8[];
extern void memcpy(void *, const void *, int);

void fn_8023B558(unsigned char *arg0, int arg1, int arg2) {
    void (*fn)(void *);
    struct {
        short a;
        short b;
        char data[0x100];
    } msg;
    char *src = (char *)arg0;
    char *dst = msg.data;

    fn = *(void (**)(void *))(lbl_80529CF8 + 0x61C);
    *(unsigned char *)(lbl_80529CF8 + 0x650) = 0;
    *(void (**)(void *))(lbl_80529CF8 + 0x61C) = 0;
    if (fn != 0) {
        msg.a = (short)arg1;
        msg.b = (short)arg2;
        memcpy(dst, src, arg2);
        fn(&msg);
    }
}