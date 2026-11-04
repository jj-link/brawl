#pragma force_active on

extern int fn_802123A8(void *p, int flag);
extern int fn_80212588(int fd);
extern int fn_80213090(int fd, int cmd, int flag1, int flag2, void *data);
extern char lbl_80492710[];

struct IOVec {
    void *base;
    int len;
};

int fn_803A9558(int arg0, int arg1) {
    int val __attribute__((aligned(32)));
    int local0 __attribute__((aligned(32)));
    int local1 __attribute__((aligned(32)));
    struct IOVec iov[3];
    int fd;

    fd = fn_802123A8(lbl_80492710, 0);
    if (fd < 0) {
        return -1;
    }

    local0 = arg0;
    val = -1;
    local1 = arg1;
    iov[0].base = &val;
    iov[0].len = 0x20;
    iov[1].base = &local0;
    iov[1].len = 0x20;
    iov[2].base = &local1;
    iov[2].len = 0x20;

    fn_80213090(fd, 14, 1, 2, &iov[0]);
    fn_80212588(fd);
    return val;
}
