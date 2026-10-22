#pragma force_active on
extern int sprintf(char *buf, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern char lbl_8059F9AC;

int fn_8037929C(char *arg0, int arg1) {
    char buf[32];
    int len;

    sprintf(buf, &lbl_8059F9AC, arg1);
    len = strlen(buf) + 1;
    if (len > 0x578 - *(int *)(arg0 + 0x578)) {
        len = 0x578 - *(int *)(arg0 + 0x578);
    }
    if (len <= 0) {
        return 0;
    }
    memcpy(arg0 + *(int *)(arg0 + 0x578), buf, len);
    *(int *)(arg0 + 0x578) += len;
    arg0[*(int *)(arg0 + 0x578) - 1] = 0;
    return 1;
}
