#pragma force_active on
extern int fn_802123A8(void *p, int flag);
extern int fn_80212588(int fd);
extern int fn_80213090(int fd, int cmd, int flag1, int flag2, void *data);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *memset(void *dst, int c, unsigned long n);
extern char lbl_80492710[];

struct IOVec {
    void *base;
    unsigned int len;
};

int fn_803A8BA0(int arg0, char *buf, unsigned int len) {
    char tmp[32] __attribute__((aligned(32)));
    int fd;
    int status;
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
    status = -1;
    if (fd < 0) {
        return -1;
    }
    if (len > 0x8000) {
        len = 0x8000;
    }
    head = ((unsigned int)buf & 31) ? 32 - ((unsigned int)buf & 31) : 0;
    total = 0;
    memset(tmp, 0, 32);
    if (head != 0) {
        if (head > len) {
            head = len;
        }
        hdr_h[0] = arg0;
        status_h[0] = -1;
        iov_h[0].base = &status_h[0];
        iov_h[0].len = 0x20;
        iov_h[1].base = tmp;
        iov_h[1].len = head;
        iov_h[2].base = &hdr_h[0];
        iov_h[2].len = 0x20;
        fn_80213090(fd, 4, 2, 1, iov_h);
        status = status_h[0];
        if (status > 0) {
            total = status;
            memcpy(buf, tmp, status);
            if ((unsigned int)status < head) {
                fn_80212588(fd);
                return total;
            }
            buf += status;
            len -= status;
        } else {
            fn_80212588(fd);
            return status;
        }
    }

    if (len != 0) {
        n = len & ~31u;
        if (n != 0) {
            hdr_m[0] = arg0;
            status_m[0] = -1;
            iov_m[0].base = &status_m[0];
            iov_m[0].len = 0x20;
            iov_m[1].base = buf;
            iov_m[1].len = n;
            iov_m[2].base = &hdr_m[0];
            iov_m[2].len = 0x20;
            fn_80213090(fd, 4, 2, 1, iov_m);
            status = status_m[0];
            if (status > 0) {
                total += status;
                if ((unsigned int)status < n) {
                    fn_80212588(fd);
                    return total;
                }
                buf += status;
                len -= status;
            } else {
                fn_80212588(fd);
                if (total > 0) {
                    return total;
                }
                return status;
            }
        }
    }

    if (len != 0) {
        n = len & 31;
        if (n != 0) {
            memset(tmp, 0, 32);
            hdr_t[0] = arg0;
            status_t[0] = -1;
            iov_t[0].base = &status_t[0];
            iov_t[0].len = 0x20;
            iov_t[1].base = tmp;
            iov_t[1].len = n;
            iov_t[2].base = &hdr_t[0];
            iov_t[2].len = 0x20;
            fn_80213090(fd, 4, 2, 1, iov_t);
            status = status_t[0];
            if (status > 0) {
                total += status;
                memcpy(buf, tmp, status);
            } else {
                fn_80212588(fd);
                if (total > 0) {
                    return total;
                }
                return status;
            }
        }
    }

    if (total > 0) {
        status = total;
    }
    fn_80212588(fd);
    return status;
}