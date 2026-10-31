#pragma force_active on
extern int fn_802123A8(void *p, int flag);
extern int fn_80212588(int fd);
extern int fn_80213090(int fd, int cmd, int flag1, int flag2, void *data);
extern char lbl_80492710[];

struct IOVec {
    void *base;
    int len;
};

int fn_803A8AF4(int arg0) {
    int local __attribute__((aligned(32)));
    int val __attribute__((aligned(32)));
    struct IOVec iov[2];
    int fd;

    fd = fn_802123A8(lbl_80492710, 0);
    if (fd < 0) {
        return -1;
    }

    local = arg0;
    val = -1;
    iov[0].base = &val;
    iov[0].len = 0x20;
    iov[1].base = &local;
    iov[1].len = 0x20;

    fn_80213090(fd, 3, 1, 1, &iov[0]);
    fn_80212588(fd);
    return val;
}
