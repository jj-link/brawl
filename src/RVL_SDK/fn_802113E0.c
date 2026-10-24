#pragma force_active on

extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_802113E0(void *arg0, void *arg1) {
    struct {
        int a;
        int b;
        char rest[0xC8];
        void *ptr;
        int param;
        void *out;
        int thirty;
        char tail[0x20];
    } buf __attribute__((aligned(32)));
    void *vec = &buf.ptr;

    if (lbl_8059ECB8 < 0 || arg1 == (void *)0) {
        return -0x3F9;
    }
    if (((unsigned int)arg0 & 0x1F) || ((unsigned int)arg1 & 0x1F)) {
        return -0x3F9;
    }

    buf.ptr = arg0;
    if (arg0 == (void *)0) {
        buf.param = 0;
    } else {
        buf.param = 0x2A4;
    }
    buf.out = arg1;
    buf.thirty = 0xD8;
    return fn_80213090(lbl_8059ECB8, 0x1B, 1, 1, vec);
}
