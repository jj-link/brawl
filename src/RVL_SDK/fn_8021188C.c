#pragma force_active on

extern int lbl_8059ECB8;
extern int fn_80213090(int, int, int, int, void *);

int fn_8021188C(int a0, int a1, int a2, int a3, int a4) {
    struct {
        int a;
        char pad[0x1C];
        int d;
        char rest[0xAC];
        struct {
            void *ptr;
            int len;
        } vec[5];
    } buf __attribute__((aligned(32)));
    void *vec = &buf.vec;
    void *data = &buf.a;

    if (lbl_8059ECB8 < 0) {
        return -0x3F9;
    }

    buf.a = a0;
    buf.vec[2].ptr = (void *)a2;
    buf.vec[4].ptr = (void *)a4;
    buf.d = a3;
    buf.vec[0].ptr = data;
    buf.vec[0].len = 4;
    buf.vec[1].ptr = (void *)a1;
    buf.vec[3].ptr = (void *)a1;
    buf.vec[1].len = 0x10;
    buf.vec[2].len = a3;
    buf.vec[4].len = a3;
    buf.vec[3].len = 0x10;

    return fn_80213090(lbl_8059ECB8, 0x2C, 3, 2, vec);
}
