#pragma force_active on
extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);
int fn_802111B0(int arg0, int arg1, void *arg2, int *arg3) {
    struct {
        int a; int b; char pad1[0x18]; int out; char pad2[0xAC];
        void *p; int len; void *q; int qlen; void *r; int rlen; char tail[0x18];
    } buf __attribute__((aligned(32)));
    int temp;
    int fd;
    void *vec = &buf.p;
    void *data = &buf.a;
    void *out = &buf.out;
    int result;
    fd = lbl_8059ECB8;
    if (fd < 0 || arg3 == (void *)0) return -0x3F9;
    if ((unsigned int)arg2 & 0x1F) return -0x3F9;
    buf.b = arg1;
    buf.a = arg0;
    if (arg2 == (void *)0) {
        buf.p = data;
        buf.len = 8;
        buf.q = out;
        buf.qlen = 4;
        result = fn_80213090(fd, 0x10, 1, 1, vec);
        if (result == 0) *arg3 = buf.out;
        return result;
    }
    temp = *arg3;
    if (temp == 0) return -0x3F9;
    buf.r = arg2;
    buf.out = temp;
    buf.p = data;
    buf.len = 8;
    buf.q = out;
    buf.qlen = 4;
    buf.rlen = *arg3 * 4;
    return fn_80213090(fd, 0x11, 2, 1, vec);
}