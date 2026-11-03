#pragma force_active on

extern void fn_80284FEC(void *, void *);
extern int fn_8028526C(int, void *, int);

int fn_802855F0(int arg0, void *arg1, int arg2) {
    char buffer[0x30] __attribute__((aligned(16)));
    fn_80284FEC(buffer, arg1);
    return fn_8028526C(arg0, buffer, arg2);
}
