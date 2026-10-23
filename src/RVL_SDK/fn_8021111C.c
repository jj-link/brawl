#pragma force_active on

extern int fn_8021316C(int, int, int, int, void *);
extern int lbl_8059ECB8;

int fn_8021111C(int arg0, int arg1, int arg2) {
    struct {
        int a;
        int b;
        char pad[0xC8];
        void *p;
        int x;
        int y;
        int z;
        char tail[0x20];
    } f __attribute__((aligned(32)));
    void *vec = &f.p;
    void *data = &f.a;
    int ret;

    if (lbl_8059ECB8 < 0) {
        return -0x3F9;
    }
    if (arg2 & 0x1F) {
        return -0x3F9;
    }

    f.b = arg1;
    f.a = arg0;
    f.y = arg2;
    f.p = data;
    f.x = 8;
    f.z = 0xD8;
    ret = fn_8021316C(lbl_8059ECB8, 8, 2, 0, vec);
    lbl_8059ECB8 = -1;
    return ret;
}
