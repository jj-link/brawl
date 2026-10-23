#pragma force_active on

extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_80211688(int arg0, int arg1, void *arg2) {
    struct {
        int a;
        int b;
        char rest[0xC8];
        void *ptr;
        int eight;
        void *out;
        int thirty;
        char tail[0x18];
    } buf __attribute__((aligned(32)));
    void *vec = &buf.ptr;
    void *data = &buf.a;

    if (lbl_8059ECB8 < 0 || arg2 == (void *)0) {
        return -0x3F9;
    }
    if ((unsigned int)arg2 & 0x1F) {
        return -0x3F9;
    }

    buf.b = arg1;
    buf.a = arg0;
    buf.out = arg2;
    buf.ptr = data;
    buf.eight = 8;
    buf.thirty = 0x1E;
    return fn_80213090(lbl_8059ECB8, 0x1D, 1, 1, vec);
}
