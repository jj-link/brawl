#pragma force_active on
extern void fn_8037B644(void *self, char *buf, int flag);
extern int sprintf(char *buf, const char *fmt, ...);
extern const char lbl_8059FA48[3];

void fn_8037BB6C(void *arg0, int arg1) {
    char sp8[16];

    sprintf(sp8, lbl_8059FA48, arg1);
    fn_8037B644(arg0, sp8, 0);
}
