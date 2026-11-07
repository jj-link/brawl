#pragma force_active on

extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_802117B8(int arg0, int arg1, void *arg2, int *arg3) {
    struct {
        int a;
        int b;
        char pad[0x18];
        int out;
        char pad2[0xAC];
        void *p;
        int x;
        void *y;
        int z;
        void *q;
        int w;
        char tail[0x18];
    } f __attribute__((aligned(32)));
    void *vec = &f.p;
    void *data = &f.a;
    void *outp = &f.out;
    int ret;

    if (lbl_8059ECB8 < 0) {
        return -0x3F9;
    }
    if ((unsigned int)arg2 & 0x1F) {
        return -0x3F9;
    }

    f.b = arg1;
    f.a = arg0;
    f.p = data;
    f.x = 8;
    if (arg2 == (void *)0) {
        f.y = (void *)0;
        f.z = 0;
    } else {
        f.y = arg2;
        f.z = *arg3 * 8;
        f.out = *arg3;
    }
    f.q = outp;
    f.w = 4;
    ret = fn_80213090(lbl_8059ECB8, 0x16, 1, 2, vec);
    *arg3 = f.out;
    return ret;
}
