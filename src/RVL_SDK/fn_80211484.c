#pragma force_active on
extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_80211484(void *arg0, int *arg1) {
    struct {
        int out;
        char pad[0xCC];
        void *p;
        int len;
        void *q;
        int qlen;
        char tail[0x10];
    } buf __attribute__((aligned(32)));
    int temp;
    int fd;
    void *vec = &buf.p;
    void *out = &buf.out;
    int result;

    fd = lbl_8059ECB8;
    if (fd < 0 || arg1 == (void *)0) return -0x3F9;
    if ((unsigned int)arg0 & 0x1F) return -0x3F9;
    if (arg0 == (void *)0) {
        buf.p = out;
        buf.len = 4;
        result = fn_80213090(fd, 0x39, 0, 1, vec);
        if (result == 0) *arg1 = buf.out;
        return result;
    }
    temp = *arg1;
    if (temp == 0) return -0x3F9;
    buf.q = arg0;
    buf.out = temp;
    buf.p = out;
    buf.len = 4;
    buf.qlen = *arg1;
    return fn_80213090(fd, 0x3A, 1, 1, vec);
}