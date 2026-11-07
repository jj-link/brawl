#pragma force_active on
int fn_80399A4C(void);
int fn_80397640(int);
void fn_80399D04(int, int, void *);
int fn_80397DE0(int, char *, ...);
extern char lbl_8059FD70[7];
extern char lbl_8059FD78[3];

int fn_8039EDE8(int *self, unsigned int flags, int p3, unsigned int p4, int *out) {
    char buf[0x20];
    int r;
    int ret = 0;

    if (flags & 1) {
        int t = fn_80399A4C();
        int len = fn_80397640(t);
        if (len <= 0) {
            ret = -12;
        } else if (len + 0x12 >= (int)p4) {
            ret = -11;
        } else {
            fn_80399D04(self[0], self[1], buf);
            r = fn_80397DE0(p3, lbl_8059FD70, 0x77, buf, t);
            if (r == 0) {
                ret = -1;
            } else {
                *out = r;
            }
        }
    } else if (flags & 2) {
        if ((unsigned int)(self[1] + 3) >= p4) {
            ret = -11;
        } else {
            r = fn_80397DE0(p3, lbl_8059FD78, self[0]);
            if (r == 0) {
                ret = -1;
            } else {
                *out = r;
            }
        }
    } else {
        ret = -3;
    }
    return ret;
}
