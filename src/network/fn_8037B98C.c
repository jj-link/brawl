#pragma force_active on
extern int fn_8037B644(void *self, void *buf, int flag);
extern char lbl_8059FA40[3];
extern char lbl_8059FA44[3];

int fn_8037B98C(void *arg0, void *arg1, void *arg2) {
    if (fn_8037B644(arg0, arg1, 0) == 0) return 0;
    if (fn_8037B644(arg0, lbl_8059FA40, 2) == 0) return 0;
    if (fn_8037B644(arg0, arg2, 0) == 0) return 0;
    return fn_8037B644(arg0, lbl_8059FA44, 2) != 0;
}
