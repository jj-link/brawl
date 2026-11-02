#pragma force_active on
extern int fn_802123A8(void *p, int flag);
extern int fn_80212588(int fd);
extern int fn_80213090(int fd, int cmd, int flag1, int flag2, void *data);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *memset(void *dst, int c, unsigned long n);
extern char lbl_80492710[];

struct IOVec {
    void *base;
    int len;
};

int fn_803A8E70(int arg0, char *buf, unsigned int len) {
    char tmp[32] __attribute__((aligned(32)));
    int fd;
    int r27;
    unsigned int head;
    int total;
    unsigned int n;
    int status_h[8] __attribute__((aligned(32)));
    int hdr_h[8] __attribute__((aligned(32)));
    struct IOVec iov_h[4] __attribute__((aligned(32)));
    int status_m[8] __attribute__((aligned(32)));
    int hdr_m[8] __attribute__((aligned(32)));
    struct IOVec iov_m[4] __attribute__((aligned(32)));
    int status_t[8] __attribute__((aligned(32)));
    int hdr_t[8] __attribute__((aligned(32)));
    struct IOVec iov_t[4] __attribute__((aligned(32)));

    fd = fn_802123A8(lbl_80492710, 0);
    r27 = -1;
    if (fd < 0) {
        return -1;
    }
    head = ((unsigned int)buf & 31) ? 32 - ((unsigned int)buf & 31) : 0;
    total = 0;
    memset(tmp, 0, 32);
    if (head != 0) {
        if (head > len) {
            head = len;
        }
        memcpy(tmp, buf, head);
        status_h[0] = -1;
        hdr_h[0] = arg0;
        iov_h[0].base = &status_h[0];
        iov_h[0].len = 0x20;
        iov_h[1].base = &hdr_h[0];
        iov_h[1].len = 0x20;
        iov_h[2].base = tmp;
        iov_h[2].len = head;
        fn_80213090(fd, 5, 1, 2, iov_h);
        r27 = status_h[0];
        if (r27 > 0) {
            total = r27;
            if ((unsigned int)r27 < head) {
                fn_80212588(fd);
                return r27;
            }
            buf += r27;
            len -= r27;
        } else {
            fn_80212588(fd);
            return r27;
        }
    }

    if (len != 0) {
        n = len & ~31u;
        if (n != 0) {
            hdr_m[0] = arg0;
            status_m[0] = -1;
            iov_m[0].base = &status_m[0];
            iov_m[0].len = 0x20;
            iov_m[1].base = &hdr_m[0];
            iov_m[1].len = 0x20;
            iov_m[2].base = buf;
            iov_m[2].len = n;
            fn_80213090(fd, 5, 1, 2, iov_m);
            r27 = status_m[0];
            if (r27 > 0) {
                total += r27;
                if ((unsigned int)r27 < n) {
                    fn_80212588(fd);
                    return total;
                }
                buf += r27;
                len -= r27;
            } else {
                fn_80212588(fd);
                if (total > 0) {
                    return total;
                }
                return r27;
            }
        }
    }

    if (len != 0) {
        n = len & 31;
        if (n != 0) {
            memset(tmp, 0, 32);
            memcpy(tmp, buf, n);
            status_t[0] = -1;
            hdr_t[0] = arg0;
            iov_t[0].base = &status_t[0];
            iov_t[0].len = 0x20;
            iov_t[1].base = &hdr_t[0];
            iov_t[1].len = 0x20;
            iov_t[2].base = tmp;
            iov_t[2].len = n;
            fn_80213090(fd, 5, 1, 2, iov_t);
            r27 = status_t[0];
            if (r27 > 0) {
                total += r27;
            } else {
                fn_80212588(fd);
                if (total > 0) {
                    return total;
                }
                return r27;
            }
        }
    }

    if (total > 0) {
        r27 = total;
    }
    fn_80212588(fd);
    return r27;
}
