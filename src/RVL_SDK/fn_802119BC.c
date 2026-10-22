#pragma force_active on
extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_802119BC(int arg0, int arg1) {
    struct {
        int a;
        int b;
        char rest[0xC8];
        void *ptr;
        int eight;
        char tail[0x20];
    } buf __attribute__((aligned(32)));
    void *vec = &buf.ptr;
    void *data = &buf.a;

    if (lbl_8059ECB8 < 0) {
        return -0x3F9;
    }

    buf.b = arg1;
    buf.a = arg0;
    buf.ptr = data;
    buf.eight = 8;
    return fn_80213090(lbl_8059ECB8, 0x17, 1, 0, vec);
}
