#pragma force_active on
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern void *fn_803F602C(void *, const void *, unsigned long);
extern char lbl_8059F5B8[6], lbl_8059F5C0[7], lbl_8059F5C8[7];
extern char lbl_8059F5D0[5], lbl_8059F5D8[5], lbl_8059F5E0[4];
extern char lbl_8059F5E4[5], lbl_8059F5EC[3];

static inline signed char get_char(const char *buf, int i)
{
    return buf[i];
}

static inline void set_char(char *buf, int i, char c)
{
    buf[i] = c;
}

int fn_80363BDC(char *buf, int *len)
{
    int i = 0;
    int n;
    char *semi;
    unsigned int sp8;
    signed char c;
    int val;
    int j;

    while (i < *len) {
        if (get_char(buf, i) != '&') {
            i++;
            continue;
        }

        if (strncmp(buf + i, lbl_8059F5B8, 5) == 0) {
            buf[i++] = '&';
            n = 4;
        } else if (strncmp(buf + i, lbl_8059F5C0, 6) == 0) {
            buf[i++] = '"';
            n = 5;
        } else if (strncmp(buf + i, lbl_8059F5C8, 6) == 0) {
            buf[i++] = 0x27;
            n = 5;
        } else if (strncmp(buf + i, lbl_8059F5D0, 4) == 0) {
            buf[i++] = '<';
            n = 3;
        } else if (strncmp(buf + i, lbl_8059F5D8, 4) == 0) {
            buf[i++] = '>';
            n = 3;
        } else if (strncmp(buf + i, lbl_8059F5E0, 3) == 0) {
            int flag;
            unsigned int mask;

            sp8 = 0;
            flag = 0;
            mask = 0xff000000;
            semi = strchr(buf + (i + 3), ';');
            if (semi == 0)
                return 0;
            if (semi - (buf + (i + 3)) > 8)
                return 0;

            sscanf(buf + (i + 3), lbl_8059F5E4, &sp8);
            for (j = 0; j < 4; j++) {
                c = (signed char)((sp8 & mask) >> ((3 - j) * 8));
                if (flag != 0 || c != 0) {
                    buf[i++] = c;
                    flag = 1;
                }
                mask >>= 8;
            }
            n = (semi - (buf + i)) + 1;
        } else if (strncmp(buf + i, lbl_8059F5EC, 2) == 0) {
            int flag;
            unsigned int mask;

            flag = 0;
            mask = 0xff000000;
            semi = strchr(buf + (i + 2), ';');
            if (semi == 0)
                return 0;

            val = atoi(buf + (i + 2));
            for (j = 0; j < 4; j++) {
                c = (signed char)((val & mask) >> ((3 - j) * 8));
                if (flag != 0 || c != 0) {
                    buf[i++] = c;
                    flag = 1;
                }
                mask >>= 8;
            }
            n = (semi - (buf + i)) + 1;
        } else {
            return 0;
        }

        fn_803F602C(buf + i, buf + (i + n), *len - (i + n));
        memset(buf + (*len - n), 0x20, n);
        *len -= n;
    }

    return 1;
}
